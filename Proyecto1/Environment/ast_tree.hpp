#ifndef AST_HPP
#define AST_HPP
#include "Environment/symbol.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <QVector>

class ast
{
public:
    std::string ConsoleOut;
    std::vector<std::string> ErrorTable;
    std::vector<std::string> SymbolTable;
    std::string GraphOut;
    bool ElseIfFlag;
    bool IfReturn;
    QVector<symbol> ListReturn;
    
    ast();
    void addError(const std::string& errorMessage, int line, int column);
    const std::vector<std::string>& getErrorTable();
    void addSymbol(std::string id,std::string tipoSymbol,std::string tipo, std::string data, int line, int column);
    void changeSymbol(std::string msgid, std::string dataAfter);
    const std::vector<std::string>& getSymbolTable();
};

#endif // AST_HPP
