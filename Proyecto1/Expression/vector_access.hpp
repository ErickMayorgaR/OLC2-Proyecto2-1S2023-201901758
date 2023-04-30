#ifndef VECTOR_ACCESS_HPP
#define VECTOR_ACCESS_HPP
#include "Interfaces/expression.hpp"

class vector_access : public expression
{
public:
    int Line;
    int Col;
    expression *Array;
    expression *Index;
    vector_access(int,int, expression*, expression*);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // VECTOR_ACCESS_HPP
