#include "ast.hpp"
#include <iostream>
#include <iomanip>

ast::ast()
{
    ListReturn = QVector<symbol>();
}

void ast::addError(const std::string& errorMessage, int line, int column) {
                std::string error = "Semantic error at line " + std::to_string(line) +
                                     ", column " + std::to_string(column) +
                                     ": " + errorMessage;
                ErrorTable.push_back(error);
            }
const std::vector<std::string>& ast::getErrorTable(){
    return ErrorTable;
}

void ast::addSymbol(std::string id,std::string tipoSymbol,std::string tipo, std::string data, int line, int column) {
                int count = 14-id.length();
                id.append(count, ' ');
                int count1 = 14-tipoSymbol.length();
                tipoSymbol.append(count1, ' ');
                int count2 = 14-tipo.length();
                tipo.append(count2, ' ');
                int count3 = 14-data.length();
                data.append(count3, ' ');

                std::string msgSymbol = id + tipoSymbol +tipo + " "+ data +std::to_string(line) + "       " + std::to_string(column);
                SymbolTable.push_back(msgSymbol);
            }
const std::vector<std::string>& ast::getSymbolTable(){
    return SymbolTable;
}

void ast::changeSymbol(std::string msgId, std::string dataAfter) {
                int count = 14-dataAfter.length();
                dataAfter.append(count, ' ');

                int elemIndex = -1;

                for (int i = 0; i < SymbolTable.size() && elemIndex == -1; i++) {
                    
                    if (SymbolTable[i].find(msgId) != std::string::npos) { // check if target substring is found in current element
                        elemIndex = i;

                    }
                }
               
                int charIndex = 41;
                for (int i = charIndex; i < 55; i++) {
                    SymbolTable[elemIndex][i+1] = dataAfter[i - charIndex];
                }
                
                
            }