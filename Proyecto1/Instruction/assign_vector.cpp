#include "assign_vector.hpp"

assign_vector::assign_vector(int line, int col,std::string id, expression *index,expression *idafter)
{
    Line = line;
    Col = col;
    Id = id;
    Index = index;
    Idafter = idafter;
}


void assign_vector::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val_index;
    value data_after;

    value val;

    //Se obtienen el vector 
    symbol symVec = env->GetVariable(Line, Col, Id, env, tree);
    val_index = Index->ejecutar(env,tree,gen);
    std::string valor_index = tree->Index;

    // vec[1] = vec[0];
    // vec[i] = vec[j]; tree -> index = 7 

    //validando tipo array
    if(symVec.Tipo == VECTOR && val_index.Tipo == INTEGER)
    {
        tree->InsideAssign = true;
        auto it = env->TablaVector.find(Id);
        int index = std::distance(env->TablaVector.begin(), it);
        std::string vec_val = tree->StackVector.at(index);
        int vec_size = tree->SizeVector.at(index);

        data_after = Idafter->ejecutar(env,tree,gen);

        gen->AddAssign(vec_val + "[(int) " + val_index.Value + "]",data_after.Value);

        symbol newVar = env->AssignVariable(Line, Col, Id, VECTOR, env, tree);
        symbol Var = env->AssignVector(Line, Col, Id, VECTOR, env, tree);


        std::string temp_str = tree->SaveVector.at(index);

        if(data_after.Tipo == VECTOR){
            /* // Definir la posición del elemento a eliminar
            int pos_after = std::stoi(tree->IndexAccess);
            int pos_before = std::stoi(valor_index);

            // Obtener la posición de la primera coma a eliminar
            int start_pos;
            if (pos_before == 0) {
                start_pos = temp_str.find('[') + 1;
            } else {
                int num_comas = 0;
                int while_i = 0;
                while(num_comas < pos_before){
                    if (temp_str[while_i] == ',') {
                        num_comas++;
                    }
                    while_i++;
                }
                start_pos = while_i;
            }


            // Obtener la posición de la segunda coma a eliminar
            int num_comas = 0;
            int while_i_end = start_pos;
                while(num_comas < 1){
                    if (temp_str[while_i_end] == ',') {
                        num_comas++;
                    }
                    while_i_end++;
                }
            int end_pos = while_i_end-1;

            std::string data_temp;

            for(int i = 0; i < end_pos; i++){
                data_temp += temp_str[start_pos + i];
            }

            // Obtener la posición de la primera coma a eliminar
            if (pos_after == 0) {
                start_pos = temp_str.find('[') + 1;
            } else {
                int num_comas = 0;
                int while_i = 0;
                while(num_comas < pos_after){
                    if (temp_str[while_i] == ',') {
                        num_comas++;
                    }
                    while_i++;
                }
                start_pos = while_i;
            }


            // Obtener la posición de la segunda coma a eliminar
            num_comas = 0;
            while_i_end = start_pos;
                while(num_comas < 1){
                    if (temp_str[while_i_end] == ',') {
                        num_comas++;
                    }
                    while_i_end++;
                }
            end_pos = while_i_end-1;

            // Si no se encontró la segunda coma, significa que estamos eliminando el último elemento
            if (end_pos == std::string::npos) {
                end_pos = temp_str.find(']', start_pos + 1);
            }

            // Eliminar el substring que se encuentra entre las dos posiciones obtenidas
            temp_str.erase(start_pos, end_pos - start_pos + 1);
            temp_str.insert(start_pos,data_temp);
            tree->SaveVector.at(index) = temp_str; */
            std::string data = tree->SaveVector.at(index);
            tree->changeSymbol(Id,data); 
        } else{
            /* int pos_after = std::stoi(valor_index);

            // Obtener la posición de la primera coma a eliminar
            int start_pos;
            if (pos_after == 0) {
                start_pos = temp_str.find('[') + 1;
            } else {
                int num_comas = 0;
                int while_i = 0;
                while(num_comas < pos_after){
                    if (temp_str[while_i] == ',') {
                        num_comas++;
                    }
                    while_i++;
                }
                start_pos = while_i;

            }


            // Obtener la posición de la segunda coma a eliminar
            int num_comas = 0;
            int while_i_end = start_pos;
                while(num_comas < 1){
                    if (temp_str[while_i_end] == ',') {
                        num_comas++;
                    }
                    while_i_end++;
                }
            int end_pos = while_i_end-1;

            // Si no se encontró la segunda coma, significa que estamos eliminando el último elemento
            if (end_pos == std::string::npos) {
                end_pos = temp_str.find(']', start_pos + 1);
            }

            // Eliminar el substring que se encuentra entre las dos posiciones obtenidas
            temp_str.erase(start_pos, end_pos - start_pos + 1);
            temp_str.insert(start_pos,data_after.Value);
            tree->SaveVector.at(index) = temp_str; */
            std::string data = tree->SaveVector.at(index);
            tree->changeSymbol(Id,data);
        }
        tree->InsideAssign = false; 
    }
    else
    {
        //se reporta un error
        std::string msg = "invalid type for assign.";
        tree->addError(msg,Line,Col);
    } 
}
