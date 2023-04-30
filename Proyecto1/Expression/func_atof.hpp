#ifndef FUNC_ATOF_HPP
#define FUNC_ATOF_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_atof : public expression
{
public:
    int Line;
    int Col;
    expression *Valor;

    func_atof(int line, int col, expression *valor);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_ATOF_HPP
