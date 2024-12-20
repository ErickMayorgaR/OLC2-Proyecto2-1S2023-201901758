#ifndef DECLARE_STRUCT_HPP
#define DECLARE_STRUCT_HPP
#include "Expression/map_struct_dec.hpp"
#include "Interfaces/instruction.hpp"

class declare_struct : public instruction
{
public:
    int Line;
    int Col;
    map_struct_dec *Array;
    std::string Id;

    declare_struct(int,int, map_struct_dec*, std::string);
    void ejecutar(environment *env, ast *tree) override;
};

#endif // DEC_STRUCT_HPP
