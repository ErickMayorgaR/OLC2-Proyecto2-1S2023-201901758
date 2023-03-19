#ifndef FUNC_SIZE_HPP
#define FUNC_SIZE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_size : public expression
{
public:
    int Line;
    int Col;
    std::string Id;

    func_size(int line, int col,std::string id);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_SIZE_HPP
