#include "symbol.hpp"

symbol::symbol(int line, int col, std::string id, TipoDato tipo, std::string strval, int numval, float floatval, bool boolval){
    this->Line = line;
    this->Col = col;
    this->Id = id;
    this->Tipo = tipo;
    this->StrVal = strval;
    this->NumVal = numval;
    this->FloatVal = floatval;
    this->BoolVal = boolval;
}
