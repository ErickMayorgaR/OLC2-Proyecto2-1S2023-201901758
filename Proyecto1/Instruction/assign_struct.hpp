#ifndef ASSIGN_STRUCT_HPP
#define ASSIGN_STRUCT_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class assign_struct : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    std::string Id2;
    expression *DataAfter;

    assign_struct(int line, int col,std::string id, std::string id2, expression *dataAfter);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // ASSIGN_STRUCT_HPP
