#include "primitive.hpp"

primitive::primitive(int line, int col, TipoDato tipo, std::string StrVal, int NumVal, float FloatVal, bool Boolval){
    this->Line = line;
    this->Col = col;
    this->Tipo = tipo;
    this->StrVal = StrVal;
    this->NumVal = NumVal;
    this->FloatVal = FloatVal;
    this->BoolVal = BoolVal;
}

symbol primitive::ejecutar(environment *env, ast* tree)
{
    symbol sym = *new symbol(this->Line,this->Col,"",this->Tipo,this->StrVal,this->NumVal,this->FloatVal,this->BoolVal);
    return sym;
}
