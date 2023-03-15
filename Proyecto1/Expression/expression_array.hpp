#ifndef EXPRESSION_ARRAY_HPP
#define EXPRESSION_ARRAY_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class expression_array: public expression
{
public:
    int Line;
    int Col;
    list_expression *ExpList;
    QVector<symbol> ArrTemp;
    expression_array(int, int, list_expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // EXPRESSION_ARRAY_HPP
