#include "func_return.hpp"

func_return::func_return(int line, int col, expression *exp)
{
    Line = line;
    Col = col;
    Exp = exp;
}

void func_return::ejecutar(environment *env, ast *tree)
{
    if(Exp != nullptr)
    {
        symbol sym = Exp->ejecutar(env, tree);
        tree->ListReturn.push_back(sym);
    }
}
