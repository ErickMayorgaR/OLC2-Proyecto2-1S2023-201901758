#include "declaration.hpp"

declaration::declaration(int line, int col, TipoDato tipo, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Valor = valor;
}
void declaration::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    symbol newVar;

    val = Valor->ejecutar(env, tree, gen);
    if(Tipo == val.Tipo){
        if(env->Inside_For){
            if (env->Tabla.find(Id) != env->Tabla.end())
            {
                env->Tabla.erase(Id);
                for (auto it = tree->SymbolTable.begin(); it != tree->SymbolTable.end(); ++it) {
                    if (it->find(Id) != std::string::npos) {
                        tree->SymbolTable.erase(it);
                        break;
                    }
                }
            }
        }
        gen->AddComment("agregando declaración de variable");
        newVar = env->SaveVariable(Line, Col, Id, Tipo, tree);
        if(val.Tipo == BOOL)
        {
            //si no es temporal (valor booleano)
            std::string newLabel = gen->newLabel();
            //add true labels
            for(int i=0; i < val.TrueLabel.size(); i++)
            {
                gen->AddLabel(val.TrueLabel[i]);
            }
            gen->AddSetStack(std::to_string(newVar.Value),"1");
            gen->AddGoto(newLabel);
            //add false labels
            for(int i=0; i < val.FalseLabel.size(); i++)
            {
                gen->AddLabel(val.FalseLabel[i]);
            }
            gen->AddSetStack(std::to_string(newVar.Value),"0");
            gen->AddGoto(newLabel);
            gen->AddLabel(newLabel);
        }
        else
        {
            //si es temporal (num, string, etc)
            gen->AddSetStack(std::to_string(newVar.Value), val.Value);
        }
        gen->AddEnter();

        if(Tipo == INTEGER)
        {
            msgtipo ="int";
            msgdata = val.Value;
        }
        else if(Tipo == STRING)
        {
            msgtipo ="string";
            msgdata = val.Value;
        }
        else if(Tipo == FLOAT)
        {
            msgtipo ="float";
            msgdata = val.Value;
        }
        else
        {
            msgtipo ="bool";
            msgdata = val.Value;

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
