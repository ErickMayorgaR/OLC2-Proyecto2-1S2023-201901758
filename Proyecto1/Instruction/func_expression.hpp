#ifndef FUNC_EXPRESSION_HPP
#define FUNC_EXPRESSION_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_expression : public instruction
{
public:
    int Line;
    int Col;
    expression *Valor;

    func_expression(int line, int col,expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // ASSIGN_HPP
