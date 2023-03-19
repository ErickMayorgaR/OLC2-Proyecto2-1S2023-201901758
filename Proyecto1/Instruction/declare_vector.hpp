#ifndef DECLARE_VECTOR_HPP
#define DECLARE_VECTOR_HPP
#include "Interfaces/instruction.hpp"
#include "Expression/expression_vector.hpp"
#include <vector>
using typedata = std::variant<int, float, std::string>;
using typedata_vector = std::vector<typedata>;

class declare_vector : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    expression *Bloque;

    declare_vector(int, int, TipoDato, std::string, expression*);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // DECLARE_VECTOR_HPP
