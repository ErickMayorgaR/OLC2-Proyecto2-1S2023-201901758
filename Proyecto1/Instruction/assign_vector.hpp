#ifndef ASSIGN_VECTOR_HPP
#define ASSIGN_VECTOR_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class assign_vector : public instruction
{
public:
    int Line;
    int Col;
    std::string Id;
    expression *Index;
    expression *Idafter;

    assign_vector(int line, int col,std::string id, expression *index,expression *idafter);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // ASSIGN_VECTOR_HPP
