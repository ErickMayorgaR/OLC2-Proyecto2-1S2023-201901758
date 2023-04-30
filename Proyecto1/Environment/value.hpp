#ifndef VALUE_HPP
#define VALUE_HPP
#include <iostream>
#include "type.h"
#include "QVector"

class value
{
public:
    std::string Value;
    bool FlagTemp;
    TipoDato Tipo;
    QVector<std::string> TrueLabel;
    QVector<std::string> FalseLabel;
    value();
    value(std::string value, bool flagtemp, TipoDato type);
};

#endif // VALUE_HPP
