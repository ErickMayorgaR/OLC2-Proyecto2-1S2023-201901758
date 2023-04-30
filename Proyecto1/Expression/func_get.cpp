#include "func_get.hpp"

func_get::func_get(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

value func_get::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);

    value val_index = Valor->ejecutar(env,tree,gen);
    
    std::string temp = gen->newTemp();
    gen->AddAssign(temp,vec_val + "[(int) " + val_index.Value + "]");

    if(!tree->InsideAssign){
        val = value(temp, true, INTEGER);
    } else{
        val = value(temp, true, VECTOR);
    }

    tree->IndexAccess = tree->Index;
    return val;
}

