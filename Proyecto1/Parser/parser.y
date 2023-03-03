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
    #include "../Proyecto1/Expression/operation.hpp"
    #include "../Proyecto1/Environment/type.h"
    #include "../Proyecto1/Interfaces/expression.hpp"

    /* instrucciones */
    #include "../Proyecto1/Interfaces/instruction.hpp"
    #include "../Proyecto1/Instruction/print.hpp"
    #include "../Proyecto1/Instruction/list_instruction.hpp"
    #include "../Proyecto1/Instruction/func_main.hpp"

}

/*
FALTAN: 
-> MATRICES 
-> VECTORES 
-> STRUCTS 
*/

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO ID STRING FLOAT BOOL INT 
%token PARA PARC LLAVA LLAVC
%token VOID RMAIN NLL 
%token SUMA MENOS POR DIV POT INC MOD NEG
%token IF ELSE WHILE FOR CONDITIONAL
%token PRINTF MEDIA MEDIANA MODA ATOI ATOF IOTA
%token ASSIGN DECLARATION 
%token BREAK CONTINUE RETURN
%token MAYOR MENOR MAYEQU MENEQU EQU DIFF 
%token AND OR NOT 
%token ';'

/* precedencia de operadores */
%left OR 
%left AND 
%left EQU DIFF
%left MENOR MENEQU MAYEQU MAYOR  
%left SUMA MENOS
%left DIV MOD POR 
%right INC NEG 
%left PARA PARC LLAVA LLAVC 

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
//Expresiones
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<expression*> BLOCK_SENTENCIAS;

//INICIO
%type<func_main*> START;
%type<func_main*> MAIN;

//FUNCIONES 
%type<functions*> FUNCTIONS;

//INSTRUCCIONES
%type<list_instruction*> LIST_INST;
%type<instruction*> INSTRUCTION;

//FUNCIONES EMBEBIDAS
%type<instruction*> PRINT;
%type<instruction*> MEDIA;
%type<instruction*> MEDIANA;
%type<instruction*> MODA;
%type<instruction*> ATOI;
%type<instruction*> ATOF;
%type<instruction*> IOTA;

//FUNCIONES DE ASIGNACION 
%type<instruction*> ASSIGN;
%type<instruction*> DECLARATION;

//SENTENCIAS DE CONTROL DE FLUJO
%type<instruction*> IF;
%type<instruction*> ELSE;
%type<instruction*> WHILE;
%type<instruction*> FOR;

//SENTENCIAS DE TRANSFERENCIA
%type<instruction*> BREAK;
%type<instruction*> CONTINUE;
%type<instruction*> RETURN;

//TYPES DATA
%type<std::string> TYPES;

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

MAIN : TYPES RMAIN PARA PARC LLAVA LIST_INST LLAVC 
{
    $$ = new func_main(0, 0, $1, $6);
}
;

LIST_PARAMETERS : TYPES ID 
                | TYPES ID ',' 
                | LIST_PARAMETERS TYPES ID 
                | ' ' {;} 
;

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
            | CONDITIONAL ';' { $$ = $1; }
            | WHILE ';' { $$ = $1; }
            | FOR ';' { $$ = $1; }
            | ASSIGN ';' {$$ = $1;}
            | DECLARATION ';' {$$ = $1;}
            | MEDIA ';' {$$ = $1;}
            | MEDIANA ';' {$$ = $1;}
            | MODA ';' {$$ = $1;}
            | ATOI ';' {$$ = $1;}
            | IOTA ';' {$$ = $1;}
            | BREAK ';' {$$ = $1;}
            | CONTINUE ';' {$$ = $1;}
            | RETURN {$$ = $1;}
            | FUNCTIONS {$$ = $1;}
            | INSTRUCTION ';'{$$ = $1;} 
;

FUNCTIONS : TYPES ID PARA LIST_PARAMETERS PARC BLOCK_SENTENCIAS {$$ = }
;

PRINT : PRINTF PARA EXP PARC { $$ = new print(0,0,$3); }
;

CONDITIONAL : IF PARA EXP PARC BLOCK_SENTENCIAS {$$ = new if(0,0,$3,$6)}
            | IF PARA EXP PARC BLOCK_SENTENCIAS ELSE BLOCK_SENTENCIAS {$$ = }
            | IF PARA EXP PARC BLOCK_SENTENCIAS ELSE CONDITIONAL {$$ = } 
;

WHILE : WHILE PARA BOOL PARC BLOCK_SENTENCIAS {$$ = new while(0,0,$3,$6)}
;

FOR : FOR PARA DECLARATION ';' EXP ';' EXP PARC BLOCK_SENTENCIAS {$$ = new for(0,0,$3,$6)}
;

ASSIGN : ID '=' VARIABLE
        | ID INC  //INCREMENTO POSTFIJO
        | INC ID  //INCREMENTO PREFIJO
;       

DECLARATION : TYPES ID  {;}
             | TYPES ID '=' VARIABLE  {;}
             | TYPES ID '=' INSTRUCTION {$$ = $4;}
             | DECLARATION ID {;}
             
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
;

TYPES : VOID { $$ = "void"; }
    | INT { $$ = "int"; }
    | STRING {$$ = "string";}
    | FLOAT {$$ = "float";}
    | BOOL {$$ = "bool";}
;
//OPERADORES ARITMÉTICOS Y LÓGICOS

EXP : EXP SUMA EXP { $$ = new operation(0, 0, $1, $3, "+"); }
    | EXP MENOS EXP { $$ = new operation(0, 0, $1, $3, "-"); }
    | EXP POR EXP { $$ = new operation(0, 0, $1, $3, "*"); }
    | EXP DIV EXP { $$ = new operation(0, 0, $1, $3, "/"); }
    | EXP POT EXP { $$ = new operation(0, 0, $1, $3, "^"); }
    | EXP MOD EXP { $$ = new operation(0, 0, $1, $3, "%"); }
   //OPERADOR ++
    | EXP INC { $$ = new operation(0, 0, $1, $3, "++"); }
    | INC EXP 
    //OPERADORES DE COMPARACION Y RELACIONALES
    | EXP MAYOR EXP 
    | EXP MAYEQU EXP 
    | EXP MENOR EXP 
    | EXP MENEQU EXP 
    | EXP EQU EXP 
    | EXP DIFF EXP 
    //OPERADORES LOGICOS
    | EXP AND EXP 
    | EXP OR EXP 
    | NOT EXP 
    //NEGACION UNARIA 
    | MENOS PRIMITIVE
    //OTRAS EXPRESIONES
    | PARA EXP PARC { $$ = $2; }
    //VALOR
    | VARIABLE { $$ = $1; }
;

// VALORES PARA ID 
VARIABLE : PRIMITIVE 
        | VARIABLE PRIMITIVE 
;

// TIPOS DE DATOS PRIMITIVOS
PRIMITIVE : NUMERO { $$ = new primitive(0,0,INTEGER, "", std::stod($1)); }
        | STRING 
        { 
            std::string cadena = $1.erase(0,1);
            $$ = new primitive(0,0,STRING, cadena.erase(cadena.length()-1,1), 0);
        }
        | FLOAT { $$ = new primitive(0,0,FLOAT, "", std::stod($1)); }
        | BOOL { $$ = new primitive(0,0,BOOL, "", std::stod($1)); }
;       
// POSIBLES SENTENCIAS 
BLOCK_SENTENCIAS : LLAVA EXP LLAVC {$$ = $2;}
                | LLAVA PRIMITIVE LLAVC {$$ = $2;}
                | LLAVA INSTRUCTION LLAVC {$$ = $2;}
                | BLOCK_SENTENCIAS {$$ = $1;}
;

%%

/* función de error */
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}

