#include "assign_struct.hpp"

assign_struct:: assign_struct(int line, int col,std::string id, std::string id2, expression *dataAfter)
{
    Line = line;
    Col = col;
    Id = id;
    Id2 = id2;
    DataAfter = dataAfter;
}


void assign_struct::ejecutar(environment *env, ast *tree)
{
    symbol sym_data (Line,Col,"",NULO,nullptr);
    //Se ejecutan ambos datos
    symbol symStruct = env->GetVariable(Line, Col, Id, env, tree);
    environment *envStruct = (environment *)symStruct.Value;
    //Se accede al struct
    symbol sym = envStruct->GetVariable(Line, Col, Id2, envStruct,tree);
    sym_data = DataAfter->ejecutar(env,tree);
    if(sym.Tipo == sym_data.Tipo){
        sym.Value = sym_data.Value;
        envStruct->AssignVariable(sym,Id2,envStruct,tree);
    }
    else{
        //se reporta un error
        std::string msg = "invalid type for assign.";
        tree->addError(msg,Line,Col);
    }
    

}
