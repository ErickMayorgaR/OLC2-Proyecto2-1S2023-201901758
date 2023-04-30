#include "environment.hpp"

environment::environment(environment *anterior, std::string id)
{
    Anterior = anterior;
    Id = id;
    Size = 0;
}

symbol environment::SaveVariable(int line, int col, std::string id, TipoDato tipo, ast *tree)
{
    Line = line;
    Col = col;
    if (Tabla.find(id) == Tabla.end())
    {
        symbol sym (0, 0, id, tipo, Size);
        Tabla[id] = sym;
        Size += 1;
        return sym;
    }
    else
    {
        //se reporta un error
        std::string msg = "Variable exist already "+id;
        tree->addError(msg,Line,Col);
        return Tabla[id];
    }
}

symbol environment::AssignVariable(int line, int col, std::string id, TipoDato tipo, environment *env, ast *tree)
{
    Line = line;
    Col = col;
    environment *currentEnv = env;
    environment *AnteriorEnv = env;
    while (currentEnv != nullptr) {
        if (currentEnv->Tabla.find(id) != currentEnv->Tabla.end()) {
            symbol sym (0, 0, id, tipo, Size);
            currentEnv->Tabla[id] = sym;
            env = AnteriorEnv;
            return sym;
        }
        currentEnv = currentEnv->Anterior;
    }

    // Si no se encontró la variable en ningún ambiente, lanzar un error
    std::string msg = "invalid id";
    tree->addError(msg, Line, Col);
    return Tabla[id];
}

void environment::SaveStruct(int line, int col, map<std::string, TipoDato> tabla, std::string id, ast *tree)
{
   Line = line;
   Col = col;
   
    if (TablaStructs.find(id) == TablaStructs.end())
    {
        TablaStructs[id] = tabla;
    }
    else
    {
        //se reporta un error
        std::string msg = "Struct exist already"+id;
        tree->addError(msg,Line,Col);
    }
}

symbol environment::SaveVector(int line, int col, std::string id, TipoDato tipo, ast *tree)
{
    Line = line;
    Col = col;
    if (TablaVector.find(id) == TablaVector.end())
    {
        symbol sym (0, 0, id, tipo, Size);
        TablaVector[id] = sym;
        Size += 1;
        return sym;
    }
    else
    {
        //se reporta un error
        std::string msg = "Variable exist already "+id;
        tree->addError(msg,Line,Col);
        return TablaVector[id];
    }
}

symbol environment::AssignVector(int line, int col, std::string id, TipoDato tipo, environment *env, ast *tree)
{
    Line = line;
    Col = col;
    environment *currentEnv = env;
    environment *AnteriorEnv = env;
    while (currentEnv != nullptr) {
        if (currentEnv->TablaVector.find(id) != currentEnv->TablaVector.end()) {
            symbol sym (0, 0, id, tipo, Size);
            currentEnv->TablaVector[id] = sym;
            env = AnteriorEnv;
            return sym;
        }
        currentEnv = currentEnv->Anterior;
    }

    // Si no se encontró la variable en ningún ambiente, lanzar un error
    std::string msg = "invalid id";
    tree->addError(msg, Line, Col);
    return TablaVector[id];
}

void environment::SaveFunction(func_symbol funcSym, std::string id, ast *tree)
{
    if (TablaFunctions.find(id) == TablaFunctions.end())
    {
        TablaFunctions[id] = funcSym;
    }
    else
    {
        //se reporta un error
        std::string msg = "function exist already"+id;
        tree->addError(msg,Line,Col);   
    }
}

symbol environment::GetVariable(int rline, int rcol, std::string id, environment *env, ast *tree)
{
    symbol sym = *new symbol;
    environment tmpEnv = *env;

    for( ; ;)
    {
        if (tmpEnv.Tabla.find(id) == tmpEnv.Tabla.end())
        {
            if(tmpEnv.Anterior == nullptr)
            {
                std::string msg = "invalid id";
                tree->addError(msg,rline,rcol);
                break;
            }
            else
            {
                tmpEnv = *tmpEnv.Anterior;
            }
        }
        else
        {
            symbol tempSym (tmpEnv.Tabla[id].Line,
                            tmpEnv.Tabla[id].Col,
                            tmpEnv.Tabla[id].Id,
                            tmpEnv.Tabla[id].Tipo,
                            tmpEnv.Tabla[id].Value);
            sym = tempSym;
            break;
        }

    }

    return sym;
}

//map<std::string, TipoDato> environment::GetStruct(std::string id, environment *env, ast *tree)
//{
//    map<std::string, TipoDato> sym_struct;
//    environment tmpEnv = *env;

//    for( ; ;)
//    {
//        if (tmpEnv.TablaStructs.find(id) == tmpEnv.TablaStructs.end())
//        {
//            if(tmpEnv.Anterior == nullptr)
//            {
//                break;
//            }
//            else
//            {
//                tmpEnv = *tmpEnv.Anterior;
//            }
//        }
//        else
//        {
//            sym_struct = tmpEnv.TablaStructs[id];
//            break;
//        }

//    }
//    return sym_struct;
//}

//func_symbol environment::GetFunc(std::string id, environment *env, ast *tree)
//{
//    func_symbol sym_func;
//    environment tmpEnv = *env;

//    for( ; ;)
//    {
//        if (tmpEnv.TablaFunctions.find(id) == tmpEnv.TablaFunctions.end())
//        {
//            if(tmpEnv.Anterior == nullptr)
//            {
//                break;
//            }
//            else
//            {
//                tmpEnv = *tmpEnv.Anterior;
//            }
//        }
//        else
//        {
//            sym_func = tmpEnv.TablaFunctions[id];
//            break;
//        }

//    }
//    return sym_func;
//}

