#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP
#include "Interfaces/expression.hpp"

class primitive : public expression
{
public:
    int Line;
    int Col;
    TipoDato Tipo;
    std::string StrVal;
    int NumVal;
    float FloatVal;
    bool BoolVal;

    primitive(int,int,TipoDato,std::string,int,float,bool);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // PRIMITIVE_HPP
