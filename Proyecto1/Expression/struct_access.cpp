#include "struct_access.hpp"

struct_access::struct_access(int line,int col, std::string structexp, std::string id, std::string id2)
{
    Line = line;
    Col = col;
    StructExp = structexp;
    Id = id;
    Id2 = id2;
}

symbol struct_access::ejecutar(environment *env, ast *tree)
{
    symbol sym (0,0,"",NULO,nullptr);

    if(Id2 != "NO"){
        symbol symStruct = env->GetVariable(Line, Col, StructExp, env, tree);
        environment *envStruct = (environment *)symStruct.Value;
        sym = envStruct->GetVariable(Line, Col, Id, envStruct,tree);
        environment *envId = (environment *)sym.Value;
        symbol symId2 = env->GetVariable(Line, Col, Id2, envId, tree);
        return symId2;
    }
    //recuperar struct
    symbol symStruct = env->GetVariable(Line, Col, StructExp, env, tree);
    environment *envStruct = (environment *)symStruct.Value;

    sym = envStruct->GetVariable(Line, Col, Id, envStruct,tree);
    return sym;
}
