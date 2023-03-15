#include "func_break.hpp"

func_break::func_break(int line, int col)
{
    Line = line;
    Col = col;

}

void func_break::ejecutar(environment *env, ast *tree)
{
    if(!env->Inside_While)
    {
        // report an error
        std::string msg = "break statement must be inside a while loop";
        tree->addError(msg, Line, Col);
        return;
    }

    env->Break_flag = true;
}

