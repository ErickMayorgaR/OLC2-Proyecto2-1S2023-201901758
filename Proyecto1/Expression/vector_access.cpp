#include "vector_access.hpp"

vector_access::vector_access(int line, int col, expression *array, expression *index)
{
    Line = line;
    Col = col;
    Array = array;
    Index = index;
}

value vector_access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    value Id = Array->ejecutar(env,tree,gen); //Id.Value -> Id del vector (temp donde esta guardado)
    value val_index = Index->ejecutar(env,tree,gen);
    
    std::string temp = gen->newTemp();
    gen->AddAssign(temp,Id.Value + "[(int) " + val_index.Value + "]");

    if(!tree->InsideAssign){
        val = value(temp, true, INTEGER);
    } else{
        val = value(temp, true, VECTOR);
    }

    tree->IndexAccess = tree->Index;
    return val;
}
