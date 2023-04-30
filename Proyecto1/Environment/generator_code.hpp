#ifndef GENERATOR_HPP
#define GENERATOR_HPP
#include "QVector"

class generator_code
{
public:
    int ContTemp;
    int ContLabel;
    QVector<std::string> MainCode;
    QVector<std::string> FuncCode;
    QVector<std::string> Natives;
    QVector<std::string> ListTemp;
    QVector<std::string> ListTempInt;
    QVector<std::string> ListTempStack;
    QVector<std::string> ListTempChar;
    QVector<std::string> ListTempNum;
    QVector<std::string> ListTempNumStack;
    bool Main_Code;
    bool PrintStringFlag;
    std::string OutputCode;

    generator_code();
    std::string newTemp();
    std::string newTempInt();
    std::string newTempChar(int num);
    std::string newTempStack(int num);
    std::string newLabel();
    void AddIf(std::string left, std::string right, std::string op, std::string label);
    void AddGoto(std::string label);
    void AddLabel(std::string label);
    void AddExpression(std::string target, std::string left, std::string right, std::string op);
    void AddAssign(std::string target, std::string val);
    void AddComment(std::string val);
    void AddCall(std::string target);
    void AddSetHeap(std::string index, std::string value);
    void AddSetStack(std::string index, std::string value);
    void AddGetHeap(std::string target, std::string index);
    void AddGetStack(std::string index, std::string target);
    void AddEnter();
    void AddPrintf(std::string typePrint, std::string value);
    void AddFloat2Int(std::string tempFloat, std::string tempInt);
    void GeneratePrintString();
    void GenerateFinalCode();

};

#endif // GENERATOR_HPP
