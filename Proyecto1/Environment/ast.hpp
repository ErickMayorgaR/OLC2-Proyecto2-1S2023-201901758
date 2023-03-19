#ifndef AST_HPP
#define AST_HPP
#include "symbol.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <QVector>
#include <map>
using std::map;

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
    map<std::string, std::string> nodes;
    int nodeCount = 2;
    std::string nodeName;
    int nodeTemp = 2;
    int nodeTemp2;
    std::string dot =
                std::string("digraph G {\n") +
                +"graph[bgcolor=\"#141D26\" margin=0]\n" +
                +"node [shape=box style=filled color=\"#48D1CC\" fontname= \"Ubuntu\" fontsize=\"14\"];\n" +
                +"edge[color=\"#B22222\" penwidth=\"1.5\"];node1[label = \"Main\"];\n\n" +
                + "Raiz->node1;\n";

    ast();
    void addError(const std::string& errorMessage, int line, int column);
    const std::vector<std::string>& getErrorTable();
    void addSymbol(std::string id,std::string tipoSymbol,std::string tipo, std::string data, int line, int column);
    void changeSymbol(std::string msgid, std::string dataAfter);
    const std::vector<std::string>& getSymbolTable();
    void addNode(std::string parent, std::string label, std::vector<std::string> values);
    void ConnectChild(std::string parent);
    void ConnectNode();
    void writeToFile();
   // ASTNode* new_node(int type, int value, char* name, ASTNode* left, ASTNode* right);
  //  void delete_node(ASTNode* node);
   // void generate_dot(ASTNode* node, std::ostream& out);
};

#endif // AST_HPP
