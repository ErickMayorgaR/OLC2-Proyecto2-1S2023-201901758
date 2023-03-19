#include "func_median.hpp"

func_median::func_median(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

symbol func_median::ejecutar(environment *env, ast *tree)
{   
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
  
   if(vec_sym.Tipo == VECTOR){
        QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
        QVector<symbol>& result = *Vec;

        std::sort(result.begin(), result.end(), [](const symbol& a, const symbol& b) {
            int a_value = *(static_cast<int*>(a.Value));
            int b_value = *(static_cast<int*>(b.Value));
            return a_value < b_value;
        });
        
        int mediana = 0;
        int middle = result.size() / 2;
        if(result.size() % 2 == 0) {
            int a = *(static_cast<int*>(result[middle - 1].Value));
            int b = *(static_cast<int*>(result[middle].Value));
            mediana = (a + b) / 2.0;
        } else {
            mediana = *(static_cast<int*>(result[middle].Value));
        }

        sym.Tipo = INTEGER;
        sym.Value = new int(mediana);
   }

    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return sym;
}
