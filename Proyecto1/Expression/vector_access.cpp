#include "vector_access.hpp"

vector_access::vector_access(int line, int col, expression *vector, expression *index)
{
    Line = line;
    Col = col;
    Vector = vector;
    Index = index;
}

symbol vector_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symVec = Vector->ejecutar(env, tree);
    symbol symInd = Index->ejecutar(env, tree);
    //validando tipo array
    if(symVec.Tipo == VECTOR && symInd.Tipo == INTEGER)
    {
        QVector<symbol> *Vec = (QVector<symbol>*)symVec.Value;
        QVector<symbol> result = *Vec;
        int *val = (int *)symInd.Value;
        sym = result[*val];
    }

    return sym;
}
