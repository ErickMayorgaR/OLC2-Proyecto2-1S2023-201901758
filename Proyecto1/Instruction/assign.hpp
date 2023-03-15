#ifndef ASSIGN_HPP
#define ASSIGN_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class assign : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;
    std::string msgtipo;
    std::string dataAfter;

    assign(int line, int col,std::string Id,expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // ASSIGN_HPP
