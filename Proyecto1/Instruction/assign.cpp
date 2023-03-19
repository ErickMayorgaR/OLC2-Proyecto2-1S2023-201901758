#include "assign.hpp"

assign::assign(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}


void assign::ejecutar(environment *env, ast *tree)
{
    symbol sym = Valor->ejecutar(env, tree);
    symbol sym2 = env->GetVariable(Line, Col, Id, env, tree);
    if(sym2.Tipo == sym.Tipo)
    {
        env->AssignVariable(sym, Id, env, tree);
        if(sym.Tipo == INTEGER)
        {
            dataAfter = std::to_string(*static_cast<int*>(sym.Value));
        }
        else if(sym.Tipo == STRING)
        {
            dataAfter = *static_cast<std::string*>(sym.Value);
        }
        else if(sym.Tipo == FLOAT)
        {
            dataAfter = std::to_string(*static_cast<float*>(sym.Value));
        }
        else
        {
            if(*static_cast<bool*>(sym.Value)){
                dataAfter = "true";
            }
            else
            {
                dataAfter = "false";
            }
        }
        
        std::string msgid = Id;
        tree->changeSymbol(msgid,dataAfter);
    }
    else
    {
        //se reporta un error
        std::string msg = "invalid type for assign";
        tree->addError(msg,Line,Col);
    }
}
