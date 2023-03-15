#ifndef FUNC_WHILE_HPP
#define FUNC_WHILE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_while : public instruction
{
public:
    int Line;
    int Col;
    expression *Sentence;
    instruction *Block;

    func_while(int line, int col,expression *sentence,instruction *block);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_WHILE_HPP
