#include "func_if.hpp"

func_if::func_if(int line, int col, expression *condition, instruction *block, instruction *elseifblock, instruction *elseblock)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
    ElseIfBlock = elseifblock;
    ElseBlock = elseblock;
}

void func_if::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    gen->AddComment("generando instruccion if");
    value condicion = Condition->ejecutar(env, tree, gen);
    if(condicion.Tipo == BOOL)
    {
        std::string newLabel = gen->newLabel(); //etiqueta de salida
        //agregando etiquetas verdaderas
        for(int i=0; i < condicion.TrueLabel.size(); i++)
        {
            gen->AddLabel(condicion.TrueLabel[i]);
        }
        //instrucción del IF
        Block->ejecutar(env, tree, gen);
        //etiqueta salida
        if(!tree->ElseIfFlag){
            gen->AddGoto(newLabel);
        }
        else{
            gen->AddGoto(tree->ElseIfLabel);
        }
        //agregando etiquetas falsas
        for(int i=0; i < condicion.FalseLabel.size(); i++)
        {
            gen->AddLabel(condicion.FalseLabel[i]);
        }
        
        //instrucción del else if
        if(ElseIfBlock != nullptr)
        {
            tree->ElseIfFlag = true;
            tree->ElseIfLabel = newLabel;
            ElseIfBlock->ejecutar(env, tree, gen);
            tree->ElseIfFlag = false;
        }
        
        //instrucción del else
        if(ElseBlock != nullptr)
        {
            ElseBlock->ejecutar(env, tree, gen);
        }
        //etiqueta salida
        gen->AddLabel(newLabel);
    }
    else
    {
        //se reporta un error
        std::string msg = "invalid combination, incorrect type for if";
        tree->addError(msg,Line,Col);
    }
}
