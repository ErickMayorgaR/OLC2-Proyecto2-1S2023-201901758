#ifndef FUNC_MEAN_HPP
#define FUNC_MEAN_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_mean : public expression
{
public:
    int Line;
    int Col;
    std::string Id;

    func_mean(int line, int col, std::string id);
    value ejecutar(environment *env, ast *tree, generator_code *gen) override;
};

#endif // FUNC_MEAN_HPP
