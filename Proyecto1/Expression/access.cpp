#include "access.hpp"

access::access(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;
}

value access::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val;
    gen->AddComment("Llamando una variable");
    symbol retSym = env->GetVariable(Line,Col,Id,env,tree);
    std::string newTemp1 = gen->newTemp();
    std::string newTemp2 = gen->newTemp();

    if(gen->Main_Code)
    {
        if(retSym.Tipo != VECTOR){
            gen->AddGetStack(newTemp2, std::to_string(retSym.Value));
            tree->Index = std::to_string(retSym.Value);
        }
        else{
            auto it = env->TablaVector.find(Id);
            int index = std::distance(env->TablaVector.begin(), it);
            std::string vec_val = tree->StackVector.at(index);
            int vec_size = tree->SizeVector.at(index);
            tree->VectorSize = vec_size;
            newTemp2 = vec_val;
        }
        
    }
    else
    {
        gen->AddExpression(newTemp1, "P", std::to_string(retSym.Value), "+");
        gen->AddGetStack(newTemp2, "(int)"+newTemp1);
    }

    val = value(newTemp2, true, retSym.Tipo);
    return val;
}
