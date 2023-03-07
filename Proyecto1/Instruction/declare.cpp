#include "declare.hpp"
#include <stdio.h>

declare::declare(int line, int col,TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}


void declare::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
    if(Tipo == sym.Tipo)
    {
        env->SaveVariable(sym, Id, tree);
    }
    else
    {
        //se reporta un error
        tree->ErrorOut += "Error: el tipo es incorrecto";
    }
}
