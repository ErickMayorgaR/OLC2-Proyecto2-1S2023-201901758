#include "create_struct.hpp"

create_struct::create_struct(int line,int col, std::string idstruct, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    IdStruct = idstruct;
    Id = id;
    ExpList = explist;
}

void create_struct::ejecutar(environment *env, ast *tree)
{
    //buscar el struct en tabla de structs
    map<std::string, TipoDato> sym_struct = env->GetStruct(IdStruct, env, tree);
    //validar tamaños
    if(sym_struct.size() == ExpList->ListExp.size())
    {
        //creando entorno struct
        environment *StructValue = new environment(nullptr, Id);
        //comparando tipos en iteraciones
        int cont = 0;
        map<std::string, TipoDato>::iterator i;
        for(i = sym_struct.begin(); i != sym_struct.end(); ++i){
            symbol sym = ExpList->ListExp[cont]->ejecutar(env, tree);
            if(sym.Tipo == i->second){
                //se asigna el valor
                StructValue->SaveVariable(sym,i->first,tree);
            }
            else
            {
                std::string msg = "incompatibles types for struct";
                tree->addError(msg,Line,Col);
                return;
            }
            cont++;
        }
        //se guarda el StructValue en el entorno de simbolos
        symbol symStruct (Line,Col,Id,STRUCT,StructValue);
        env->SaveVariable(symStruct,Id, tree);
        tree->addSymbol(Id,"variable","struct","",Line,Col);
    }
    else
    {
        std::string msg = "number of attributes does not match";
        tree->addError(msg,Line,Col);
        return;
    }
}
