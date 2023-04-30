#include "func_atof.hpp"

func_atof::func_atof(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;

}

value func_atof::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val = Valor->ejecutar(env, tree,gen);
    if(val.Tipo == STRING)
    {
        try{
            std::string ptr = gen->newTemp();
            gen->AddAssign(ptr,val.Value);
            std::string suma_entera = gen->newTemp();
            std::string suma_decimal = gen->newTemp();
            std::string potencia_decimal = gen->newTemp();
            gen->AddAssign(suma_entera,"0");
            gen->AddAssign(suma_decimal,"0");
            gen->AddAssign(potencia_decimal,"1.0");
            std::string i = gen->newTemp();
            gen->AddAssign(i,"0");

            std::string flag_entero = gen->newTemp();
            gen->AddAssign(flag_entero,"1");

            std::string loopLvl = gen->newLabel();
            gen->AddLabel(loopLvl);

            std::string newTemp1 = gen->newTemp();
            std::string val_heap = gen->newTemp();
            gen->AddExpression(val_heap,ptr,i,"+");
            gen->AddGetHeap(newTemp1, "(int) " + val_heap);

            std::string endLoop = gen->newLabel();           
            gen->AddIf(newTemp1,"-1","==",endLoop);

            std::string puntoDecimal = gen->newLabel(); 
            std::string NotPuntoDecimal = gen->newLabel();           
            gen->AddIf(newTemp1,"46","==",puntoDecimal);
            gen->AddGoto(NotPuntoDecimal);

            gen->AddLabel(puntoDecimal);
            gen->AddAssign(flag_entero,"0");
            gen->AddExpression(i,i,"1","+");
            gen->AddGoto(loopLvl);
            
            gen->AddLabel(NotPuntoDecimal);
            std::string newTemp2 = gen->newTemp();   
            gen->AddExpression(newTemp2,newTemp1,"48","-");

            std::string Entero = gen->newLabel();
            gen->AddIf(flag_entero,"1","==",Entero);
            std::string notEntero = gen->newLabel();
            gen->AddGoto(notEntero);

            std::string jump = gen->newLabel();

            gen->AddLabel(Entero);
            std::string newTemp3 = gen->newTemp();   
            gen->AddExpression(newTemp3,suma_entera,"10","*");
            gen->AddExpression(suma_entera,newTemp3,newTemp2,"+");
            gen->AddGoto(jump);

            gen->AddLabel(notEntero);
            std::string newTemp4 = gen->newTemp();   
            std::string newTemp5 = gen->newTemp(); 
            std::string newTemp6 = gen->newTemp();   
            gen->AddExpression(newTemp4,potencia_decimal,"10.0","/");
            gen->AddExpression(newTemp5,newTemp2,newTemp4,"*");
            gen->AddExpression(newTemp6,suma_decimal,newTemp5,"+");
            gen->AddAssign(suma_decimal,newTemp6);
            gen->AddAssign(potencia_decimal,newTemp4);
            gen->AddGoto(jump);

            gen->AddLabel(jump);
            gen->AddExpression(i,i,"1","+");
            gen->AddGoto(loopLvl);

            gen->AddLabel(endLoop);
            std::string valor_float = gen->newTemp();
            gen->AddExpression(valor_float,suma_entera,suma_decimal,"+");
            val = value(valor_float,true,FLOAT);
            return val;
        
        } catch(const std::invalid_argument& e) {
            // Conversion failed: invalid argument
            // report an error
            std::string msg = "invalid argument.";
            tree->addError(msg, Line, Col);
            return value("",false, NULO);

        } catch(const std::out_of_range& e) {
            // Conversion failed: out of range
            // report an error
            std::string msg = "out of range.";
            tree->addError(msg, Line, Col);
            return value("",false, NULO);
        }
            
    }

    else{
        // report an error
        std::string msg = "invalid type. String expected.";
        tree->addError(msg, Line, Col);
        return value("",false, NULO);
    }

}

