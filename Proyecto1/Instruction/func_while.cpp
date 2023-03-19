#include "func_while.hpp"
#include "Environment/environment.hpp"
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
        return;
    } else {
        condicion = *static_cast<bool*>(sym.Value);
    }

    // Usar la variable booleana "condicion" en la condición del ciclo while
    while (condicion) {
        environment *AnteriorEnv = env;
        environment *WhileEnv = new environment(env, "WHILE");

        Block->ejecutar(WhileEnv, tree);
        contador++;
        if (contador >= 50) {
            env = AnteriorEnv; // Volvemos al ambiente anterior
            delete WhileEnv;
            break;
        }
        if(tree->IfReturn){
            tree->IfReturn = false;
        }
        if(env->Break_flag){
            env->Break_flag = false;
            tree->IfReturn = false;
            env = AnteriorEnv; // Volvemos al ambiente anterior
            delete WhileEnv;
            break;
        }
        if(env->Continue_flag){
            env->Continue_flag = false;
            tree->IfReturn = false;
            env = AnteriorEnv; // Volvemos al ambiente anterior
            delete WhileEnv;
            continue;
        }
        env = AnteriorEnv; // Volvemos al ambiente anterior
        delete WhileEnv;
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

