#include "declare_vector.hpp"

declare_vector::declare_vector(int line, int col, TipoDato tipo, std::string id, expression *bloque)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Bloque = bloque;
}

void declare_vector::ejecutar(environment *env, ast *tree)
{
        // Save the vector in the environment
    symbol vec_sym = Bloque->ejecutar(env,tree);
    QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
    QVector<symbol> result = *Vec;
    env->SaveVariable(vec_sym,Id,tree);
    // Add the vector to the symbol table
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
    tree->addSymbol(Id, "variable", "vector", data, Line, Col);
}

