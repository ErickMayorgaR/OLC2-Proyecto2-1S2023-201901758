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
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_MEAN_HPP
