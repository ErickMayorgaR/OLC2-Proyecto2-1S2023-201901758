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
    symbol sym (Line,Col,"",NULO,nullptr);
    switch (Tipo) {
    case INTEGER:
        sym = symbol(Line,Col,"",Tipo,&NumVal);
        break;
    case STRING:
        sym = symbol(Line,Col,"",Tipo,&StrVal);
        break;
    case BOOL:
        sym = symbol(Line,Col,"",Tipo,&BoolVal);
        break;
    case FLOAT:
        sym = symbol(Line,Col,"",Tipo,&FloatVal);
        break;
    default:
        break;
    }
    return sym;
}
