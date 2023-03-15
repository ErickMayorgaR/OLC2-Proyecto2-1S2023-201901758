#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP
#include <map>
#include "Environment/ast.hpp"
#include "Environment/func_symbol.hpp"
#include "Environment/symbol.hpp"
using std::map;

class environment
{
public:
    environment *Anterior;
    map<std::string, symbol> Tabla;
    map<std::string, map<std::string, TipoDato>> TablaStructs;
    map<std::string, func_symbol> TablaFunctions;
    std::string Id;
    int Line;
    int Col;
    bool Inside_While = false;
    bool Inside_For = false;
    bool Break_flag = false;
    bool Continue_flag = false;

    environment(environment *anterior, std::string id);
    void SaveVariable(symbol sym, std::string id, ast *tree);
    void AssignVariable(symbol sym, std::string id, ast *tree);
    void SaveStruct(int line, int col, map<std::string, TipoDato> tabla, std::string id, ast *tree);
    void SaveFunction(func_symbol sym, std::string id, ast *tree);
    symbol GetVariable(int rline, int rcol, std::string id, environment *env, ast *tree);
    map<std::string, TipoDato> GetStruct(std::string id, environment *env, ast *tree);
    func_symbol GetFunction(std::string id, environment *env, ast *tree);
};

#endif // ENVIRONMENT_HPP
