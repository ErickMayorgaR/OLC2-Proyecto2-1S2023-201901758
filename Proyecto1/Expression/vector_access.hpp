#ifndef VECTOR_ACCESS_HPP
#define VECTOR_ACCESS_HPP
#include "Interfaces/expression.hpp"

class vector_access : public expression
{
public:
    int Line;
    int Col;
    expression *Vector;
    expression *Index;
    vector_access(int,int, expression*, expression*);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // VECTOR_ACCESS_HPP
