#ifndef FUNC_MEDIAN_HPP
#define FUNC_MEDIAN_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_median : public expression
{
public:
    int Line;
    int Col;
    std::string Id;

    func_median(int line, int col, std::string id);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_MEDIAN_HPP
