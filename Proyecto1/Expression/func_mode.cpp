#include "func_mode.hpp"

func_mode::func_mode(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

value func_mode::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);

    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
  
   if(vec_sym.Tipo == VECTOR){
        gen->AddComment("Comenzando a calcular moda");
        std::string sizeVector = std::to_string(vec_size);
        std::string fin = gen->newTemp();
        std::string cont = gen->newTemp();
        std::string temp_cont = gen->newTemp();
        std::string moda = gen->newTemp();
        std::string i = gen->newTemp();
        std::string j = gen->newTemp();

        gen->AddExpression(fin,sizeVector,"1","-");
        gen->AddAssign(cont,"0");
        gen->AddAssign(moda,vec_val + "[0]");
        gen->AddAssign(i,"0");

        std::string label1 = gen->newLabel();
        std::string label2 = gen->newLabel();
        std::string label3 = gen->newLabel();
        std::string label4 = gen->newLabel();
        std::string label5 = gen->newLabel();
        std::string label6 = gen->newLabel();
        std::string label7 = gen->newLabel();
        std::string label8 = gen->newLabel();

        gen->AddLabel(label1);
            gen->AddIf(i,fin,">",label2);
            gen->AddExpression(j,i,"1","+");
            gen->AddAssign(temp_cont,"1");
            
            gen->AddLabel(label3);
                gen->AddIf(j,fin,">",label4);
                std::string vec_i = gen->newTemp();
                std::string vec_j = gen->newTemp();
                gen->AddAssign(vec_i,vec_val + "[(int) " + i + "]");
                gen->AddAssign(vec_j,vec_val + "[(int) " + j + "]");
                gen->AddIf(vec_i,vec_j,"==",label5);
                gen->AddGoto(label6);
            
            gen->AddLabel(label5);
                gen->AddExpression(temp_cont,temp_cont,"1","+");
            
            gen->AddLabel(label6);
                gen->AddExpression(j,j,"1","+");
                gen->AddGoto(label3);

            gen->AddLabel(label4);
                gen->AddIf(temp_cont,cont,">",label7);
                gen->AddGoto(label8);

            gen->AddLabel(label7);
                gen->AddAssign(cont,temp_cont);
                gen->AddAssign(moda,vec_val + "[(int) " + i + "]");

            gen->AddLabel(label8);
                gen->AddExpression(i,i,"1","+");
                gen->AddGoto(label1);

            gen->AddLabel(label2);

            val = value(moda,true,INTEGER);
            return val;                         
   }

    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return val;
}
