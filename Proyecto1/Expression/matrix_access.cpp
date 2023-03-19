#include "matrix_access.hpp"

matrix_access::matrix_access(int line, int col, expression *matrix, expression *index1, expression *index2)
{
    Line = line;
    Col = col;
    Matrix = matrix;
    Index1 = index1;
    Index2 = index2;
}

symbol matrix_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol symMatrix = Matrix->ejecutar(env, tree);
    symbol symInd1 = Index1->ejecutar(env, tree);
    symbol symInd2 = Index2->ejecutar(env, tree);
    //validando tipo array
    if(symInd1.Tipo == INTEGER && symInd2.Tipo == INTEGER)
    {
        QVector<QVector<symbol>> *Vec = (QVector<QVector<symbol>>*)symMatrix.Value;
        QVector<QVector<symbol>> result = *Vec;
        int *val1 = (int *)symInd1.Value;
        int *val2 = (int *)symInd2.Value;
        sym = result[*val1][*val2];
    }

    return sym;
}
