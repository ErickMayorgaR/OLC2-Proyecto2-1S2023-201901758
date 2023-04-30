#include "func_median.hpp"

func_median::func_median(int line, int col, std::string id)
{
    Line = line;
    Col = col;
    Id = id;

}

value func_median::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val;
    auto it = env->TablaVector.find(Id);
    int index = std::distance(env->TablaVector.begin(), it);
    std::string vec_val = tree->StackVector.at(index);
    int vec_size = tree->SizeVector.at(index);

    symbol vec_sym = env->GetVariable(Line, Col, Id, env, tree);
  
   if(vec_sym.Tipo == VECTOR){
        gen->AddComment("Comenzando a calcular mediana");
        
        std::string i = gen->newTemp();
        std::string fin = gen->newTemp();
        std::string sizeVector = std::to_string(vec_size);
    
        gen->AddAssign(i,"0");
        gen->AddExpression(fin, sizeVector, "1", "-");
        std::string label1 = gen->newLabel();
        std::string true_orden = gen->newLabel();
        std::string false_orden = gen->newLabel();
        
        gen->AddLabel(label1);
            gen->AddIf(i,fin, "<", true_orden);
            gen->AddGoto(false_orden);

            gen->AddLabel(true_orden);
                std::string j = gen->newTemp();
                gen->AddExpression(j, i,"1","+");

                std::string label2 = gen->newLabel();
                std::string label2_true = gen->newLabel();
                std::string label2_false = gen->newLabel();

                gen->AddLabel(label2);
                    gen->AddIf(j,sizeVector,"<",label2_true);
                    gen->AddGoto(label2_false);

                    gen->AddLabel(label2_true);
                    
                        std::string label3_true = gen->newLabel();
                        std::string label3_false = gen->newLabel();

                        std::string temp_i = gen->newTemp();
                        std::string temp_j = gen->newTemp();

                        gen->AddAssign(temp_i,vec_val + "[(int) " + i + "]");
                        gen->AddAssign(temp_j,vec_val + "[(int) " + j + "]");
                        gen->AddIf(temp_i,temp_j,">",label3_true);
                        gen->AddGoto(label3_false);

                        gen->AddLabel(label3_true);
                            std::string temp = gen->newTemp();
                            gen->AddAssign(temp,vec_val + "[(int) " + i + "]");
                            gen->AddAssign(vec_val + "[(int) " + i + "]",vec_val + "[(int) " + j + "]");
                            gen->AddAssign(vec_val + "[(int) " + j + "]",temp);
                            gen->AddExpression(j,j,"1","+");
                            gen->AddGoto(label2);

                        gen->AddLabel(label3_false);
                            gen->AddExpression(j,j,"1","+");
                            gen->AddGoto(label2);
                        
                    gen->AddLabel(label2_false);
                    gen->AddExpression(i,i,"1","+");
                    gen->AddGoto(label1);
        gen->AddLabel(false_orden);

        std::string label4 = gen->newLabel();
        std::string label4_true = gen->newLabel();
        std::string label4_false = gen->newLabel();
        
        std::string mod = gen->newTemp();
        gen->AddExpression(mod,"(int) " + sizeVector,"2","%");
        gen->AddIf(mod,"0","==",label4_true);
        gen->AddGoto(label4_false);

        gen->AddLabel(label4_true);
            std::string pos = gen->newTemp();
            std::string pos_1 = gen->newTemp();
            std::string vec_pos = gen->newTemp();
            std::string vec_pos_1 = gen->newTemp();
            std::string temp_med = gen->newTemp();
            std::string mediana_par = gen->newTemp();
            gen->AddExpression(pos, sizeVector,"2","/");
            gen->AddExpression(pos_1, pos,"1","-");
            gen->AddAssign(vec_pos,vec_val+"[(int) " + pos + "]");
            gen->AddAssign(vec_pos_1,vec_val+"[(int) " + pos_1 + "]");
            gen->AddExpression(temp_med, vec_pos_1,vec_pos,"+");
            gen->AddExpression(mediana_par, temp_med,"2","/");   
            gen->AddGoto(label4);
        gen->AddLabel(label4_false);
            pos = gen->newTemp();
            pos_1 = gen->newTemp();
            temp_med = gen->newTemp();
            std::string mediana_impar = gen->newTemp();
            gen->AddExpression(temp_med, sizeVector,"1","+");
            gen->AddExpression(pos, temp_med,"2","/");
            gen->AddExpression(pos_1, pos,"1","-");
            gen->AddAssign(mediana_impar, vec_val + "[(int) " + pos_1 + "]"); 

        gen->AddLabel(label4);

        if(vec_size % 2 == 0){
            val = value(mediana_par, true, INTEGER);
        }
        else{
            val = value(mediana_impar, true, INTEGER);
        }
        
        return val;
   }
    else{
        // report an error
        std::string msg = "invalid type. Vector expected.";
        tree->addError(msg, Line, Col);
    }
    return val;
}
