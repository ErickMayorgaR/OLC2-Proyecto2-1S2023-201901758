#include "assign_vector.hpp"

assign_vector::assign_vector(int line, int col,std::string id, expression *index,expression *idafter)
{
    Line = line;
    Col = col;
    Id = id;
    Index = index;
    Idafter = idafter;
}


void assign_vector::ejecutar(environment *env, ast *tree)
{
    symbol sym_data (Line,Col,"",NULO,nullptr);
    //Se ejecutan ambos datos
    symbol val_index = Index->ejecutar(env, tree); //Se obtiene el indice 
    symbol data_after = Idafter->ejecutar(env, tree); //El valor por el que se quiere cambiar

    //Se obtienen el vector 
    symbol symVec = env->GetVariable(Line, Col, Id, env, tree);

    //validando tipo array
    if(symVec.Tipo == VECTOR && val_index.Tipo == INTEGER)
    {
        QVector<symbol> *Vec = (QVector<symbol>*)symVec.Value;
        QVector<symbol> result = *Vec;
        int index1 = *static_cast<int*>(val_index.Value);
        if (index1 < 0 || index1 >= result.size()) {
            // reportar un error
            std::string msg = "index out of range.";
            tree->addError(msg, Line, Col);
        } else {
            int *val = (int *)val_index.Value;

            if(result[0].Tipo == data_after.Tipo){
                switch (data_after.Tipo)
                {
                case STRING:
                    sym_data = symbol(Line,Col,"",STRING,new std::string(*static_cast<std::string*>(data_after.Value)));
                    break;
                case INTEGER:
                    sym_data = symbol(Line,Col,"",INTEGER,new int(*static_cast<int*>(data_after.Value)));
                    break;
                case FLOAT:
                    sym_data = symbol(Line,Col,"",FLOAT,new float(*static_cast<float*>(data_after.Value)));
                    break;
                default:
                    break;
                }
                result[index1] = sym_data;
                symVec.Value = new QVector<symbol>(result);
                env->AssignVariable(symVec, Id, env, tree);
                
                std::string data = "[";
                for (int i = 0; i < result.size(); i++) {
                    std::string value = "";
                    switch (result[i].Tipo) {
                    case STRING:
                        value = *static_cast<std::string*>(result[i].Value);
                        break;
                    case INTEGER:
                        value = std::to_string(*static_cast<int*>(result[i].Value));
                        break;
                    case FLOAT:
                        value = std::to_string(*static_cast<float*>(result[i].Value));
                        break;
                    default:
                        value = "NULL";
                        break;  
                    }
                    data += value;
                    if (i != result.size() - 1) {
                        data += ",";
                    }
                }
                data += "]";
                tree->changeSymbol(Id,data);
            }
            else{
                //se reporta un error
                std::string msg = "incompatible types.";
                tree->addError(msg,Line,Col);
            }
        }
    }

    else
    {
        //se reporta un error
        std::string msg = "invalid type for assign.";
        tree->addError(msg,Line,Col);
    }
}
