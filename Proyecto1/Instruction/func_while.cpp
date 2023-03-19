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
    env->Inside_While = true;
    bool condicion = false;
    int contador = 0; // Inicializar el contador en cero
    symbol sym = Sentence->ejecutar(env, tree);
    if (sym.Tipo != BOOL) {
        std::string msg = "invalid type for while loop condition. Expected boolean.";
        tree->addError(msg, Line, Col);
    } else {
        condicion = *static_cast<bool*>(sym.Value);
    }

    // Usar la variable booleana "condicion" en la condición del ciclo while
    while (condicion) {
        if(env->Break_flag){
            env->Break_flag = false;
            break;
        }
        if(env->Continue_flag){
            env->Continue_flag = false;
            continue;
        }
        Block->ejecutar(env, tree);
        contador++;
        if (contador >= 50) {
            break;
        }
        // Volver a evaluar la expresión de la condición al final de cada iteración
        sym = Sentence->ejecutar(env, tree);
        if (sym.Tipo != BOOL) {
            std::string msg = "invalid type for while loop condition. Expected boolean.";
            tree->addError(msg, Line, Col);
            break;
        } else {
            condicion = *static_cast<bool*>(sym.Value);
        }
    }
    env->Inside_While = false;
}

