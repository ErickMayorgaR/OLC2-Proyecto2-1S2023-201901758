#include "func_mean.hpp"

func_mean::func_mean(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

value func_mean::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);

    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
    if(vec_sym.Tipo == VECTOR){
        gen->AddComment("Comenzando a calcular media");
        std::string newTemp2 = gen->newTemp();
        std::string sizeVector = std::to_string(vec_size);

        gen->AddAssign(newTemp2,"0");

        std::string newLabel = gen->newLabel();
        std::string trueLabel = gen->newLabel();
        std::string falseLabel = gen->newLabel();
        gen->AddLabel(newLabel);
        gen->AddIf(newTemp2,sizeVector,"<",trueLabel);
        gen->AddGoto(falseLabel);
        gen->AddLabel(trueLabel);

        std::string newTemp3 = gen->newTemp();
        std::string newTemp4 = gen->newTemp();
        std::string newTemp5 = gen->newTemp();

        gen->AddAssign(newTemp5,vec_val + "[(int) " + newTemp2 + "]");
        gen->AddExpression(newTemp3,newTemp3,newTemp5,"+");
        gen->AddExpression(newTemp2,newTemp2,"1","+");
        gen->AddGoto(newLabel);

        gen->AddLabel(falseLabel);

        std::string val_media = gen->newTemp();
        gen->AddExpression(val_media,newTemp3,"10","/");

        val = value(val_media,true,FLOAT);   
        return val;     
   }
    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return val;
}

