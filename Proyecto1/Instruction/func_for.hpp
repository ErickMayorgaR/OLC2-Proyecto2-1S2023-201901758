#ifndef FUNC_FOR_HPP
#define FUNC_FOR_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_for : public instruction
{
public:
    int Line;
    int Col;
    instruction *Sentence1;
    expression *Comparative;
    expression *Sentence2;
    instruction *Block;

    func_for(int line, int col, instruction *sentence1, expression *comparative, expression *sentence2, instruction *block);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_FOR_HPP
