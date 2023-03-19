#include "expression_vector.hpp"

expression_vector::expression_vector(int line, int col, list_expression *explist)
{
    Line = line;
    Col = col;
    ExpList = explist;
}

symbol expression_vector::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    QVector<symbol> Vec = QVector<symbol>();
    for(int i=0; i < ExpList->ListExp.size(); ++i){
        Vec.push_back(ExpList->ListExp[i]->ejecutar(env, tree));
    }
    this->VecTemp = Vec;
    sym = symbol(Line, Col, "", VECTOR, &VecTemp);
    return sym;
}
