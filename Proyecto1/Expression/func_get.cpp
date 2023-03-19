#include "func_get.hpp"

func_get::func_get(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

symbol func_get::ejecutar(environment *env, ast *tree)
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
            sym = symbol(Line, Col, "", result.at(index).Tipo, result.at(index).Value);
        }
    }
    else{
        // report an error
            std::string msg = "invalid type for get.";
            tree->addError(msg, Line, Col);
    }
    return sym;
}

