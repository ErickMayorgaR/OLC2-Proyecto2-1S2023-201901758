#include "declare_matrix.hpp"

declare_matrix::declare_matrix(int line, int col, TipoDato tipo, std::string id, expression *dimension1, expression *dimension2, expression *dimension3, list_expression* valores) {
    Line = line;
    Col = col;
    Tipo = tipo;
    Id = id;
    Dimension1 = dimension1;
    Dimension2 = dimension2;
    Dimension3 = dimension3;
    Valores = valores;
}
void declare_matrix::ejecutar(environment *env, ast *tree)
{
    if(Dimension1 != nullptr){
        dim1 = Dimension1->ejecutar(env,tree);
    }
    else{
        std::string msg = "matrix must have at least one dimension.";
        tree->addError(msg, Line, Col);
        return;
    }
    
    if(Dimension2 != nullptr){
        dim2 = Dimension2->ejecutar(env,tree);
    }
    else{
        dim2 = symbol(Line,Col, "",INTEGER,new int(0));
    }

    if(Dimension3 != nullptr){
        dim3 = Dimension3->ejecutar(env,tree);
    }
    else{
        dim3 = symbol(Line,Col, "",INTEGER,new int(0));
    }
    
    
    if (dim1.Tipo != INTEGER || dim2.Tipo != INTEGER || dim3.Tipo != INTEGER) {
            std::string msg = "dimmensions must be integers.";
            tree->addError(msg,Line,Col);
            return;
    }

    int dimension1 = *static_cast<int*>(dim1.Value);
    int dimension2 = *static_cast<int*>(dim2.Value);
    int dimension3 = *static_cast<int*>(dim3.Value);

    if (dimension1 <= 0 || dimension2 < 0 || dimension3 < 0) {
        std::string msg = "Invalid matrix dimensions.";
        tree->addError(msg, Line, Col);
        return;
    }

    if(dimension2 != 0 && dimension3 != 0){
        int filas = dimension1;
        int columnas = dimension2;
        int profundidad = dimension3;
        std::vector<std::vector<std::vector<symbol>>> matrix(filas, std::vector<std::vector<symbol>>(columnas, std::vector<symbol>(profundidad)));
        if (Valores->ListExp.size() > 0) {
            if (filas != Valores->ListExp.size()) {
                std::string msg = "matrix initialization block size does not match rows matrix dimensions.";
                tree->addError(msg, Line, Col);
                return;
            } 
            for (int i = 0; i < filas; i++) {
                list_expression *vec_sym = (list_expression*)(Valores->ListExp[i]);
                if (columnas != vec_sym->ListExp.size()) {
                    std::string msg = "matrix initialization block size does not match columns matrix dimensions.";
                    tree->addError(msg, Line, Col);
                    return;
                } 
                for (int j = 0; j < columnas; j++) {
                    symbol vec_sym2 = vec_sym->ListExp[j]->ejecutar(env, tree);
                    QVector<symbol> *Vec = (QVector<symbol>*)vec_sym2.Value;
                    QVector<symbol> result = *Vec;
                    for (int k = 0; k < profundidad; k++) {
                        if (result[k].Tipo != Tipo) {
                        std::string msg = "matrix initialization block contains elements of incorrect type.";
                        tree->addError(msg, Line, Col);
                        return;
                        }
                        matrix[i][j][k] = result[k];
                    }
                }
            }
        }
        // Add the matrix to the environment
        symbol matrix_sym(Line, Col, Id, Tipo, &matrix);
        env->SaveVariable(matrix_sym, Id, tree);
    } 

    else if(dimension2 != 0 && dimension3 == 0){
        int filas = dimension1;
        int columnas = dimension2;
        std::vector<std::vector<symbol>> matrix(filas, std::vector<symbol>(columnas));
        if (Valores->ListExp.size() > 0) {
            if (filas != Valores->ListExp.size()) {
                std::string msg = "matrix initialization block size does not match matrix dimensions.";
                tree->addError(msg, Line, Col);
                return;
            } 
            for (int i = 0; i < filas; i++) {
                symbol vec_sym = Valores->ListExp[i]->ejecutar(env, tree);
                QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
                QVector<symbol> result = *Vec;
                for (int j = 0; j < columnas; j++) {
                    if (result[j].Tipo != Tipo) {
                    std::string msg = "matrix initialization block contains elements of incorrect type.";
                    tree->addError(msg, Line, Col);
                    return;
                    }
                    matrix[i][j] = result[j];
                }
            }
        }
        // Add the matrix to the environment
        symbol matrix_sym(Line, Col, Id, Tipo, &matrix);
        env->SaveVariable(matrix_sym, Id, tree);
    }   
    // Check if a block was provided to initialize the matrix
    else{
        int filas = dimension1;
        std::vector<std::vector<symbol>> matrix(1, std::vector<symbol>(filas));
        if (Valores->ListExp.size() > 0) {
            if (filas != Valores->ListExp.size()) {
                std::string msg = "matrix initialization block size does not match matrix dimensions.";
                tree->addError(msg, Line, Col);
                return;
            }
            for (int j = 0; j < filas; j++) {
                symbol value_sym = Valores->ListExp[j]->ejecutar(env, tree);
                if (value_sym.Tipo != Tipo) {
                std::string msg = "matrix initialization block contains elements of incorrect type.";
                tree->addError(msg, Line, Col);
                return;
                }
                matrix[0][j] = value_sym;
            }   
        }
        // Add the matrix to the environment
        symbol matrix_sym(Line, Col, Id, Tipo, &matrix);
        env->SaveVariable(matrix_sym, Id, tree);
    }


    if(Tipo == INTEGER){
        msgTipo = "int";
    }
    else if(Tipo == STRING){
        msgTipo = "string";
    }
    tree->addSymbol(Id,"matriz",msgTipo," ",Line,Col);
}

