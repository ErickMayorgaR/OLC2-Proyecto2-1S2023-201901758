#include "func_atoi.hpp"

func_atoi::func_atoi(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;

}

value func_atoi::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val = Valor->ejecutar(env, tree, gen);
    if(val.Tipo == STRING)
    {
        try{
            std::string ptr = gen->newTemp();
            gen->AddAssign(ptr,val.Value);
            std::string suma = gen->newTemp();
            gen->AddAssign(suma,"0");
            std::string i = gen->newTemp();
            gen->AddAssign(i,"0");

            std::string loopLvl = gen->newLabel();
            gen->AddLabel(loopLvl);

            std::string newTemp1 = gen->newTemp();
            std::string val_heap = gen->newTemp();
            gen->AddExpression(val_heap, ptr, i, "+");
            gen->AddGetHeap(newTemp1, "(int) " + val_heap);

            std::string endLoop = gen->newLabel();           
            gen->AddIf(newTemp1,"-1","==",endLoop);

            std::string newTemp2 = gen->newTemp();   
            gen->AddExpression(newTemp2,newTemp1,"48","-");

            std::string newTemp3 = gen->newTemp();   
            gen->AddExpression(newTemp3,suma,"10","*");
            gen->AddExpression(suma,newTemp3,newTemp2,"+");
            gen->AddExpression(i,i,"1","+");
            gen->AddGoto(loopLvl);

            gen->AddLabel(endLoop);

            val = value(suma,true,INTEGER);
            return val;
        
        } catch(const std::invalid_argument& e) {
            // Conversion failed: invalid argument
            // report an error
            std::string msg = "invalid argument.";
            tree->addError(msg, Line, Col);
            return value("",false,NULO);

        } catch(const std::out_of_range& e) {
            // Conversion failed: out of range
            // report an error
            std::string msg = "out of range.";
            tree->addError(msg, Line, Col);
            return value("",false,NULO);
        }
            
    }

    else{
        // report an error
        std::string msg = "invalid type. String expected.";
        tree->addError(msg, Line, Col);
        return value("",false,NULO);
    }

}

