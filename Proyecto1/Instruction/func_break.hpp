#ifndef FUNC_BREAK_HPP
#define FUNC_BREAK_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_break : public instruction
{
public:
    int Line;
    int Col;

    func_break(int line, int col);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_FOR_HPP
