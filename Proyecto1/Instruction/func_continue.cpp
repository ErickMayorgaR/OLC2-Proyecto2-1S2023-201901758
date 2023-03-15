#include "func_continue.hpp"

func_continue::func_continue(int line, int col)
{
    Line = line;
    Col = col;

}

void func_continue::ejecutar(environment *env, ast *tree)
{
    if((!env->Inside_For)&&(!env->Inside_While))
    {
        // report an error
        std::string msg = "continue statement must be inside a while or for loop";
        tree->addError(msg, Line, Col);
        return;
    }

    env->Continue_flag = true;
}

