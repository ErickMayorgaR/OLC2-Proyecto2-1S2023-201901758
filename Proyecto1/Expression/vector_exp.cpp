#include "vector_exp.hpp"

vector_exp::vector_exp(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

value vector_exp::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    int num = ExpList->ListExp.size();
    tree->VectorSize = num;

    std::string vector_mem = gen->newTempChar(num);

    std::string vector_str = gen->newTemp();
    gen->AddAssign("int* " + vector_str, "(int*) " + vector_mem);

    tree->Vector = "[";
    for(int i=0; i < ExpList->ListExp.size(); ++i){
        std::string Index = std::to_string(i);
        value valor = ExpList->ListExp[i]->ejecutar(env, tree, gen);
        gen->AddAssign(vector_str + "[" + Index + "]", valor.Value);
        tree->Vector += (valor.Value + ",");
    }

    tree->Vector.pop_back();
    tree->Vector += "]";
    value val(vector_str, true, VECTOR);
    return val;
}
