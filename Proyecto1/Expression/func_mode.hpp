#ifndef FUNC_MODE_HPP
#define FUNC_MODE_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"
#include <QMap>

class func_mode : public expression
{
public:
    int Line;
    int Col;
    std::string Id;

    func_mode(int line, int col, std::string id);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_MODE_HPP
