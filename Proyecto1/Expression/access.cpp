#include "access.hpp"

access::access(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

symbol access::ejecutar(environment *env, ast *tree)
{
    symbol sym = env->GetVariable(Line, Col, Id, env, tree);
    return sym;
}
