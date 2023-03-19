#ifndef FUNC_PUSHFRONT_HPP
#define FUNC_PUSHFRONT_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_pushfront : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;

    func_pushfront(int line, int col,std::string id,expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_PUSHFRONT_HPP
