#include "ast.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

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
                int count3 = 30-data.length();
                data.append(count3, ' ');

                std::string msgSymbol = id + tipoSymbol +tipo + " "+ data +std::to_string(line) + "       " + std::to_string(column);
                SymbolTable.push_back(msgSymbol);
            }
const std::vector<std::string>& ast::getSymbolTable(){
    return SymbolTable;
}

void ast::changeSymbol(std::string msgId, std::string dataAfter) {
                int count = 30-dataAfter.length();
                dataAfter.append(count, ' ');
                int elemIndex = -1;

                for (int i = 0; i < SymbolTable.size() && elemIndex == -1; i++) {
                    
                    if (SymbolTable[i].find(msgId) != std::string::npos) { // check if target substring is found in current element
                        elemIndex = i;

                    }
                }
               
                if (elemIndex != -1) {
                    int charIndex = 42;
                    SymbolTable[elemIndex].erase(charIndex+1, dataAfter.length());
                    SymbolTable[elemIndex].insert(charIndex+1, dataAfter);
                }
                
                
            }

void ast::addNode(std::string parent, std::string label,std::vector<std::string> values)
{
    if(label == "Instruccion"){
        if((nodeCount-3) == (nodeTemp2)){
            nodeTemp2 = nodeTemp2 + 3;
            nodeCount++;
            return;}
        else{
        nodeTemp = nodeCount;
        nodeTemp2 = nodeTemp;
        }
    }
    // Create a new node with a unique name
    nodeName = "node" + std::to_string(nodeCount++);
    // Add the node to the graph
    std::string nodeString = nodeName + " [label=\"" + label + "\"];\n";
    dot += nodeString;

    if(nodeCount == 3){
        dot += "node1 -> node2;\n";
    }
    // Add edges to the parent node
    if (parent != "") {
        std::string edgeString = "";
        for (const auto& value : values) {
            edgeString += nodeName + " -> " + value + ";\n";
        }
        dot += edgeString;
    }
}

void ast::ConnectChild(std::string parent){
        dot += parent + " -> " + nodeName + ";\n";
}

void ast::ConnectNode(){
        std::string nodeBefore = "node" + std::to_string(nodeTemp);
        dot += nodeBefore + " -> " + nodeName + ";\n";
}

void ast::writeToFile() {
        FILE* outfile = fopen("C:\\Users\\mmvg2\\Documents\\PROGRA\\PRY1\\Proyecto1\\Environment\\ast.dot", "w");
        dot += "\n}";
        fprintf(outfile, "%s", dot.c_str());
        fclose(outfile);
    }
