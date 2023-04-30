#ifndef FUNC_REMOVE_HPP
#define FUNC_REMOVE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_remove : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Valor;

    func_remove(int line, int col,std::string id,expression *valor);
    void ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_REMOVE_HPP
