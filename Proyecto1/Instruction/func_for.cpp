#include "func_for.hpp"

func_for::func_for(int line, int col, instruction *sentence1, expression *comparative, expression *sentence2, instruction *block)
{
    Line = line;
    Col = col;
    Sentence1 = sentence1;
    Comparative = comparative;
    Sentence2 = sentence2;
    Block = block;
}

void func_for::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    env->Inside_For = true;
    gen->AddComment("generando instruccion for");
    value condicion;
    Sentence1->ejecutar(env, tree, gen);

    std::string InitLvl = gen->newLabel();
    gen->AddLabel(InitLvl);
    //ejecutando expresion
    condicion = Comparative->ejecutar(env,tree,gen);
    //aqui se agregarian etiquetas break y continue
    if (condicion.Tipo != BOOL) {
        std::string msg = "invalid type for loop condition. Expected boolean.";
        tree->addError(msg, Line, Col);
        return;
    } 
    //etiqueta de retorno
    std::string RetLvl = gen->newLabel();
    gen->AddLabel(RetLvl);

    value val = Sentence2->ejecutar(env,tree,gen);
    gen->AddSetStack(tree->Index,val.Value);
    gen->AddGoto(InitLvl);
    //agregando etiquetas verdaderas
    for(int i=0; i < condicion.TrueLabel.size(); i++)
    {
        gen->AddLabel(condicion.TrueLabel[i]);
    }
    //En caso se encuentre un continue o break
    std::string continue_label = gen->newLabel();
    tree->ContinueLabel = continue_label;

    //ejecutando instrucciones
    Block->ejecutar(env, tree, gen);
    
    //retorno
    if(env->Continue_flag){
        gen->AddLabel(continue_label);
        env->Continue_flag = false;
    }
    
    gen->AddGoto(RetLvl);
    
    //agregando etiquetas falsas
    for(int i=0; i < condicion.FalseLabel.size(); i++)
    {
        gen->AddLabel(condicion.FalseLabel[i]);
    }

    env->Inside_For = false;
}

