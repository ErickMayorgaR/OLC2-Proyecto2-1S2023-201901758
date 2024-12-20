#ifndef DECLARATION_HPP
#define DECLARATION_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class declaration : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    expression *Valor;
    std::string msgtipo;
    std::string msgdata;

    declaration(int line, int col, TipoDato tipo, std::string Id, expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // DECLARATION_HPP
