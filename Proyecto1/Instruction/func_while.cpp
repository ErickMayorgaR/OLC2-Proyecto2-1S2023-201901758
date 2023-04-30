
#include "func_while.hpp"

func_while::func_while(int line, int col, expression *condition, instruction *block)
{
    Line = line;
    Col = col;
    Condition = condition;
    Block = block;
}

void func_while::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    env->Inside_While = true;
    gen->AddComment("generando instruccion while");
    value condicion;
    //etiqueta de retorno
    std::string RetLvl = gen->newLabel();
    gen->AddLabel(RetLvl);
    //ejecutando expresion
    condicion = Condition->ejecutar(env, tree, gen);
    if (condicion.Tipo != BOOL) {
        std::string msg = "invalid type for while loop condition. Expected boolean.";
        tree->addError(msg, Line, Col);
        return;
    }

    //agregando etiquetas verdaderas
    for(int i=0; i < condicion.TrueLabel.size(); i++)
    {
        gen->AddLabel(condicion.TrueLabel[i]);
    }
    //En caso se encuentre un continue o break
    std::string continue_label = gen->newLabel();
    std::string break_label = gen->newLabel();
    tree->BreakLabel = break_label;
    tree->ContinueLabel = continue_label;

    //ejecutando instrucciones
    Block->ejecutar(env, tree, gen);
    
    //retorno
    if(env->Continue_flag){
        gen->AddLabel(continue_label);
        env->Continue_flag = false;
    }
    
    gen->AddGoto(RetLvl);
    if(env->Break_flag){
        gen->AddLabel(break_label);
        env->Break_flag = false;
    }
    
    //agregando etiquetas falsas
    for(int i=0; i < condicion.FalseLabel.size(); i++)
    {
        gen->AddLabel(condicion.FalseLabel[i]);
    }

    env->Inside_While = false;
}
