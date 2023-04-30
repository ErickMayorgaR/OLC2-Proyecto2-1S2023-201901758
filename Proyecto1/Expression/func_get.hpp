#ifndef FUNC_GET_HPP
#define FUNC_GET_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_get : public expression
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;

    func_get(int line, int col,std::string id,expression *valor);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_GET_HPP
