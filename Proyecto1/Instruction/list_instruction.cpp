#include "list_instruction.hpp"
#include "Instruction/func_return.hpp"

list_instruction::list_instruction()
{
    this->ListInst = QVector<instruction*>();
}

void list_instruction::ejecutar(environment *env, ast *tree)
{
    for (int i = 0; i < this->ListInst.size(); i ++)
    {
        this->ListInst[i]->ejecutar(env, tree);
        //validación return de if
        if(tree->IfReturn)
        {
            return;
        }
        //validacion return function
        func_return* ret = dynamic_cast<func_return*>(ListInst[i]);
        if(ret)
        {
            return;
        }
    }
}

void list_instruction::newInst(instruction *inst)
{
    this->ListInst.push_back(inst);
}
