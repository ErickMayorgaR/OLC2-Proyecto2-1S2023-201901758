#ifndef FUNC_PUSHBACK_HPP
#define FUNC_PUSHBACK_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_pushback : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;

    func_pushback(int line, int col,std::string id,expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_PUSHBACK_HPP
