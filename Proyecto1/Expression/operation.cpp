#include "operation.hpp"
#include <string>

operation::operation(int line, int col, expression *op_izq, expression *op_der, std::string operador){
    Line = line;
    Col = col;
    Op_izq = op_izq;
    Op_der = op_der;
    Operator = operador;
}

value operation::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    value val ("",false,NULO);

    //matriz dominante: esta matriz retorna el tipo dominante entre dos operandos
    TipoDato Matrz[4][4] = {
        {INTEGER, FLOAT, STRING, INTEGER},
        {FLOAT, FLOAT, STRING, FLOAT},
        {STRING, STRING, STRING, STRING},
        {INTEGER, FLOAT, STRING, INTEGER}
    };

    std::string newTemp = gen->newTemp();
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADORES ALGEBRAICOS
-----------------------------------------------------------------------------------------------------------------------*/
    if(Operator == "+")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            val = value(newTemp, true, Dominante);
            return val;
        }
        else if(Dominante == STRING){
            gen->AddExpression(newTemp,op1.Value,op2.Value,"+");
            val = value(newTemp, true, Dominante);
            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER || Dominante == FLOAT)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"-");
            val = value(newTemp, true, Dominante);

            if(tree->InsideRemove){
                int val_op1 = std::stoi(op1.Value);
                int val_op2 = std::stoi(op2.Value);
                int result = val_op1 - val_op2;
                tree->Index = std::to_string(result);
            }
            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            gen->AddExpression(newTemp,op1.Value,op2.Value,"*");
            val = value(newTemp, true, Dominante);
            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            if(op2.Value != "0")
            {
                gen->AddExpression(newTemp,op1.Value,op2.Value,"/");
                val = value(newTemp, true, Dominante);
                return val;
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
    else if (Operator == "%")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];

        if (Dominante == INTEGER)
        {
            if (op1.FlagTemp)
            {
                std::string newTempInt = gen->newTempInt();
                std::string TargetInt = gen->newTempInt();
                gen->AddFloat2Int(op1.Value,newTempInt);
                if (op2.Value != "0")
                {
                    gen->AddExpression(TargetInt, newTempInt, op2.Value, "%");
                    val = value(TargetInt, true, Dominante);
                    return val;
                }
                else
                {
                    // Se reporta un error
                    std::string msg = "can not obtain module of zero";
                    tree->addError(msg, Line, Col);
                }
            }
            else
            {
                gen->AddExpression(newTemp, op1.Value, op2.Value, "%");
                val = value(newTemp, true, Dominante);
                return val;
            }
        }
        else
        {
            // Se reporta un error
            std::string msg = "invalid combination, incorrect type for module";
            tree->addError(msg, Line, Col);
        }
    }
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADOR ++
-----------------------------------------------------------------------------------------------------------------------*/
     else if(Operator == "++")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        
        if(Dominante == INTEGER || Dominante == FLOAT)
        {
            gen->AddExpression(newTemp,op1.Value,"1","+");
            val = value(newTemp, true, Dominante); 
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for inc++";
            tree->addError(msg,Line,Col);
        }
    }  
/*-----------------------------------------------------------------------------------------------------------------------
                                          OPERADORES LOGICOS
-----------------------------------------------------------------------------------------------------------------------*/
else if(Operator == "&&")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas verdaderas de op1
        for(int i=0; i < op1.TrueLabel.size(); i++)
        {
            gen->AddLabel(op1.TrueLabel[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLabel += op2.TrueLabel;
        val.FalseLabel += op1.FalseLabel;
        val.FalseLabel += op2.FalseLabel;

        return val;
    }
    else if(Operator == "||")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        //se agregan etiquetas falsas de op1
        for(int i=0; i < op1.FalseLabel.size(); i++)
        {
            gen->AddLabel(op1.FalseLabel[i]);
        }
        value op2 = Op_der->ejecutar(env, tree, gen);

        val = value("", false, BOOL);

        val.TrueLabel += op1.TrueLabel;
        val.TrueLabel += op2.TrueLabel;
        val.FalseLabel += op2.FalseLabel;
        return val;
    }
    else if(Operator == "!")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        if(op1.Tipo == BOOL)
        {
            val = value("", false, BOOL);
            val.TrueLabel += op1.FalseLabel;
            val.FalseLabel += op1.TrueLabel;
            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER || Dominante == FLOAT)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "==", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "!=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
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
    else if(Operator == "<")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for <";
            tree->addError(msg,Line,Col);
        }
    }
    else if(Operator == ">")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for >";
            tree->addError(msg,Line,Col);
        }
    }
    else if(Operator == ">=")
    {
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, ">=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
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
        value op1 = Op_izq->ejecutar(env, tree, gen);
        value op2 = Op_der->ejecutar(env, tree, gen);
        TipoDato Dominante = Matrz[op1.Tipo][op2.Tipo];
        if(Dominante == INTEGER)
        {
            std::string trueLabel = gen->newLabel();
            std::string falseLabel = gen->newLabel();

            gen->AddIf(op1.Value,op2.Value, "<=", trueLabel);
            gen->AddGoto(falseLabel);

            val = value("", false, BOOL);

            val.TrueLabel.append(trueLabel);
            val.FalseLabel.append(falseLabel);

            return val;
        }
        else
        {
            //se reporta un error
            std::string msg = "invalid combination, incorrect type for <=";
            tree->addError(msg,Line,Col);
        }
    }    
    return val;
}
