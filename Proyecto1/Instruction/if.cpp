#include "if.hpp"

if::if(int line, int col, expression *valor, expression *valor1)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
    this->Valor1 = valor1;
}

void if::ejecutar(environment *env, ast *tree)
{
    symbol sym = this->Valor->ejecutar(env, tree);
    symbol sym1 = this->Valor1->ejecutar(env, tree);
    if(sym.Tipo == STRING)
    {
        tree->ConsoleOut += sym.StrVal+"\n";
    }
    else if(sym.Tipo == INTEGER)
    {
        tree->ConsoleOut += sym.StrVal+"\n";
    }
    else if(sym.Tipo == FLOAT)
    {
        tree->ConsoleOut += sym.StrVal+"\n";
    }
    else if(sym.Tipo == BOOL)
    {
        tree->ConsoleOut += sym.StrVal+"\n";
    }
    else
    {
        tree->ConsoleOut += std::to_string(sym.NumVal)+"\n";
    }

}
