#include "func_pushback.hpp"

func_pushback::func_pushback(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

void func_pushback::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);
    int new_size = vec_size+1;

    std::string nuevo_n = gen->newTemp();
    gen->AddAssign(nuevo_n,std::to_string(new_size));

    std::string temp = gen->newTempChar(new_size);
    std::string nuevo_vector = gen->newTemp();
    gen->AddAssign("int* " + nuevo_vector, "(int*) " + temp);

    std::string nuevo_elem = gen->newTemp();
    val = Valor->ejecutar(env,tree,gen);
    gen->AddAssign(nuevo_elem,val.Value);

    std::string i = gen->newTemp();
    gen->AddAssign(i,"0");

    std::string label1 = gen->newLabel();
    std::string label2 = gen->newLabel();
    gen->AddLabel(label1);
    gen->AddIf(i,std::to_string(vec_size),">=",label2);
    gen->AddAssign(nuevo_vector + "[(int) " + i + "]", vec_val + "[(int) " + i + "]");
    gen->AddExpression(i,i,"1","+");
    gen->AddGoto(label1);

    gen->AddLabel(label2);
    gen->AddAssign(nuevo_vector + "["+ std::to_string(vec_size)+"]",nuevo_elem);
    gen->AddAssign(vec_val,nuevo_vector);


    symbol newVar = env->AssignVariable(Line, Col, Id, VECTOR, env, tree);
    symbol Var = env->AssignVector(Line, Col, Id, VECTOR, env, tree);
    tree->SizeVector.at(index) = new_size;
    
    // Crear el nuevo elemento que se agregará al final
    symbol sym (0, 0, Id, VECTOR, 0);
    std::pair<std::string, symbol> nuevo_elemento(nuevo_vector, sym);

    // Obtener la última clave existente en el mapa
    std::string ultima_clave = env->TablaVector.rbegin()->first;

    // Agregar 1 a la última letra de la última clave para obtener una clave mayor
    char ultima_letra = ultima_clave.back();
    ultima_letra++;
    std::string nueva_clave = ultima_clave + ultima_letra;

    // Agregar el nuevo elemento al mapa con la nueva clave
    env->TablaVector.insert(std::make_pair(nueva_clave, sym));

    // Eliminar el primer elemento del string
    std::string temp_str = tree->SaveVector.at(index);
    temp_str.pop_back();

    tree->StackVector.push_back(nuevo_vector);
    tree->SizeVector.push_back(new_size);

    // Agregar un nuevo elemento al inicio del string
    std::string new_element = "," + val.Value + "]";
    temp_str.insert(temp_str.end(), new_element.begin(), new_element.end());
    tree->SaveVector.at(index) = temp_str;
    std::string data = tree->SaveVector.at(index);
    tree->changeSymbol(Id,data);   
}

