#include "declare_vector.hpp"

declare_vector::declare_vector(int line, int col, TipoDato tipo, std::string id, expression *bloque)
{
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Bloque = bloque;
}

void declare_vector::ejecutar(environment *env, ast *tree, generator_code *gen)
{    
    value val = Bloque->ejecutar(env,tree,gen);
    symbol newVar = env->SaveVariable(Line, Col, Id, VECTOR, tree);
    symbol Var = env->SaveVector(Line, Col, Id, VECTOR, tree);
    tree->StackVector.push_back(val.Value);
    tree->SizeVector.push_back(tree->VectorSize);
    std::string data = tree->Vector;
    tree->SaveVector.push_back(data);
    tree->addSymbol(Id, "variable", "vector", data, Line, Col);

}

