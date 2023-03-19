#include "declare_struct.hpp"

declare_struct::declare_struct(int line, int col, map_struct_dec *array, std::string id)
{
    Line = line;
    Col = col;
    Array = array;
    Id = id;
}

void declare_struct::ejecutar(environment *env, ast *tree)
{

    env->SaveStruct(Line, Col, Array->ListDec,Id, tree);
}
