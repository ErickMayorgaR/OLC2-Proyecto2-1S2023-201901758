#include "environment.hpp"

environment::environment(environment *anterior, std::string id)
{
    Anterior = anterior;
    Id = id;
}

void environment::SaveVariable(symbol sym, std::string id, ast *tree)
{
    if (Tabla.find(id) == Tabla.end())
    {
        Tabla[id] = sym;
    }
    else
    {
        //se reporta un error
        std::string msg = "Variable exist already "+id;
        tree->addError(msg,sym.Line,sym.Col);
    }
}

void environment::AssignVariable(symbol sym, std::string id, environment *env, ast *tree)
{
    environment *currentEnv = env;
    environment *AnteriorEnv = env;
    while (currentEnv != nullptr) {
        if (currentEnv->Tabla.find(id) != currentEnv->Tabla.end()) {
            currentEnv->Tabla[id] = sym;
            env = AnteriorEnv;
            return;
        }
        currentEnv = currentEnv->Anterior;
    }

    // Si no se encontró la variable en ningún ambiente, lanzar un error
    std::string msg = "invalid id";
    tree->addError(msg, sym.Line, sym.Col);
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

void environment::SaveVector(int line, int col, typedata_vector tablavector, std::string id, ast *tree)
{
    Line = line;
    Col = col; 

    if (TablaVector.find(id) == TablaVector.end())
    {
        TablaVector[id] = tablavector;
    }
    else
    {
        //se reporta un error
        std::string msg = "Vector exist already"+id;
        tree->addError(msg,Line,Col);
    }
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
    symbol sym (0,0,"",NULO,nullptr);
    environment glbEnv = *env;

    for( ; ;)
    {
        if (glbEnv.Tabla.find(id) == glbEnv.Tabla.end())
        {
            if(glbEnv.Anterior == nullptr)
            {
                std::string msg = "invalid id";
                tree->addError(msg,rline,rcol);
                break;
            }
            else
            {
                glbEnv = *glbEnv.Anterior;
            }
        }
        else
        {
            symbol tempSym (glbEnv.Tabla[id].Line,
                            glbEnv.Tabla[id].Col,
                            glbEnv.Tabla[id].Id,
                            glbEnv.Tabla[id].Tipo,
                            glbEnv.Tabla[id].Value);
            sym = tempSym;
            break;
        }

    }

    return sym;
}

map<std::string, TipoDato> environment::GetStruct(std::string id, environment *env, ast *tree)
{
    map<std::string, TipoDato> sym_struct;
    environment glbEnv = *env;

    for( ; ;)
    {
        if (glbEnv.TablaStructs.find(id) == glbEnv.TablaStructs.end())
        {
            if(glbEnv.Anterior == nullptr)
            {
                break;
            }
            else
            {
                glbEnv = *glbEnv.Anterior;
            }
        }
        else
        {
            sym_struct = glbEnv.TablaStructs[id];
            break;
        }

    }
    return sym_struct;
}

func_symbol environment::GetFunction(std::string id, environment *env, ast *tree)
{
    func_symbol sym_func;
    environment glbEnv = *env;

    for( ; ;)
    {
        if (glbEnv.TablaFunctions.find(id) == glbEnv.TablaFunctions.end())
        {
            if(glbEnv.Anterior == nullptr)
            {
                break;
            }
            else
            {
                glbEnv = *glbEnv.Anterior;
            }
        }
        else
        {
            sym_func = glbEnv.TablaFunctions[id];
            break;
        }

    }
    return sym_func;
}
