#include "func_continue.hpp"

func_continue::func_continue(int line, int col)
{
    Line = line;
    Col = col;

}

void func_continue::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    bool found_loop = false;

    if(env->Inside_For || env->Inside_While)
    {
        found_loop = true;
        gen->AddGoto(tree->ContinueLabel);
    }
   

    if(!found_loop)
    {
        // report an error
        std::string msg = "continue statement must be inside a while or for loop";
        tree->addError(msg, Line, Col);
        return;
    }

    env->Continue_flag = true;
}


