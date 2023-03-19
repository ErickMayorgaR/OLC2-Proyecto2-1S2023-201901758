#include "func_pushfront.hpp"

func_pushfront::func_pushfront(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

void func_pushfront::ejecutar(environment *env, ast *tree)
{
    symbol sym_data (Line,Col,"",NULO,nullptr);
    symbol sym = Valor->ejecutar(env,tree);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
    QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
    QVector<symbol>& result = *Vec;
    switch (sym.Tipo)
    {
    case STRING:
        sym_data = symbol(Line,Col,"",STRING,new std::string(*static_cast<std::string*>(sym.Value)));
        break;
    case INTEGER:
        sym_data = symbol(Line,Col,"",INTEGER,new int(*static_cast<int*>(sym.Value)));
        break;
    case FLOAT:
        sym_data = symbol(Line,Col,"",FLOAT,new float(*static_cast<float*>(sym.Value)));
        break;
    default:
        break;
    }
    result.prepend(sym_data);
    vec_sym.Value = &result;
    env->AssignVariable(vec_sym, Id, env, tree);

    std::string data = "[";
    for (int i = 0; i < result.size(); i++) {
        std::string value = "";
        switch (result[i].Tipo) {
        case STRING:
            value = *static_cast<std::string*>(result[i].Value);
            break;
        case INTEGER:
            value = std::to_string(*static_cast<int*>(result[i].Value));
            break;
        case FLOAT:
            value = std::to_string(*static_cast<float*>(result[i].Value));
            break;
        default:
            value = "NULL";
            break;  
        }
        data += value;
        if (i != result.size() - 1) {
            data += ",";
        }
    }
    data += "]";
    tree->changeSymbol(vec_sym.Id,data);
}

