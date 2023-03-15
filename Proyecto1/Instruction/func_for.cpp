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

void func_for::ejecutar(environment *env, ast *tree)
{
    Sentence1->ejecutar(env,tree);
    symbol sym = Comparative->ejecutar(env, tree);
    if(sym.Tipo == BOOL)
    {
        while(*static_cast<bool*>(Comparative->ejecutar(env, tree).Value)){
            env->Inside_For = true;
            //ejecuta el bloque
            if(env->Continue_flag){
                env->Continue_flag = false;
                Sentence2->ejecutar(env, tree);
                continue;
            }
            Block->ejecutar(env, tree);
            Sentence2->ejecutar(env, tree);
        }
        
        env->Inside_For = false;
        return;

    }

    else
    {
        //se reporta un error
        std::string msg = "invalid combination, incorrect type for for";
        tree->addError(msg,Line,Col);
    }
}

