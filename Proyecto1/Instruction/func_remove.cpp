#include "func_remove.hpp"

func_remove::func_remove(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

void func_remove::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    tree->InsideRemove = true;
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);
    int new_size = vec_size-1;

    std::string remove_elem = gen->newTemp();
    std::string label2 = gen->newLabel();
    val = Valor->ejecutar(env,tree,gen);
    std::string val_index = tree->Index;
    gen->AddAssign(remove_elem,val.Value);
    gen->AddIf(remove_elem,std::to_string(vec_size),">=",label2);

    std::string temp = gen->newTempChar(new_size);
    std::string nuevo_vector = gen->newTemp();
    gen->AddAssign("int* " + nuevo_vector, "(int*) " + temp);

    std::string i = gen->newTemp();
    gen->AddAssign(i,"0");
    std::string j = gen->newTemp();
    gen->AddAssign(j,"0");

    std::string label1 = gen->newLabel();
    std::string label3 = gen->newLabel();
    std::string label4 = gen->newLabel();
    
    gen->AddLabel(label1);
    gen->AddIf(i,std::to_string(vec_size),">=",label2);
    gen->AddIf(i,remove_elem,"!=",label3);
    gen->AddAssign(j, "1");
    gen->AddGoto(label4);

    gen->AddLabel(label3);
    std::string nuevo_index = gen->newTemp();
    gen->AddExpression(nuevo_index,i,j,"-");
    gen->AddAssign(nuevo_vector + "[(int) " + nuevo_index + "]", vec_val + "[(int) " + i + "]");

    gen->AddLabel(label4);
    gen->AddExpression(i,i,"1","+");
    gen->AddGoto(label1);

    gen->AddLabel(label2);
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

    tree->StackVector.push_back(nuevo_vector);
    tree->SizeVector.push_back(new_size);


// Eliminar el primer elemento del string
    std::string temp_str = tree->SaveVector.at(index);
    // Definir la posición del elemento a eliminar
    int pos = std::stoi(val_index);

    // Obtener la posición de la primera coma a eliminar
    int start_pos;
    if (pos == 0) {
        start_pos = temp_str.find('[') + 1;
    } else {
        int num_comas = 0;
        int while_i = 0;
        while(num_comas < pos){
            if (temp_str[while_i] == ',') {
                num_comas++;
            }
            while_i++;
        }
        start_pos = while_i;
    }


    // Obtener la posición de la segunda coma a eliminar
    int num_comas = 0;
    int while_i_end = start_pos;
        while(num_comas < 1){
            if (temp_str[while_i_end] == ',') {
                num_comas++;
            }
            while_i_end++;
        }
    int end_pos = while_i_end-1;

    // Si no se encontró la segunda coma, significa que estamos eliminando el último elemento
    if (end_pos == std::string::npos) {
        end_pos = temp_str.find(']', start_pos + 1);
    }

    // Eliminar el substring que se encuentra entre las dos posiciones obtenidas
    temp_str.erase(start_pos, end_pos - start_pos + 1);
    tree->SaveVector.at(index) = temp_str;
    std::string data = tree->SaveVector.at(index);
    tree->changeSymbol(Id,data);   
    tree->InsideRemove = true;
}

