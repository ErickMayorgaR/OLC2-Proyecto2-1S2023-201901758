#include "value.hpp"

value::value()
{

}

value::value(std::string value, bool flagtemp, TipoDato type)
{
    Value = value;
    FlagTemp = flagtemp;
    Tipo = type;
    TrueLabel = QVector<std::string>();
    FalseLabel = QVector<std::string>();
}
