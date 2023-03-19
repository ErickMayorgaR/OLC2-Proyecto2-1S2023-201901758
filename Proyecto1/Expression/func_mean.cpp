#include "func_mean.hpp"

func_mean::func_mean(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

symbol func_mean::ejecutar(environment *env, ast *tree)
{   
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
  
   if(vec_sym.Tipo == VECTOR){
        QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
        QVector<symbol>& result = *Vec;
        float total = 0;
        for(int i = 0; i < result.size(); i++){       
            int* value = static_cast<int*>(result[i].Value);
            total += *value;
        }
        float mean = total/result.size();
        sym.Tipo = FLOAT;
        sym.Value = new float(mean);
   }

    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return sym;
}

