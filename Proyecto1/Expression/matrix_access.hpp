#ifndef MATRIX_ACCESS_HPP
#define MATRIX_ACCESS_HPP
#include "Interfaces/expression.hpp"

class matrix_access : public expression
{
public:
    int Line;
    int Col;
    expression *Matrix;
    expression *Index1;
    expression *Index2;

    matrix_access(int,int, expression*, expression*, expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // MATRIX_ACCESS_HPP
