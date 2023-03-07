#ifndef DECLARE_HPP
#define DECLARE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class declare : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    expression *Valor;

    declare(int line, int col,TipoDato tipo,std::string id,expression *valor);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // DECLARE_HPP
