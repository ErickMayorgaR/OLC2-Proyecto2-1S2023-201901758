#ifndef FUNC_MEDIA_HPP
#define FUNC_MEDIA_HPP
#include "Interfaces/expression.hpp"
#include "Interfaces/instruction.hpp"

class func_media : public expression
{
public:
    int Line;
    int Col;
    expression *Valor;

    func_media(int line, int col, expression *valor);
    symbol ejecutar(environment *env, ast *tree) override;
};

#endif // FUNC_MEDIA_HPP
