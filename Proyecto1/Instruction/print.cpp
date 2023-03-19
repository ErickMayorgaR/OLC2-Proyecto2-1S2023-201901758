#include "print.hpp"

print::print(int line, int col, list_expression* valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree)
{
    for(int i = 0; i < Valor->ListExp.size();i++){
        symbol sym = Valor->ListExp[i]->ejecutar(env, tree);
        switch (sym.Tipo) {
        case STRING:
            tree->ConsoleOut += *static_cast<std::string*>(sym.Value);
            break;
        case INTEGER:
            tree->ConsoleOut += std::to_string(*static_cast<int*>(sym.Value));
            break;
        case FLOAT:
            tree->ConsoleOut += std::to_string(*static_cast<float*>(sym.Value));
            break;
        case BOOL:
            tree->ConsoleOut += *static_cast<bool*>(sym.Value) ? "true" : "false";
            break;
        case NULO:
            tree->ConsoleOut += "NULL";
            break;
        case VECTOR:
            QVector<symbol> *Vec = (QVector<symbol>*)sym.Value;
            QVector<symbol> result = *Vec;
            tree->ConsoleOut += VectorToString(result);
            break;
        
        }
    }
    tree->ConsoleOut += "\n";
}

std::string print::VectorToString(QVector<symbol> Vector)
{
    std::string strBuffer = "[";
    int contIndex = 0;
    for(int i=0; i < Vector.size(); ++i){
        contIndex++;
        if(Vector[i].Tipo == VECTOR)
        {
            if(contIndex < Vector.size())
            {
                strBuffer += VectorToString(*static_cast<QVector<symbol>*>(Vector[i].Value)) + ",";
            }
            else
            {
                strBuffer += VectorToString(*static_cast<QVector<symbol>*>(Vector[i].Value));
            }

        }
        else
        {
            if(Vector[i].Tipo == STRING)
            {
                if(contIndex < Vector.size())
                {
                    strBuffer += *static_cast<std::string*>(Vector[i].Value) + ",";
                }
                else
                {
                    strBuffer += *static_cast<std::string*>(Vector[i].Value);
                }

            }
            else if(Vector[i].Tipo == INTEGER)
            {
                if(contIndex < Vector.size())
                {
                    strBuffer += std::to_string(*static_cast<int*>(Vector[i].Value)) + ",";
                }
                else
                {
                    strBuffer += std::to_string(*static_cast<int*>(Vector[i].Value));
                }

            }
            else if(Vector[i].Tipo == FLOAT)
            {
                if(contIndex < Vector.size())
                {
                    strBuffer += std::to_string(*static_cast<float*>(Vector[i].Value)) + ",";
                }
                else
                {
                    strBuffer += std::to_string(*static_cast<float*>(Vector[i].Value));
                }

            }
        }
    }
    strBuffer += "]";
    return strBuffer;
}
