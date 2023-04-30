
#include "assignment.hpp"

assignment::assignment(int line, int col, std::string id, expression *valor)
{
    Line = line;
    Col = col;
    Id = id;
    Valor = valor;
}

void assignment::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    gen->AddComment("Generando asignación");
    //buscando variable en entorno
    symbol sym = env->GetVariable(Line, Col, Id,env, tree);
    //ejecutando valor
    value val = Valor->ejecutar(env, tree, gen);
    //asignando valor
    gen->AddSetStack(std::to_string(sym.Value), val.Value);
    gen->AddEnter();
}
