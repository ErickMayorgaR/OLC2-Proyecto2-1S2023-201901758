#ifndef EXPRESSION_VECTOR_H
#define EXPRESSION_VECTOR_H
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class expression_vector: public expression
{
public:
    int Line;
    int Col;
    list_expression *ExpList;
    QVector<symbol> VecTemp;
    expression_vector(int, int, list_expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // EXPRESSION_VECTOR_H
