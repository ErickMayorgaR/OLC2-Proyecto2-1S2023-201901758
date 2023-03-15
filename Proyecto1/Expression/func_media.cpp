#include "func_atoi.hpp"

func_atoi::func_atoi(int line, int col, expression *valor)
{
    Line = line;
    Col = col;
    Valor = valor;

}

symbol func_atoi::ejecutar(environment *env, ast *tree)
{   
    symbol sym2 = Valor->ejecutar(env, tree);
    if(sym2.Tipo == STRING)
    {
        try{
            std::string *val1 = (std::string *)sym2.Value;
            int result = std::stoi(*val1);
            int *result_ptr = new int(result);
            return symbol(Line, Col, "", INTEGER, result_ptr);
        
        } catch(const std::invalid_argument& e) {
            // Conversion failed: invalid argument
            // report an error
            std::string msg = "invalid argument.";
            tree->addError(msg, Line, Col);
            return symbol(Line, Col, "", NULO, nullptr);

        } catch(const std::out_of_range& e) {
            // Conversion failed: out of range
            // report an error
            std::string msg = "out of range.";
            tree->addError(msg, Line, Col);
            return symbol(Line, Col, "", NULO, nullptr);
        }
            
    }

    else{
        // report an error
        std::string msg = "invalid type. String expected.";
        tree->addError(msg, Line, Col);
        return symbol(Line, Col, "", NULO, nullptr);
    }

}

