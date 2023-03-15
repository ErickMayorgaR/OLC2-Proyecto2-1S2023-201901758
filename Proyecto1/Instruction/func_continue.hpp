#ifndef FUNC_CONTINUE_HPP
#define FUNC_CONTINUE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_continue : public instruction
{
public:
    int Line;
    int Col;

    func_continue(int line, int col);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_CONTINUE_HPP
