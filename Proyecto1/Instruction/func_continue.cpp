#include "func_continue.hpp"

func_continue::func_continue(int line, int col)
{
    Line = line;
    Col = col;

}

void func_continue::ejecutar(environment *env, ast *tree)
{
    environment *current_env = env;
    bool found_loop = false;

    while(current_env != nullptr)
    {
        if(current_env->Inside_For || current_env->Inside_While)
        {
            found_loop = true;
            break;
        }

        current_env = current_env->Anterior;
    }

    if(!found_loop)
    {
        // report an error
        std::string msg = "continue statement must be inside a while or for loop";
        tree->addError(msg, Line, Col);
        return;
    }

    current_env->Continue_flag = true;
}


