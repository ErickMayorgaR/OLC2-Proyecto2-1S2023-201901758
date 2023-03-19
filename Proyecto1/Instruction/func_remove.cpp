#include "func_remove.hpp"

func_remove::func_remove(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

void func_remove::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol sym_data = Valor->ejecutar(env,tree);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
    QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
    QVector<symbol>& result = *Vec;
 
    if(sym_data.Tipo == INTEGER){
        int index = *static_cast<int*>(sym_data.Value);
        if (index < 0 || index >= result.size()) {
            // reportar un error
            std::string msg = "index out of range.";
            tree->addError(msg, Line, Col);
        } else {
            result.remove(index);
            vec_sym.Value = &result;
            env->AssignVariable(vec_sym, Id, env, tree);
        }
    }
    else{
        // report an error
            std::string msg = "invalid type for remove.";
            tree->addError(msg, Line, Col);
    }

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

