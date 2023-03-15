#include "func_while.hpp"

func_while::func_while(int line, int col, expression *sentence,instruction *block)
{
    Line = line;
    Col = col;
    Sentence = sentence;
    Block = block;
}

void func_while::ejecutar(environment *env, ast *tree)
{
    symbol sym = Sentence->ejecutar(env, tree);
    if(sym.Tipo == BOOL)
    {
        env->Inside_While = true;
        while(*static_cast<bool*>(Sentence->ejecutar(env, tree).Value)){      
            //ejecuta el bloque
            if(env->Break_flag){
                env->Break_flag = false;
                break;
            }
            if(env->Continue_flag){
                env->Continue_flag = false;
                continue;
            }
            Block->ejecutar(env, tree);
        }
        env->Inside_While = false;

            return;

    }

    else
    {
        //se reporta un error
        std::string msg = "invalid type for while loop condition. Expected boolean.";
        tree->addError(msg,Line,Col);
    }
}

