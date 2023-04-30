#include "generator_code.hpp"
#include <iostream>

generator_code::generator_code()
{
    ContTemp = 1;
    ContLabel = 1;
    MainCode = QVector<std::string>();
    FuncCode = QVector<std::string>();
    ListTemp = QVector<std::string>();
    Natives = QVector<std::string>();
    Main_Code = false;
    PrintStringFlag = true;
    OutputCode = "";
}
// Generar un nuevo temporal
std::string generator_code::newTemp()
{
    std::string temp = "t"+std::to_string(ContTemp);
    ContTemp += 1;
    ListTemp.push_back(temp);
    return temp;
}

std::string generator_code::newTempInt()
{
    std::string temp = "t"+std::to_string(ContTemp);
    ContTemp += 1;
    ListTempInt.push_back(temp);
    return temp;
}

std::string generator_code::newTempChar(int num)
{
    std::string temp = "t"+std::to_string(ContTemp);
    ContTemp += 1;
    ListTempChar.push_back(temp);
    ListTempNum.push_back(std::to_string(num));
    return temp;
}

std::string generator_code::newTempStack(int num)
{
    std::string temp = "t"+std::to_string(ContTemp);
    ContTemp += 1;
    ListTempStack.push_back(temp);
    ListTempNumStack.push_back(std::to_string(num));
    return temp;
}

// Genera una nueva etiqueta
std::string generator_code::newLabel()
{
    int temp = ContLabel;
    ContLabel += 1;
    return "L"+std::to_string(temp);
}
// Agregando una instruccion if
void generator_code::AddIf(std::string left, std::string right, std::string op, std::string label)
{
    if(Main_Code)
    {
        MainCode.append("if(" + left + " " + op + " " + right + ") goto " + label + ";\n");
    }
    else
    {
        FuncCode.append("if(" + left + " " + op + " " + right + ") goto " + label + ";\n");
    }
}

// Agregando un salto
void generator_code::AddGoto(std::string label )
{
    if(Main_Code)
    {
        MainCode.append("goto " + label + ";\n");
    }
    else
    {
        FuncCode.append("goto " + label + ";\n");
    }

}

// Agregando una expresion
void generator_code::AddExpression(std::string target, std::string left, std::string right, std::string op)
{
    if(Main_Code)
    {
        MainCode.append(target + " = " + left + " " + op + " " + right + ";\n");
    }
    else
    {
        FuncCode.append(target + " = " + left + " " + op + " " + right + ";\n");
    }

}

// Agregando una etiqueta
void generator_code::AddLabel(std::string label)
{
    if(Main_Code)
    {
        MainCode.append(label + ":\n");
    }
    else
    {
        FuncCode.append(label + ":\n");
    }

}

// Agregando una asignacion
void generator_code::AddAssign(std::string target, std::string val)
{
    if(Main_Code)
    {
        MainCode.append(target + " = " + val + ";\n");
    }
    else
    {
        FuncCode.append(target + " = " + val + ";\n");
    }

}

// Agregando un comentario
void generator_code::AddComment(std::string val)
{
    if(Main_Code)
    {
        MainCode.append("// "+val+"\n");
    }
    else
    {
        FuncCode.append("// "+val+"\n");
    }

}

// Agregando una llamada
void generator_code::AddCall(std::string target)
{
    if(Main_Code)
    {
        MainCode.append(target+"();\n");
    }
    else
    {
        FuncCode.append(target+"();\n");
    }
}

//set heap
void generator_code::AddSetHeap(std::string index, std::string value) {
    if (Main_Code)
    {
        MainCode.append("heap[" + index + "] = " + value + ";\n");
    }
    else
    {
        FuncCode.append("heap[" + index + "] = " + value + ";\n");
    }
}

//set heap
void generator_code::AddSetStack(std::string index, std::string value) {
    if (Main_Code)
    {
        MainCode.append("stack[" + index + "] = " + value + ";\n");
    }
    else
    {
        FuncCode.append("stack[" + index + "] = " + value + ";\n");
    }
}

//get heap
void generator_code::AddGetHeap(std::string target, std::string index) {
    if (Main_Code)
    {
        MainCode.append(target + " = heap[" + index + "];\n");
    }
    else
    {
        FuncCode.append(target + " = heap[" + index + "];\n");
    }
}

//get stack
void generator_code::AddGetStack(std::string target, std::string index) {
    if (Main_Code)
    {
        MainCode.append(target + " = stack[" + index + "];\n");
    }
    else
    {
        FuncCode.append(target + " = stack[" + index + "];\n");
    }
}

//agrega un salto de linea
void generator_code::AddEnter()
{
    if (Main_Code)
    {
        MainCode.append("\n");
    }
    else
    {
        FuncCode.append("\n");
    }
}

//agrega un printf
void  generator_code::AddPrintf(std::string typePrint, std::string value)
{
    if (Main_Code)
    {
        MainCode.append("printf(\"%" + typePrint + "\", " + value + ");\n");
    }
    else
    {
        FuncCode.append("printf(\"%" + typePrint + "\", " + value + ");\n");
    }
}

//Cambio de float a int
void  generator_code::AddFloat2Int(std::string tempFloat, std::string tempInt)
{
    if (Main_Code)
    {
        MainCode.append(tempInt + " = " + "(int) " + tempFloat +";\n");
    }
    else
    {
        FuncCode.append(tempInt + " = " + "(int) " + tempFloat +";\n");
    }
}

void generator_code::GeneratePrintString()
{
    if (PrintStringFlag)
    {
        //generando temporales y etiquetas
        std::string newTemp1 = newTemp();
        std::string newTemp2 = newTemp();
        std::string newTemp3 = newTemp();
        std::string newLvl1 = newLabel();
        std::string newLvl2 = newLabel();
        //se genera la funcion printstring
        Natives.append("void printString() {\n");
        Natives.append("\t" + newTemp1 + " = P + 1;\n");
        Natives.append("\t" + newTemp2 + " = stack[(int)" + newTemp1 + "];\n");
        Natives.append("\t" + newLvl2 + ":\n");
        Natives.append("\t" + newTemp3 + " = heap[(int)" + newTemp2 + "];\n");
        Natives.append("\tif(" + newTemp3 + " == -1) goto " + newLvl1 + ";\n");
        Natives.append("\tprintf(\"%c\", (char)" + newTemp3 + ");\n");
        Natives.append("\t" + newTemp2 + " = " + newTemp2 + " + 1;\n");
        Natives.append("\tgoto " + newLvl2 + ";\n");
        Natives.append("\t" + newLvl1 + ":\n");
        Natives.append("\treturn;\n");
        Natives.append("}\n\n");
        PrintStringFlag = false;
    }
}

//agregar headers
void generator_code::GenerateFinalCode()
{
    //creando cabecera
    OutputCode += "#include <stdio.h>\n";
    OutputCode += "float stack[100000];\n";
    OutputCode += "float heap[100000];\n";
    OutputCode += "float P;\n";
    OutputCode += "float H;\n";
    //Temporales
    if(!ListTemp.isEmpty()){
        std::string tmpDec = "float "+ListTemp[0];
        for(int i=1; i< ListTemp.size(); i++){
            tmpDec += ", "+ListTemp[i];
        }
        tmpDec += ";\n";
        OutputCode += tmpDec;
    }

    if(!ListTempInt.isEmpty()){
        std::string tmpDec = "int "+ListTempInt[0];
        for(int i=1; i< ListTempInt.size(); i++){
            tmpDec += ", "+ListTempInt[i];
        }
        tmpDec += ";\n";
        OutputCode += tmpDec;
    }

    if(!ListTempChar.isEmpty()){
        std::string tmpDec = "char "+ListTempChar[0] + "[" + ListTempNum[0] + " * sizeof(int)]";
        for(int i=1; i< ListTempChar.size(); i++){
            tmpDec += ", "+ListTempChar[i] + "[" + ListTempNum[i] + " * sizeof(int)]";
        }
        tmpDec += ";\n";
        OutputCode += tmpDec;
    }

    if(!ListTempStack.isEmpty()){
        std::string tmpDec = "int "+ListTempStack[0] + "[" + ListTempNumStack[0] + "]";
        for(int i=1; i< ListTempStack.size(); i++){
            tmpDec += ", "+ListTempStack[i] + "[" + ListTempNumStack[i] + "]";
        }
        tmpDec += ";\n";
        OutputCode += tmpDec;
    }
    
    OutputCode += "\n";
    //Funciones
    for(int i=0; i<FuncCode.size(); i++){
        OutputCode += FuncCode[i];
    }
    //Print String
    for(int i=0; i<Natives.size(); i++){
        OutputCode += Natives[i];
    }
    //Main
    OutputCode += "int main()\n{\n";
    for(int i=0; i<MainCode.size(); i++){
        OutputCode += "\t";
        OutputCode += MainCode[i];
    }
    OutputCode += "\treturn 0;\n}";
}
