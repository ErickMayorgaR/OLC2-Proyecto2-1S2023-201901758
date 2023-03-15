#include "call_exp.hpp"
#include "Expression/map_struct_dec.hpp"
#include "Instruction/list_instruction.hpp"

call_exp::call_exp(int line, int col, std::string id, list_expression *explist)
{
    Line = line;
    Col = col;
    Id = id;
    ExpList = explist;
}

symbol call_exp::ejecutar(environment *env, ast *tree)
{
    symbol sym = symbol(0,0,"",NULO, nullptr);

    //creamos entorno de funcion
    environment *FuncEnv = new environment(env, Id);
    func_symbol sym_func = env->GetFunction(Id, env, tree);
    map_struct_dec mapStrTemp = *(map_struct_dec*)sym_func.ParamList;
    list_instruction instTemp = *(list_instruction*)sym_func.InstList;
    //validando si la llamada trae parametros
    if(ExpList != nullptr)
    {
        //Comparando cantidad de parametros
        map<std::string, TipoDato> mapTemp = mapStrTemp.ListDec;
        if(ExpList->ListExp.size() == mapTemp.size())
        {
            //comparando tipos de parametros
            int cont = 0;
            map<std::string, TipoDato>::iterator i;
            for(i = mapTemp.begin(); i != mapTemp.end(); ++i)
            {
                symbol sym = ExpList->ListExp[cont]->ejecutar(env, tree);
                if(sym.Tipo == i->second){
                    //se agrega la variable al entorno de la funcion
                    FuncEnv->SaveVariable(sym,i->first,tree);
                }
                else
                {
                    std::string msg = "incompatible parameter types";
                    tree->addError(msg,Line,Col);
                    return sym;
                }
                cont++;
            }
        }
        else
        {
            std::string msg = "the number of parameters is not correct";
            tree->addError(msg,Line,Col);
            return sym;
        }
    }
    //ejecutando instrucciones
    instTemp.ejecutar(FuncEnv, tree);
    //valor retorno
    if(!tree->ListReturn.isEmpty())
    {
        sym = tree->ListReturn[tree->ListReturn.size()-1];
        tree->ListReturn.pop_back();
    }
    //validacion de tipo
    if(sym.Tipo != sym_func.Tipo)
    {
        std::string msg = "wrong return type";
        tree->addError(msg,Line,Col);
    }
    return sym;
}
