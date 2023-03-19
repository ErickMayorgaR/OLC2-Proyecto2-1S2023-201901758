#include "func_break.hpp"

func_break::func_break(int line, int col)
{
    Line = line;
    Col = col;

}

void func_break::ejecutar(environment *env, ast *tree)
{
    environment *current_env = env;
    bool found_loop = false;

    while(current_env != nullptr)
    {
        if(current_env->Inside_While)
        {
            found_loop = true;
            break;
        }

        current_env = current_env->Anterior;
    }

    if(!found_loop)
    {
        // report an error
        std::string msg = "break statement must be inside a while loop";
        tree->addError(msg, Line, Col);
        return;
    }
    current_env->Break_flag = true;
}

