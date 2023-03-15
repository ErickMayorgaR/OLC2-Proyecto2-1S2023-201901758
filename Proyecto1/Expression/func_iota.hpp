#ifndef FUNC_IOTA_HPP
#define FUNC_IOTA_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_iota : public expression
{
public:
    int Line;
    int Col;
    expression *Valor;

    func_iota(int line, int col, expression *valor);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_IOTA_HPP
