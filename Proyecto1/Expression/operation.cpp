#include "operation.hpp"

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

symbol operation::ejecutar(environment *env, ast *tree)
{
    symbol sym (Line,Col,"",NULO,nullptr);
    symbol op1 = Op_izq->ejecutar(env, tree);
    symbol op2 = Op_der->ejecutar(env, tree);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[4][4] = {
        {INTEGER, FLOAT, STRING, INTEGER},
        {FLOAT, FLOAT, STRING, FLOAT},
        {STRING, STRING, STRING, STRING},
        {INTEGER, FLOAT, STRING, INTEGER}
    };

    TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADORES ALGEBRAICOS
-----------------------------------------------------------------------------------------------------------------------*/
    if(Operator == "+")
    {
        if(Dominante == INTEGER)
        {
            int result = *static_cast<int*>(op1.Value) + *static_cast<int*>(op2.Value);
            sym = symbol(Line,Col,"",Dominante,&result);
        }

        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            std::string result = *val1 + *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }

        else if(Dominante == FLOAT){
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            float result = *val1 + *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    }
    else if(Operator == "-")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 - *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            float result = *val1 - *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto para resta\n";
        }
    }
    else if(Operator == "*")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 * *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            float result = *val1 * *val2;
            sym = symbol(Line,Col,"",Dominante,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    }
    else if(Operator == "/")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            if(*val2 != 0)
            {
                int result = *val1 / *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: no se puede dividir entre cero\n";
            }
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            if(*val2 != 0)
            {
                float result = *val1 / *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: no se puede dividir entre cero\n";
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    }
     else if(Operator == "%")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            if(*val2 != 0)
            {
                int result = *val1 % *val2;
                sym = symbol(Line,Col,"",Dominante,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: no se puede realizar el modulo entre cero\n";
            }
        }
         
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    } 
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADOR ++
-----------------------------------------------------------------------------------------------------------------------*/
/*     else if(Operator == "++")
    {
        if(Dominante == INTEGER)
        {
            if(op1.Tipo != 0){
                sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",op1.NumVal++,0.0,false);
            } 
            else{
                sym = *new symbol(this->Line,this->Col,"",op2.Tipo,"",op2.NumVal++,0.0,false);
            }  
        }
        else if(Dominante == FLOAT)
        {
            if(op1.Tipo != 0){
                sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",0,op1.FloatVal++,false);
            }
            else{
                sym = *new symbol(this->Line,this->Col,"",op1.Tipo,"",0,op1.FloatVal++,false);  
            }
            
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto";
        }
    }  */
/*-----------------------------------------------------------------------------------------------------------------------
                                          NEGACION UNARIA
-----------------------------------------------------------------------------------------------------------------------*/
    else if(Operator == "NEG")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int result = -(*val1);
            sym = symbol(Line,Col,"",Dominante,&result);  
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float result = -(*val1);
            sym = symbol(Line,Col,"",Dominante,&result); 
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool result = -(*val1);
            sym = symbol(Line,Col,"",Dominante,&result); 
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto\n";
        }
    } 
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADORES LOGICOS
-----------------------------------------------------------------------------------------------------------------------*/

    else if(Operator == "&&")
    {
        if(op1.Tipo == BOOL)
        {
            if(op2.Tipo == BOOL){
                bool *val1 = (bool *)op1.Value;
                bool *val2 = (bool *)op2.Value;
                bool result = *val1 && *val2;
                sym = symbol(Line,Col,"",BOOL,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: tipo incorrecto, solo se acepta tipo bool\n";
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto, solo se acepta tipo bool\n";
        }
    } 
    else if(Operator == "||")
    {
        if(op1.Tipo == BOOL)
        {
            if(op2.Tipo == BOOL){
                bool *val1 = (bool *)op1.Value;
                bool *val2 = (bool *)op2.Value;
                bool result = *val1 || *val2;
                sym = symbol(Line,Col,"",BOOL,&result);
            }
            else
            {
                //se reporta un error
                tree->ErrorOut += "Error: tipo incorrecto, solo se acepta tipo bool\n";
            }
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto, solo se aceptan tipo bool\n";
        }
    } 
    else if(Operator == "!")
    {
        if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool result = !(*val1) ;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: tipo incorrecto\n";
        }
    } 
/*-----------------------------------------------------------------------------------------------------------------------
                                OPERADORES DE COMPARACION - IGUALDAD Y DESIGUALDAD
-----------------------------------------------------------------------------------------------------------------------*/
    else if(Operator == "==")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 == *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    }
    else if(Operator == "!=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == STRING)
        {
            std::string *val1 = (std::string *)op1.Value;
            std::string *val2 = (std::string *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 != *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto\n";
        }
    }
/*-----------------------------------------------------------------------------------------------------------------------
                                OPERADORES DE COMPARACION - RELACIONALES
-----------------------------------------------------------------------------------------------------------------------*/
    else if(Operator == ">")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 > *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 > *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 > *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }       
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto";
        }     
    }
    else if(Operator == "<")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 < *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 < *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 < *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }       
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto";
        }      
    }
    else if(Operator == ">=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 >= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 >= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 >= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }       
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto";
        }        
    }
    else if(Operator == "<=")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 <= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float *val2 = (float *)op2.Value;
            int result = *val1 <= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else if(Dominante == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool *val2 = (bool *)op2.Value;
            int result = *val1 <= *val2;
            sym = symbol(Line,Col,"",BOOL,&result);
        }       
        else
        {
            //se reporta un error
            tree->ErrorOut += "Error: combinacion invalida, tipo incorrecto";
        }       
    }
    return sym;
}
