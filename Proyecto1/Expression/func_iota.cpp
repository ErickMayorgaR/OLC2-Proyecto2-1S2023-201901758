#include "func_iota.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

func_iota::func_iota(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;

}

value func_iota::ejecutar(environment *env, ast *tree, generator_code *gen)
{   
    value val = Valor->ejecutar(env, tree, gen);
    if(val.Tipo == INTEGER){

        if(!val.FlagTemp){
            std::string tmp = gen->newTemp();
            gen->AddAssign(tmp,val.Value);
            val.Value = tmp;
        }
        //nuevo temporal
        std::string newTemp = gen->newTemp();
        std::string newTemp1 = gen->newTemp();
        std::string newTemp2 = gen->newTemp();
        std::string newTemp3 = gen->newTemp();
        std::string newTemp4 = gen->newTemp();
        std::string newTemp5 = gen->newTemp();

        //igualar a Heap Pointer
        gen->AddAssign(newTemp, "H");
        gen->AddAssign(newTemp2, "0");

        std::string newLabel = gen->newLabel();
        gen->AddLabel(newLabel);
        gen->AddExpression(newTemp1,"(int) " + val.Value,"10","%"); //Obtener el ultimo digito
        gen->AddExpression(val.Value,"(int) " + val.Value,"10","/"); //Eliminar el ultimo digito
        //Convertir el digito a ascii y almacenarlo en el heap
        gen->AddSetHeap("(int) H",newTemp1 + "+ 48");
        gen->AddExpression("H","H","1","+");
        gen->AddExpression(newTemp2,val.Value,"0",">");
        gen->AddIf(newTemp2,"1","==",newLabel);

        gen->AddExpression(newTemp3, "H", "1", "-");
        gen->AddAssign(newTemp4,newTemp);
        std::string whileLabel = gen->newLabel();
        std::string endLabel = gen->newLabel();

        gen->AddLabel(whileLabel);
        gen->AddIf(newTemp3,newTemp4,"<=",endLabel);
        gen->AddGetHeap(newTemp5,"(int) " + newTemp3);
        gen->AddAssign("heap[(int) "+ newTemp3 +"]","heap[(int) "+ newTemp4 +"]");
        gen->AddSetHeap("(int) " + newTemp4,newTemp5);
        gen->AddExpression(newTemp3, newTemp3, "1", "-");
        gen->AddExpression(newTemp4, newTemp4, "1", "+");
        gen->AddGoto(whileLabel);
        gen->AddLabel(endLabel);
        gen->AddComment("Caracter de terminacion de cadena");
        gen->AddSetHeap("(int) H","-1");
        gen->AddExpression("H","H","1","+");
        val = value(newTemp,true,STRING);
        return val;

    }
    else if(val.Tipo == FLOAT){
        std::string val_string;
        if(!val.FlagTemp){
            std::string tmp = gen->newTemp();
            gen->AddAssign(tmp,val.Value);
            float val_int =  std::stof(val.Value) * 1000;
            val_string = std::to_string(val_int);
            val.Value = tmp;
        }
        else{
            val_string = gen->newTemp();
            gen->AddExpression(val_string,val.Value,"1000","*");
        }

        //nuevo temporal
        std::string newTemp = gen->newTemp();
        std::string newTemp1 = gen->newTemp();
        std::string newTemp2 = gen->newTemp();
        std::string newTemp3 = gen->newTemp();
        std::string newTemp4 = gen->newTemp();
        std::string newTemp5 = gen->newTemp();
        std::string newTemp6 = gen->newTemp();
        std::string newTemp7 = gen->newTemp();
        std::string newTemp8 = gen->newTemp();
        std::string newTemp9 = gen->newTemp();

        //igualar a Heap Pointer
        gen->AddAssign(newTemp, "H");
        gen->AddAssign(newTemp2, "0");

        gen->AddComment("Se obtiene el entero");
        gen->AddExpression(newTemp1,"(int) " + val_string,"1000","/"); //Se obtiene el entero
        gen->AddComment("Se obtiene la parte decimal");
        gen->AddExpression(newTemp3,"(int) " + newTemp1,"1000","*");
        gen->AddExpression(newTemp4,"(int) " + val_string,newTemp3,"-"); //Se obtiene la parte decimal

        std::string newLabel = gen->newLabel();
        gen->AddLabel(newLabel);
        gen->AddExpression(newTemp5,"(int) " + newTemp1,"10","%"); //Obtener el ultimo digito
        gen->AddExpression(newTemp1,"(int) " + newTemp1,"10","/"); //Eliminar el ultimo digito
        //Convertir el digito a ascii y almacenarlo en el heap
        gen->AddSetHeap("(int) H",newTemp5 + "+ 48");
        gen->AddExpression("H","H","1","+");
        gen->AddExpression(newTemp2,newTemp1,"0",">");
        gen->AddIf(newTemp2,"1","==",newLabel);

        gen->AddExpression(newTemp6, "H", "1", "-");
        gen->AddAssign(newTemp7,newTemp);
        std::string whileLabel = gen->newLabel();
        std::string endLabel = gen->newLabel();

        gen->AddLabel(whileLabel);
        gen->AddIf(newTemp6,newTemp7,"<=",endLabel);
        gen->AddGetHeap(newTemp8,"(int) " + newTemp6);
        gen->AddAssign("heap[(int) "+ newTemp6 +"]","heap[(int) "+ newTemp7 +"]");
        gen->AddSetHeap("(int) " + newTemp7,newTemp8);
        gen->AddExpression(newTemp6, newTemp6, "1", "-");
        gen->AddExpression(newTemp7, newTemp7, "1", "+");
        gen->AddGoto(whileLabel);
        gen->AddLabel(endLabel);

        gen->AddComment("Agregando el punto decimal");
        gen->AddSetHeap("(int) H", "46"); // Agregar punto decimal (ASCII 46) al heap
        gen->AddExpression("H", "H", "1", "+"); // Incrementar Heap Pointer

        //igualar a Heap Pointer
        gen->AddAssign(newTemp9, "H");
        gen->AddAssign(newTemp2, "0");

        newLabel = gen->newLabel();
        gen->AddLabel(newLabel);
        gen->AddExpression(newTemp5,"(int) " + newTemp4,"10","%"); //Obtener el ultimo digito
        gen->AddExpression(newTemp4,"(int) " + newTemp4,"10","/"); //Eliminar el ultimo digito
        //Convertir el digito a ascii y almacenarlo en el heap
        gen->AddSetHeap("(int) H",newTemp5 + "+ 48");
        gen->AddExpression("H","H","1","+");
        gen->AddExpression(newTemp2,newTemp4,"0",">");
        gen->AddIf(newTemp2,"1","==",newLabel);

        gen->AddExpression(newTemp6, "H", "1", "-");
        gen->AddAssign(newTemp7,newTemp9);
        whileLabel = gen->newLabel();
        endLabel = gen->newLabel();

        gen->AddLabel(whileLabel);
        gen->AddIf(newTemp6,newTemp7,"<=",endLabel);
        gen->AddGetHeap(newTemp8,"(int) " + newTemp6);
        gen->AddAssign("heap[(int) "+ newTemp6 +"]","heap[(int) "+ newTemp7 +"]");
        gen->AddSetHeap("(int) " + newTemp7,newTemp8);
        gen->AddExpression(newTemp6, newTemp6, "1", "-");
        gen->AddExpression(newTemp7, newTemp7, "1", "+");
        gen->AddGoto(whileLabel);
        gen->AddLabel(endLabel);

        gen->AddComment("Caracter de terminacion de cadena");
        gen->AddSetHeap("(int) H","-1");
        gen->AddExpression("H","H","1","+");

        val = value(newTemp,true,STRING);
        return val;

    }


    return val;
}

