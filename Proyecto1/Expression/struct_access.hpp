#ifndef STRUCT_ACCESS_HPP
#define STRUCT_ACCESS_HPP
#include "Interfaces/expression.hpp"

class struct_access : public expression
{
public:
    int Line;
    int Col;
    std::string StructExp;
    std::string Id;
    std::string Id2;

    struct_access(int,int, std::string, std::string, std::string);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // STRUCT_ACCESS_HPP
