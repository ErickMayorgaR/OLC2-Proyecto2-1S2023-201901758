#include "operation.hpp"
#include "Environment/environment.hpp"
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
            int *val1 = (int *)op1.Value;
            int *val2 = (int *)op2.Value;
            int result = *val1 + *val2;
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
            std::string msg = "invalid combination, incorrect type for sum";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for minus";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for multiplication";
            tree->addError(msg,Line,Col);
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
                std::string msg = "can not divide by zero";
                tree->addError(msg,Line,Col);
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
                std::string msg = "can not divide by zero";
                tree->addError(msg,Line,Col);
            }
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for divition";
            tree->addError(msg,Line,Col);
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
                std::string msg = "can not obtain module of zero";
                tree->addError(msg,Line,Col);
            }
        }
         
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for module";
            tree->addError(msg,Line,Col);
        }
    } 
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADOR ++
-----------------------------------------------------------------------------------------------------------------------*/
     else if(Operator == "++A")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            int result = (*val1)++;
            sym = symbol(Line,Col,"",Dominante,&result);  
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            float result = (*val1)++;
            sym = symbol(Line,Col,"",Dominante,&result); 
            
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for inc++";
            tree->addError(msg,Line,Col);
        }
    }  

    else if(Operator == "++B")
    {
        if(Dominante == INTEGER)
        {
            int *val1 = (int *)op1.Value;
            *val1 = (*val1) + 1;
            int result = (*val1);
            sym = symbol(Line,Col,"",Dominante,&result);  
        }
        else if(Dominante == FLOAT)
        {
            float *val1 = (float *)op1.Value;
            *val1 = (*val1) + 1.0;
            float result = (*val1);
            sym = symbol(Line,Col,"",Dominante,&result); 
            
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for ++inc";
            tree->addError(msg,Line,Col);
        }
    }  
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
            std::string msg = "invalid combination, incorrect type for negation";
            tree->addError(msg,Line,Col);
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
                std::string msg = "invalid type, type has to be bool";
                tree->addError(msg,Line,Col);
            }
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid type, type has to be bool";
            tree->addError(msg,Line,Col);
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
                std::string msg = "invalid type, type has to be bool";
                tree->addError(msg,Line,Col);
            }
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid type, type has to be bool";
            tree->addError(msg,Line,Col);
        }
    } 
    else if(Operator == "!")
    {
        if(op1.Tipo == BOOL)
        {
            bool *val1 = (bool *)op1.Value;
            bool result = !(*val1) ;
            sym = symbol(Line,Col,"",BOOL,&result);
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid type, type has to be bool";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for ==";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for !=";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for >";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for <";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for >=";
            tree->addError(msg,Line,Col);
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
            std::string msg = "invalid combination, incorrect type for <=";
            tree->addError(msg,Line,Col);
        }       
    }

    return sym;
}
