#ifndef DECLARE_MATRIX_HPP
#define DECLARE_MATRIX_HPP
#include "Interfaces/instruction.hpp"
#include "Expression/expression_vector.hpp"
#include <vector>

class declare_matrix : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string Id;
    list_expression* Valores;
    expression *Dimension1;
    expression *Dimension2;
    expression *Dimension3;
    std::string msgTipo;
    symbol dim1;
    symbol dim2;
    symbol dim3;
    

    declare_matrix(int line, int col, TipoDato tipo, std::string id,expression *dimension1, expression *dimension2, expression *dimension3, list_expression* valores);
    void ejecutar(environment *env, ast *tree) override;   
};

#endif // DECLARE_MATRIX_HPP
