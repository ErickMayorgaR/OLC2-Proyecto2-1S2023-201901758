#include "func_break.hpp"

func_break::func_break(int line, int col)
{
    Line = line;
    Col = col;

}

void func_break::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    bool found_loop = false;

    if(env->Inside_While)
    {
        found_loop = true;
        gen->AddGoto(tree->BreakLabel);
    }


    if(!found_loop)
    {
        // report an error
        std::string msg = "break statement must be inside a while loop";
        tree->addError(msg, Line, Col);
        return;
    }
    env->Break_flag = true;
}

