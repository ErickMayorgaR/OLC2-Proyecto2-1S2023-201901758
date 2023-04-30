#include "ast.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <functional>

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

// Función que crea un nuevo nodo del árbol
ast::ASTNode* ast::create_node(std::string type, std::vector<ASTNode*> children) {
    ASTNode* node = new ASTNode();
    node->type = type;
    node->children = children;
    return node;
}

// Función que genera el árbol AST
ast::ASTNode* ast::generate_ast(std::vector<std::string> tokens) {
    // Inicializar el índice del token actual
    int current_token = 0;

    // Función principal para generar el árbol AST
    ASTNode* root = nullptr;
    while (current_token < tokens.size()) {
        std::string token = tokens[current_token];
        if (token == "+"
            || token == "-"
            || token == "*"
            || token == "/"
            || token == "%"
            || token == "^") {
            root = create_arithmetic_expression_node(tokens,current_token);
        } else if (token == "=="
                   || token == "!="
                   || token == "<"
                   || token == ">"
                   || token == "<="
                   || token == ">=") {
            root = create_relational_expression_node(tokens,current_token);
        } else if (token == "&&"
                   || token == "||") {
            root = create_logical_expression_node(tokens,current_token);
        } else if (token == "iota"
                   || token == "atoi"
                   || token == "atof") {
            root = create_function_node(tokens,current_token);
        } else {
            // Es un número o una variable
            root = create_node(token, {});
            current_token++;
        }
    }
    return root;
}

// Función auxiliar para crear un nodo de expresión aritmética
ast::ASTNode* ast::create_arithmetic_expression_node(std::vector<std::string> tokens, int current_token) {
    // Obtener el operador y los operandos
    std::string op = tokens[current_token++];
    ASTNode* left = generate_ast(tokens);
    ASTNode* right = generate_ast(tokens);

    // Crear y devolver el nodo
    return create_node(op, {left, right});
}

// Función auxiliar para crear un nodo de expresión relacional
ast::ASTNode* ast::create_relational_expression_node(std::vector<std::string> tokens, int current_token) {
    // Obtener el operador y los operandos
    std::string op = tokens[current_token++];
    ASTNode* left = generate_ast(tokens);
    ASTNode* right = generate_ast(tokens);

    // Crear y devolver el nodo
    return create_node(op, {left, right});
}

// Función auxiliar para crear un nodo de expresión lógica
ast::ASTNode* ast::create_logical_expression_node(std::vector<std::string> tokens, int current_token) {
    // Obtener el operador y los operandos
    std::string op = tokens[current_token++];
    ASTNode* left = generate_ast(tokens);
    ASTNode* right = generate_ast(tokens);

    // Crear y devolver el nodo
    return create_node(op, {left, right});
}

// Función auxiliar para crear un nodo de función
ast::ASTNode* ast::create_function_node(std::vector<std::string> tokens, int current_token) {
    // Obtener el nombre de la función y los argumentos
    std::string name = tokens[current_token++];
    std::vector<ASTNode*> arguments;
    while (tokens[current_token] != ")") {
        arguments.push_back(generate_ast(tokens));
    }
    current_token++; // Consumir el token de ")"
    
    // Crear y devolver el nodo
    return create_node(name, arguments);
}

void ast::writeToFile() {
        FILE* outfile = fopen("C:\\Users\\mmvg2\\Documents\\PROGRA\\PRY1\\Proyecto1\\Environment\\ast.dot", "w");
    }

// Función que genera el archivo .dot para visualizar el árbol
void ast::generate_dot(ASTNode* node, std::ofstream& dotfile) {
    dotfile << "digraph AST {" << std::endl;
    int node_count = 0;
    // Función anónima recursiva para generar los nodos en el archivo .dot
    std::function<void(ASTNode*)> generate_nodes = [&](ASTNode* node) {
        if (node == nullptr) {
            return;
        }
        // Generar el nodo actual
        dotfile << "node" << node_count << " [label=\"" << node->type << "\"];" << std::endl;
        int parent_count = node_count;
        node_count++;
        // Generar los nodos hijos y las conexiones entre ellos
        for (ASTNode* child : node->children) {
            generate_nodes(child);
            dotfile << "node" << parent_count << " -> node" << node_count << ";" << std::endl;
            node_count++;
        }
    };
    generate_nodes(node);
    dotfile << "}" << std::endl;
}




