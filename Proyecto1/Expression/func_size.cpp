#include "func_size.hpp"

func_size::func_size(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

value func_size::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);

    std::string sizeVec = std::to_string(vec_size);
    val = value(sizeVec,false,INTEGER);
    return val;
}


