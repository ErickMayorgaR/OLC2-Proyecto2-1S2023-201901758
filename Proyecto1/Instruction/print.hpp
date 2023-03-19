#ifndef PRINT_HPP
#define PRINT_HPP
#include "Expression/list_expression.hpp"
#include "Interfaces/instruction.hpp"

class print : public instruction
{
public:
    int Line;
    int Col;
    list_expression *Valor;
    symbol sym;

    print(int, int, list_expression*);
    std::string VectorToString(QVector<symbol> vector);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // PRINT_HPP
