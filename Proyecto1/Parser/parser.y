/* comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)*/
%defines

/* indica el namespace que contiene al parser */
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */
%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires 
{
    /* cabeceras iniciales */
    #include <iostream> 
    #include <string> 
    #include <vector>
    #include "parserctx.hpp"

    /* expresiones */
    #include "../Proyecto1/Expression/primitive.hpp"
    #include "../Proyecto1/Expression/access.hpp"
    #include "../Proyecto1/Expression/array_access.hpp"
    #include "../Proyecto1/Expression/struct_access.hpp"
    #include "../Proyecto1/Expression/operation.hpp"
    #include "../Proyecto1/Environment/type.h"
    #include "../Proyecto1/Interfaces/expression.hpp"
    #include "../Proyecto1/Expression/map_struct_dec.hpp"
    #include "../Proyecto1/Expression/list_expression.hpp"

    /* instrucciones */
    #include "../Proyecto1/Interfaces/instruction.hpp"
    #include "../Proyecto1/Instruction/print.hpp"
    #include "../Proyecto1/Instruction/list_instruction.hpp"
    #include "../Proyecto1/Instruction/func_main.hpp"
    #include "../Proyecto1/Instruction/func_if.hpp"
    #include "../Proyecto1/Instruction/declare.hpp"
    #include "../Proyecto1/Instruction/dec_struct.hpp"
    #include "../Proyecto1/Instruction/create_struct.hpp"

    #include "../Proyecto1/mainwindow.hpp" 
    #include <QApplication>
    #include <QMainWindow>
    #include "ui_mainwindow.h"   
}   

/*
FALTAN: 
-> MATRICES 
-> VECTORES 
*/

/* enlace con la función del retorno de simbolos */
%code {yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO ID STRING TSTRING FLOAT BOOLEAN STRUCT INT BOOLTRUE BOOLFALSE
%token <std::string> PARA PARC LLAVA LLAVC CORA CORC
%token <std::string> VOID RMAIN NLL 
%token <std::string> SUMA MENOS POR DIV POT INC MOD 
%token <std::string> RIF RELSE WHILE FOR 
%token <std::string> PRINTF ASIGNAR MEDIA MEDIANA MODA ATOI ATOF IOTA
%token <std::string> BREAK CONTINUE RETURN
%token <std::string> MAYOR MENOR MAYEQU MENEQU EQU DIFF 
%token <std::string> AND OR NOT 
%token ';' '=' ',' '.'

/* precedencia de operadores */
%left AND OR NOT
%left EQU DIFF
%left MENOR MENEQU MAYEQU MAYOR  
%left SUMA MENOS
%left DIV MOD POR 
%right INC 
%left PARA PARC LLAVA LLAVC 


/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
//Expresiones
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<expression*> LIST_ARR;

//INICIO
%type<func_main*> START;
%type<func_main*> MAIN;

//FUNCIONES 
//%type<functions*> FUNCTIONS;

//INSTRUCCIONES
%type<list_instruction*> LIST_INST;
%type<list_instruction*> ELSEIF_LIST;
%type<list_instruction*> ELSE;
%type<list_expression*> EXP_LIST;
%type<instruction*> INSTRUCTION;

//FUNCIONES EMBEBIDAS
%type<instruction*> PRINT;
/* %type<instruction*> MEDIA;
%type<instruction*> MEDIANA;
%type<instruction*> MODA;
%type<instruction*> ATOI;
%type<instruction*> ATOF;
%type<instruction*> IOTA; */

//FUNCIONES DE ASIGNACION 
/*  %type<instruction*> ASSIGN; */
%type<instruction*> DECLARATION; 

//SENTENCIAS DE CONTROL DE FLUJO
%type<instruction*> IF;
%type<instruction*> ELSEIF;
/*%type<instruction*> WHILE;
%type<instruction*> FOR; */

//SENTENCIAS DE TRANSFERENCIA
/* %type<instruction*> BREAK;
%type<instruction*> CONTINUE;
%type<instruction*> RETURN; */

//ESTRUCTURA DE DATOS
 %type<instruction*> DECLARE_STRUCT;
 %type<instruction*> CREATE_STRUCT;

//TYPES DATA
%type<TipoDato> TYPES;
%type<map_struct_dec*> DECLARE_LIST; 

/* printer */
%printer { yyoutput << $$; } <*>;

/* inicio de la grámatica */
%%

%start START;

START : MAIN
    {
        ctx.Main = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $1;
    }
;

MAIN : VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC 
{
    $$ = new func_main(0, 0, $1, $6);
}
;

/* LIST_PARAMETERS : TYPES ID 
                | TYPES ID ',' 
                | LIST_PARAMETERS TYPES ID 
                | ' ' {;} 
; */

LIST_INST : LIST_INST INSTRUCTION 
        { 
            $1->newInst($2);
            $$ = $1;
        }  
        | INSTRUCTION 
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

INSTRUCTION : PRINT ';' { $$ = $1; }
             | IF { $$ = $1; }
/*            | WHILE ';' { $$ = $1; }
            | FOR ';' { $$ = $1; }*/
            | DECLARATION ';' {$$ = $1;}
            | DECLARE_STRUCT { $$ = $1; }
            | CREATE_STRUCT { $$ = $1; }
/*            | MEDIA ';' {$$ = $1;}
            | MEDIANA ';' {$$ = $1;}
            | MODA ';' {$$ = $1;}
            | ATOI ';' {$$ = $1;}
            | IOTA ';' {$$ = $1;}
            | BREAK ';' {$$ = $1;}
            | CONTINUE ';' {$$ = $1;}
            | RETURN {$$ = $1;}
            | FUNCTIONS {$$ = $1;}
            | INSTRUCTION ';'{$$ = $1;}  */
;

/* FUNCTIONS : TYPES ID PARA LIST_PARAMETERS PARC BLOCK_SENTENCIAS {$$ = }
; */

PRINT : PRINTF PARA EXP PARC { $$ = new print(0,0,$3); }
;

IF : RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE 
    {
        $$ = new func_if(0,0,$2,$4,$6,$7);
    }
    | RIF EXP LLAVA LIST_INST LLAVC 
    {
        $$ = new func_if(0,0,$2,$4,nullptr,nullptr);
    }
    | RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
    {
        $$ = new func_if(0,0,$2,$4,$6,nullptr);
    }
    | RIF EXP LLAVA LIST_INST LLAVC ELSE 
    {
        $$ = new func_if(0,0,$2,$4,nullptr,$6);
    }
;

ELSEIF_LIST : ELSEIF_LIST ELSEIF 
        { 
            $1->newInst($2);
            $$ = $1;
        }  
        | ELSEIF 
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

ELSEIF : RELSE RIF EXP LLAVA LIST_INST LLAVC 
        {
            $$ = new func_if(0,0,$3,$5, nullptr, nullptr);
        }
;

ELSE : RELSE LLAVA LIST_INST LLAVC { $$ = $3; }
    | %empty { }
;

/*
WHILE : WHILE PARA BOOL PARC BLOCK_SENTENCIAS {$$ = new while(0,0,$3,$6)}
;

FOR : FOR PARA DECLARATION ';' EXP ';' EXP PARC BLOCK_SENTENCIAS {$$ = new for(0,0,$3,$6)}
;
*/    
DECLARE_STRUCT: STRUCT ID LLAVA DECLARE_LIST LLAVC {$$ = new dec_struct(0,0,$4,$2); }
;

DECLARE_LIST : DECLARE_LIST TYPES ID ';' 
        {
            $1->newMap($3,$2);
            $$ = $1;
        }
        | TYPES ID ';' 
        {   
            $$ = new map_struct_dec();
            $$->newMap($2, $1);
        }
;

CREATE_STRUCT : STRUCT ID ID '=' LLAVA EXP_LIST LLAVC 
                {
                    $$ = new create_struct(0,0,$2,$3,$6);
                }
;

EXP_LIST : EXP_LIST ',' EXP 
        {
            $1->newExp($3);
            $$ = $1;
        }
        | EXP 
        {
            $$ = new list_expression();
            $$->newExp($1);
        }
;

DECLARATION : TYPES ID '=' EXP {$$ = new declare(0,0,$1,$2,$4);}
            | TYPES ID {$$ = new declare(0,0,$1,$2,nullptr);}

/* ASSIGN : ID '=' PRIMITIVE 
        {
            $$ = new declare(0,0,"null",$1,$3);
        }
;   */ 
/*          
MEDIA : MEDIA PARA VARIABLE PARC ';' {$$ = }
;

MEDIANA : MEDIANA PARA VARIABLE PARC ';' {$$ = }
;

MODA : MODA PARA VARIABLE PARC ';' {$$ = }
;

ATOI : ATOI PARA STRING PARC 
    | ATOF {$$ = $1}

ATOF : ATOI PARA STRING PARC {$$ =}
;

IOTA : IOTA PARA INT PARC 
    | IOTA PARA BOOL PARC 
    | IOTA PARA FLOAT PARC 
;

BREAK : BREAK {$$ = ;}
;

CONTINUE : CONTINUE {$$ = ;}
;

RETURN : RETURN ';' {;}
        | RETURN VARIABLE ';' {$$ = $2}
; */

TYPES : INT { $$ = INTEGER; }
    | TSTRING { $$ = STRING; }
    | BOOLEAN { $$ = BOOL; }
    | FLOAT { $$ = FLOAT; }
;
//OPERADORES ARITMÉTICOS Y LÓGICOS

EXP : EXP SUMA EXP { $$ = new operation(0, 0, $1, $3, "+"); }
    | EXP MENOS EXP { $$ = new operation(0, 0, $1, $3, "-"); }
    | EXP POR EXP { $$ = new operation(0, 0, $1, $3, "*"); }
    | EXP DIV EXP { $$ = new operation(0, 0, $1, $3, "/"); }
    | EXP MOD EXP { $$ = new operation(0, 0, $1, $3, "%"); }
   //OPERADOR ++
    | EXP INC { $$ = new operation(0, 0, $1, new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
    | INC EXP { $$ = new operation(0, 0, $2, new primitive(0,0,INTEGER, "", 0,0.0,false), "++B"); }
   //OPERADORES DE COMPARACION Y RELACIONALES
    | EXP MAYOR EXP {$$ =  new operation(0, 0, $1, $3, ">");}
    | EXP MAYEQU EXP {$$ =  new operation(0, 0, $1, $3, ">=");}
    | EXP MENOR EXP {$$ =  new operation(0, 0, $1, $3, "<");}
    | EXP MENEQU EXP {$$ =  new operation(0, 0, $1, $3, "<=");}
    | EXP EQU EXP {$$ =  new operation(0, 0, $1, $3, "==");}
    | EXP DIFF EXP {$$ =  new operation(0, 0, $1, $3, "!=");}
    //OPERADORES LOGICOS
    | EXP AND EXP {$$ = new operation(0, 0, $1, $3, "&&");}
    | EXP OR EXP {$$ = new operation(0, 0, $1, $3, "||");}
    | NOT EXP 
    {
        $$ = new operation(0, 0, $2, new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
    //NEGACION UNARIA 
    | MENOS EXP {
        $$ = new operation(0,0,$2,new primitive(0,0,INTEGER, "", 0,0.0,false),"NEG");
        }
    //OTRAS EXPRESIONES
    | PARA EXP PARC { $$ = $2; }
    //VALOR
    | PRIMITIVE { $$ = $1; }
;

// TIPOS DE DATOS PRIMITIVOS
PRIMITIVE : NUMERO { 
            std::string cadena = $1;
            if(cadena.find(".") == -1)
            {   
                int num = stoi($1);
                $$ = new primitive(0,0,INTEGER, "", num,0.0,false); }
            else
            {
                float num = stof($1);
                $$ = new primitive(0,0,FLOAT, "", 0, num,false);}
            
            }
        | STRING 
        { 
            std::string str1 = $1.erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            $$ = new primitive(0,0,STRING,str2,0,0.0,false);
        }
        |BOOLTRUE {$$ = new primitive(0,0,BOOL, "", 0, 0.0, true);}
        |BOOLFALSE {$$ = new primitive(0,0,BOOL, "", 0, 0.0, false);}
        |LIST_ARR {$$ = $1;}
;       

LIST_ARR : LIST_ARR CORA EXP CORC { $$ = new array_access(0,0,$1,$3); }
        | LIST_ARR '.' ID { $$ = new struct_access(0,0,$1,$3); }
        | ID {$$ = new access(0,0,$1); }   
;

%%
/* función de error */
void yy::Parser::error(const yy::location& loc, const std::string& msg)
{
    std::stringstream ss;
    ss << msg << ", line " << loc.begin.line << ", column " << loc.begin.column;
    std::string error_message = ss.str();
    // obtener la instancia de Ui_MainWindow de MainWindow
    QMainWindow* mainWindow = dynamic_cast<QMainWindow*>(QApplication::activeWindow());
    Ui::MainWindow* ui = new Ui::MainWindow;
    ui->setupUi(mainWindow);
    ui->textEdit_3->append(QString::fromStdString(error_message));   
}
