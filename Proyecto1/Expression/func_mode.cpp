#include "func_mode.hpp"

func_mode::func_mode(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

symbol func_mode::ejecutar(environment *env, ast *tree)
{   
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
  
   if(vec_sym.Tipo == VECTOR){
        QVector<symbol> *Vec = (QVector<symbol>*)vec_sym.Value;
        QVector<symbol>& result = *Vec;

        QMap<int, int> countMap;
        for(int i = 0; i < result.size(); i++) {
            countMap[*static_cast<int*>(result[i].Value)]++;
        }
        int maxCount = 0;
        symbol moda = symbol(Line, Col, "", NULO, nullptr);

        QMap<int, int>::iterator it;
        for(it = countMap.begin(); it != countMap.end(); it++) {
            if(it.value() > maxCount) {
                maxCount = it.value();
                int* value = new int(it.key());
                moda.Value = static_cast<void*>(value);

            }
        }
        moda.Tipo = INTEGER;
        sym = moda;

   }

    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return sym;
}
