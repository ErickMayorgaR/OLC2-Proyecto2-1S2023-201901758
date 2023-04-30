#include "print.hpp"

print::print(int line, int col, list_expression *valor)
{
    this->Line = line;
    this->Col = col;
    this->Valor = valor;
}

void print::ejecutar(environment *env, ast *tree, generator_code *gen)
{
    for(int i = 0; i < Valor->ListExp.size();i++){
        value result = Valor->ListExp[i]->ejecutar(env, tree, gen);

        if(result.Tipo == INTEGER)
        {
            gen->AddPrintf("d", "(int)"+ result.Value);
            
        }
        else if(result.Tipo == FLOAT)
        {
            gen->AddPrintf("f", "(float)"+ result.Value);
        }
        else if(result.Tipo == STRING)
        {
            //llamar a generar printstring
            gen->GeneratePrintString();
            //agregar codigo en el main
            std::string NewTemp1 = gen->newTemp();
            std::string NewTemp2 = gen->newTemp();
            int size = env->Size;
            gen->AddComment("nuevo temporal en pos vacia");
            gen->AddExpression(NewTemp1, "P", std::to_string(size), "+");
            gen->AddComment("se deja espacio de retorno");
            gen->AddExpression(NewTemp1, NewTemp1, "1", "+");
            gen->AddComment("se coloca string en parametro que se manda");
            gen->AddSetStack("(int)"+ NewTemp1, result.Value);
            gen->AddComment("cambio de entorno");
            gen->AddExpression("P", "P", std::to_string(size), "+");
            gen->AddComment("Llamada");
            gen->AddCall("printString");
            gen->AddComment("obtencion retorno");
            gen->AddGetStack(NewTemp2, "(int)P");
            gen->AddComment("regreso del entorno");
            gen->AddExpression("P", "P", std::to_string(size), "-");
        }
        else if(result.Tipo == BOOL)
        {
            std::string newLabel = gen->newLabel();
            std::string newFalseLabel = gen->newLabel();
            if(result.FlagTemp)
            {
                gen->AddIf(result.Value, "1", "!=", newFalseLabel);
            }
            //add true labels
            for(int i=0; i < result.TrueLabel.size(); i++)
            {
                gen->AddLabel(result.TrueLabel[i]);
            }
            gen->AddPrintf("c", "(char)116");
            gen->AddPrintf("c", "(char)114");
            gen->AddPrintf("c", "(char)117");
            gen->AddPrintf("c", "(char)101");
            gen->AddGoto(newLabel);
            //add false labels
            for(int j=0; j < result.FalseLabel.size(); j++)
            {
                gen->AddLabel(result.FalseLabel[j]);
            }
            gen->AddLabel(newFalseLabel);
            gen->AddPrintf("c", "(char)102");
            gen->AddPrintf("c", "(char)97");
            gen->AddPrintf("c", "(char)108");
            gen->AddPrintf("c", "(char)115");
            gen->AddPrintf("c", "(char)101");
            gen->AddLabel(newLabel);
        }
        else if(result.Tipo == NULO)
        {
            gen->AddPrintf("c", "(char)78");
            gen->AddPrintf("c", "(char)85");
            gen->AddPrintf("c", "(char)76");
            gen->AddPrintf("c", "(char)76");
            gen->AddPrintf("c", "10");
            gen->AddEnter();
        }
        else if(result.Tipo == VECTOR){
            int num = tree->VectorSize;

            std::string i = gen->newTempInt();
            std::string n = gen->newTempInt();
            std::string newTemp = gen->newTemp();
            
            gen->AddAssign(i,"0");
            gen->AddAssign(n,std::to_string(num));
            gen->AddExpression(newTemp,n,"1","-");
            gen->AddPrintf("c","91");

            std::string start_for = gen->newLabel();
            std::string end_for = gen->newLabel();

            gen->AddLabel(start_for);
            gen->AddIf(i,n,">=",end_for);
            gen->AddPrintf("d",result.Value + "[(int) " + i + "]");

            gen->AddIf(i,newTemp,">=",end_for);
            gen->AddPrintf("c","44");
            gen->AddExpression(i,i,"1","+");
            gen->AddGoto(start_for);
            gen->AddLabel(end_for);
            gen->AddPrintf("c","93");
        }
    }
    gen->AddPrintf("c", "10");
    gen->AddEnter();
}

//std::string print::ArrayToString(QVector<symbol> Array)
//{
//    std::string strBuffer = "[";
//    int contIndex = 0;
//    for(int i=0; i < Array.size(); ++i){
//        contIndex++;
//        if(Array[i].Tipo == ARRAY)
//        {
//            if(contIndex < Array.size())
//            {
//                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value)) + ",";
//            }
//            else
//            {
//                strBuffer += ArrayToString(*static_cast<QVector<symbol>*>(Array[i].Value));
//            }

//        }
//        else
//        {
//            if(Array[i].Tipo == STRING)
//            {
//                if(contIndex < Array.size())
//                {
//                    strBuffer += *static_cast<std::string*>(Array[i].Value) + ",";
//                }
//                else
//                {
//                    strBuffer += *static_cast<std::string*>(Array[i].Value);
//                }

//            }
//            else if(Array[i].Tipo == INTEGER)
//            {
//                if(contIndex < Array.size())
//                {
//                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value)) + ",";
//                }
//                else
//                {
//                    strBuffer += std::to_string(*static_cast<int*>(Array[i].Value));
//                }

//            }
//            else if(Array[i].Tipo == BOOL)
//            {
//                if(contIndex < Array.size())
//                {
//                    if(*static_cast<bool*>(Array[i].Value))
//                    {
//                        strBuffer += "true,";
//                    }
//                    else
//                    {
//                        strBuffer += "false,";
//                    }
//                }
//                else
//                {
//                    if(*static_cast<bool*>(Array[i].Value))
//                    {
//                        strBuffer += "true";
//                    }
//                    else
//                    {
//                        strBuffer += "false";
//                    }
//                }

//            }
//        }
//    }
//    strBuffer += "]\n";
//    return strBuffer;
//}





