#ifndef VECTOR_EXP_HPP
#define VECTOR_EXP_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/expression.hpp"

class vector_exp: public expression
{
public:
    int Line;
    int Col;
    list_expression *ExpList;
    QVector<symbol> ArrTemp;
    vector_exp(int, int, list_expression*);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // VECTOR_EXP_HPP
