#ifndef IF_HPP
#define IF_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class if : public instruction
{
public:
    int Line;
    int Col;
    expression *Valor;
    expression *Valor1;

    if(int line, int col, expression *valor, expression *valor1);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // if_HPP
