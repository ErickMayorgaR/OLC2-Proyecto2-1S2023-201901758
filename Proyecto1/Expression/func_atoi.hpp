#ifndef FUNC_ATOI_HPP
#define FUNC_ATOI_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_atoi : public expression
{
public:
    int Line;
    int Col;
    expression *Valor;

    func_atoi(int line, int col, expression *valor);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_ATOI_HPP
