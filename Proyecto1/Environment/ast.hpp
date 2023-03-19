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
    struct ASTNode {
    std::string type;               // tipo de nodo
    std::vector<ASTNode*> children; // lista de hijos
    };

    std::string ConsoleOut;
    std::vector<std::string> ErrorTable;
    std::vector<std::string> SymbolTable;
    std::string GraphOut;
    bool ElseIfFlag = false;
    bool IfReturn = false;
    QVector<symbol> ListReturn;
    map<std::string, std::string> nodes;
    int nodeCount = 2;
    std::string nodeName;
    int nodeTemp = 2;
    int nodeTemp2;
    /* std::string dot =
                std::string("digraph G {\n") +
                +"graph[bgcolor=\"#141D26\" margin=0]\n" +
                +"node [shape=box style=filled color=\"#48D1CC\" fontname= \"Ubuntu\" fontsize=\"14\"];\n" +
                +"edge[color=\"#B22222\" penwidth=\"1.5\"];node1[label = \"Main\"];\n\n" +
                + "Raiz->node1;\n"; */

    ast();
    void addError(const std::string& errorMessage, int line, int column);
    const std::vector<std::string>& getErrorTable();
    void addSymbol(std::string id,std::string tipoSymbol,std::string tipo, std::string data, int line, int column);
    void changeSymbol(std::string msgid, std::string dataAfter);
    const std::vector<std::string>& getSymbolTable();

    ASTNode* create_node(std::string type, std::vector<ASTNode*> children);
    ASTNode* generate_ast(std::vector<std::string> tokens);
    void generate_dot(ASTNode* node, std::ofstream& dotfile);
    ASTNode* create_relational_expression_node(std::vector<std::string> tokens, int current_token);
    ASTNode* create_arithmetic_expression_node(std::vector<std::string> tokens, int current_token);
    ASTNode* create_logical_expression_node(std::vector<std::string> tokens, int current_token);
    ASTNode* create_function_node(std::vector<std::string> tokens, int current_token);
    void writeToFile();
};

#endif // AST_HPP
