#include "func_expression.hpp"

func_expression::func_expression(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;
}


void func_expression::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
}
