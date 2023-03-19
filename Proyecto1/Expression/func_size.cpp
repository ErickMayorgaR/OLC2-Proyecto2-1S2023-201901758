#include "func_size.hpp"

func_size::func_size(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

symbol func_size::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
    QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
    QVector<symbol>& result = *Vec;
    sym = symbol(Line, Col, "", INTEGER, new int(static_cast<int>(result.size())));
    return sym;
}


