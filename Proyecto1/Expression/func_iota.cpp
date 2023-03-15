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

symbol func_iota::ejecutar(environment *env, ast *tree)
{   
    symbol sym2 = Valor->ejecutar(env, tree);
    if(sym2.Tipo == INTEGER)
    {
        int *val1 = (int *)sym2.Value;
        std::string result = std::to_string(*val1);
        std::string *result_ptr = new std::string(result);
        return symbol(Line, Col, "", STRING, result_ptr);    
    }
    else if(sym2.Tipo == FLOAT)
    {
        float *val1 = (float *)sym2.Value;
        std::ostringstream stream;
        stream << std::fixed << std::setprecision(5) << (*val1);
        std::string result = stream.str();
        std::string *result_ptr = new std::string(result);
        return symbol(Line, Col, "", STRING, result_ptr);    
    }
    else if(sym2.Tipo == BOOL)
    {
        bool *val1 = (bool *)sym2.Value;
        std::string result = (*val1) ? "true" : "false";
        std::string *result_ptr = new std::string(result);
        return symbol(Line, Col, "", STRING, result_ptr);    
    }
    else{
        // report an error
        std::string msg = "invalid type. Numeric or Bool expected.";
        tree->addError(msg, Line, Col);
        return symbol(Line, Col, "", NULO, nullptr);
    }

}

