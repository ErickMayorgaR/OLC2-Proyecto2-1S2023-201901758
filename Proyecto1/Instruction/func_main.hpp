#ifndef FUNC_MAIN_HPP
#define FUNC_MAIN_HPP
#include "Instruction/list_instruction.hpp"
#include "Interfaces/instruction.hpp"
#include <vector>

class func_main : public instruction
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    list_instruction *ListaInstr;

    func_main(int line, int col, TipoDato tipo, list_instruction *listainst);
    void ejecutar(environment *env, ast* tree) override;
};

#endif // FUNC_MAIN_HPP
