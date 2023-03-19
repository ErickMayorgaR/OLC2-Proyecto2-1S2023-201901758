#include "declare.hpp"

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
        if(Tipo == INTEGER)
        {
            msgtipo ="int";
            msgdata = std::to_string(*static_cast<int*>(sym.Value));
        }
        else if(Tipo == STRING)
        {
            msgtipo ="string";
            msgdata = *static_cast<std::string*>(sym.Value);
        }
        else if(Tipo == FLOAT)
        {
            msgtipo ="float";
            msgdata = std::to_string(*static_cast<float*>(sym.Value));
        }
        else
        {
            msgtipo ="bool";
            bool value = *static_cast<bool*>(sym.Value);
            msgdata = value ? "true" : "false";

        }
        tree->addSymbol(Id,"variable",msgtipo,msgdata,Line,Col);

    }
    else
    {
        //se reporta un error
        std::string msg = "invalid type for id";
        tree->addError(msg,Line,Col);
    }
}
