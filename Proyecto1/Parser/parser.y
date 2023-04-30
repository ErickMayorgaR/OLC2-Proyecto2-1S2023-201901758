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
/* %define parse.error verbose */

%code requires
{
    /* cabeceras iniciales */
    #include <sstream>
    #include <iostream>
    #include <string>
    #include <vector>
    #include "parserctx.hpp"


    /* expresiones */
    #include "../Proyecto1/Expression/primitive.hpp"
    #include "../Proyecto1/Expression/access.hpp"
    #include "../Proyecto1/Expression/vector_access.hpp"
    #include "../Proyecto1/Expression/vector_exp.hpp"
    #include "../Proyecto1/Expression/struct_access.hpp"
    #include "../Proyecto1/Expression/operation.hpp"
    #include "../Proyecto1/Expression/func_iota.hpp"
    #include "../Proyecto1/Expression/func_atoi.hpp"
    #include "../Proyecto1/Expression/func_atof.hpp"
    #include "../Proyecto1/Expression/func_mean.hpp"
    #include "../Proyecto1/Expression/func_median.hpp"
    #include "../Proyecto1/Expression/func_mode.hpp"
    #include "../Proyecto1/Environment/type.h"
    #include "../Proyecto1/Interfaces/expression.hpp"
    #include "../Proyecto1/Expression/map_struct_dec.hpp"
    #include "../Proyecto1/Expression/list_expression.hpp"
    #include "../Proyecto1/Expression/call_exp.hpp"
    #include "../Proyecto1/Expression/func_size.hpp"
    #include "../Proyecto1/Expression/func_get.hpp"

    /* instrucciones */
    #include "../Proyecto1/Interfaces/instruction.hpp"
    #include "../Proyecto1/Instruction/print.hpp"
    #include "../Proyecto1/Instruction/list_instruction.hpp"
    #include "../Proyecto1/Instruction/func_main.hpp"
    #include "../Proyecto1/Instruction/func_if.hpp"
    #include "../Proyecto1/Instruction/func_for.hpp"
    #include "../Proyecto1/Instruction/declaration.hpp"
    #include "../Proyecto1/Instruction/dec_struct.hpp"
    #include "../Proyecto1/Instruction/declare_vector.hpp"
    #include "../Proyecto1/Instruction/assign_vector.hpp"
    #include "../Proyecto1/Instruction/create_struct.hpp"
    #include "../Proyecto1/Instruction/function.hpp"
    #include "../Proyecto1/Instruction/func_break.hpp"
    #include "../Proyecto1/Instruction/func_continue.hpp"
    #include "../Proyecto1/Instruction/call_inst.hpp"
    #include "../Proyecto1/Instruction/inst_return.hpp"
    #include "../Proyecto1/Instruction/func_while.hpp"
    #include "../Proyecto1/Instruction/assignment.hpp"
    #include "../Proyecto1/Instruction/func_pushfront.hpp"
    #include "../Proyecto1/Instruction/func_pushback.hpp"
    #include "../Proyecto1/Instruction/func_remove.hpp"

    #include "../Proyecto1/mainwindow.h"
    #include <QApplication>
    #include <QMainWindow>
    #include "ui_mainwindow.h"
}

/* enlace con la función del retorno de simbolos */
%code { yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO ID STRING RMAIN
%token <std::string> PARA PARC LLAVA LLAVC CORA CORC
%token <std::string> VOID INT TSTRING FLOAT BOOLEAN RTRUE RFALSE NLL
%token <std::string> PRINTF RIOTA RATOI RATOF RMEAN RMEDIAN RMODE
%token <std::string> SUMA MENOS POR DIV INC MOD 
%token <std::string> RIF RELSE RWHILE RFOR
%token <std::string> RBREAK RCONTINUE RRETURN
%token <std::string> AND OR NOT 
%token <std::string> MAY MEN MAY_IG MEN_IG DIF IG STRUCT RVECTOR
%token <std::string> VPBACK VGET VREMOVE VSIZE VPFRONT
%token ';' '=' '.' ','

/* precedencia de operadores */
%left AND OR NOT
%left IG DIF
%left MEN MEN_IG MAY MAY_IG
%right INC
%left SUMA MENOS
%left POR DIV MOD
%nonassoc RIOTA RATOI RATOF RMEAN RMEDIAN RMODE VSIZE

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
//Expresiones
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<expression*> CALL_EXP;
%type<expression*> LIST_ARR;
%type<expression*> BOOL;

//INICIO
%type<func_main*> START;
%type<func_main*> MAIN;

//INSTRUCCIONES
%type<list_instruction*> LIST_INST;
%type<list_instruction*> ELSEIF_LIST;
%type<list_instruction*> ELSE;
%type<list_instruction*> LIST_FUNC;
%type<list_expression*> EXP_LIST;
%type<instruction*> INSTRUCTION;

//FUNCIONES EMBEBIDAS
%type<instruction*> PRINT;
%type<instruction*> FUNCTION;
%type<instruction*> CALL_INST;
%type<expression*> IOTA;
%type<expression*> ATOI;
%type<expression*> ATOF;
%type<expression*> MEAN;
%type<expression*> MEDIAN;
%type<expression*> MODE;  

//FUNCIONES DE ASIGNACION
%type<instruction*> ASSIGNMENT;
%type<instruction*> DECLARATION;

//SENTENCIAS DE CONTROL DE FLUJO
%type<instruction*> IF;
%type<instruction*> ELSEIF;
%type<instruction*> WHILE;
%type<instruction*> FOR;  

//SENTENCIAS DE TRANSFERENCIA
%type<instruction*> BREAK;
%type<instruction*> CONTINUE;
%type<instruction*> RETURN;

//ESTRUCTURA DE DATOS
%type<instruction*> STRUCT_DECLARATION;
%type<instruction*> STRUCT_CREATION;

 //FUNCIONES DE VECTORES
%type<expression*> SIZE;
%type<instruction*> INST_VECTOR;
%type<expression*> GET;

//TYPES DATA
%type<TipoDato> TYPES;
%type<map_struct_dec*> DEC_LIST;
%type<map_struct_dec*> FUNC_LIST;

/* printer */
%printer { yyoutput << $$; } <*>;

/* inicio de la grámatica */
%%

%start START;

START : MAIN
    {
        ctx.Main = $1;
        ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $1;
    }
    | LIST_FUNC MAIN
    {
        ctx.Main = $2;
        ctx.Functions = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $2;
    }
;

LIST_FUNC : LIST_FUNC FUNCTION
        {
            $1->newInst($2);
            $$ = $1;
        }
        | FUNCTION
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

FUNCTION : TYPES ID PARA FUNC_LIST PARC LLAVA LIST_INST LLAVC
        {
            $$ = new function(@1.begin.line, @1.begin.column,$1,$2,$4,$7);
        }
        | TYPES ID PARA PARC LLAVA LIST_INST LLAVC
        {
            $$ = new function(@1.begin.line, @1.begin.column,$1,$2,nullptr,$6);
        }
;

FUNC_LIST : FUNC_LIST ',' TYPES ID
        {
            $1->newMap($4,$3);
            $$ = $1;
        }
        | TYPES ID
        {
            $$ = new map_struct_dec();
            $$->newMap($2, $1);
        }
;

MAIN : VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
{
    $$ = new func_main(@1.begin.line, @1.begin.column, $1, $6);
}
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
    | DECLARATION ';' { $$ = $1; }
    | ASSIGNMENT ';' { $$ = $1; }
    | IF { $$ = $1; }
    | WHILE { $$ = $1; }
    | STRUCT_DECLARATION { $$ = $1; }
    | STRUCT_CREATION { $$ = $1; }
    | CALL_INST { $$ = $1; }
    | BREAK ';' {$$ = $1;}
    | CONTINUE ';' {$$ = $1;}
    | RETURN ';' { $$ = $1; }
    | INST_VECTOR ';' {$$ = $1;}
    | FOR { $$ = $1; }
;

RETURN : RRETURN EXP { $$ = new inst_return(@1.begin.line, @1.begin.column,$2); }
    | RRETURN { $$ = new inst_return(@1.begin.line, @1.begin.column,nullptr); }
;

PRINT : PRINTF PARA EXP_LIST PARC { $$ = new print(@1.begin.line, @1.begin.column,$3); }
;

DECLARATION : TYPES ID '=' EXP { $$ = new declaration(@1.begin.line, @1.begin.column,$1,$2,$4); }
            | RVECTOR MEN TYPES MAY ID '=' EXP  {$$ = new declare_vector(@1.begin.line, @1.begin.column, $3, $5, $7);}
;

ASSIGNMENT : ID '=' EXP { $$ = new assignment(@1.begin.line, @1.begin.column, $1, $3); }
            | ID CORA PRIMITIVE CORC '=' PRIMITIVE {$$ = new assign_vector(@1.begin.line, @1.begin.column, $1,$3,$6);}
;

BREAK : RBREAK {$$ = new func_break(@1.begin.line, @1.begin.column);}
;

CONTINUE : RCONTINUE {$$ = new func_continue(@1.begin.line, @1.begin.column);}
;

INST_VECTOR : ID '.' VPBACK PARA EXP PARC {$$ = new func_pushback(@1.begin.line, @1.begin.column, $1,$5);}
            | ID '.' VPFRONT PARA EXP PARC {$$ = new func_pushfront(@1.begin.line, @1.begin.column, $1,$5);}
            | ID '.' VREMOVE PARA EXP PARC {$$ = new func_remove(@1.begin.line, @1.begin.column, $1,$5);}
;

IF : RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
    {
        $$ = new func_if(@1.begin.line, @1.begin.column,$2,$4,$6,$7);
    }
    | RIF EXP LLAVA LIST_INST LLAVC ELSE
    {
        $$ = new func_if(@1.begin.line, @1.begin.column,$2,$4,nullptr,$6);
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

WHILE : RWHILE EXP LLAVA LIST_INST LLAVC { $$ = new func_while(@1.begin.line, @1.begin.column, $2, $4); }
;

FOR : RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC {$$ = new func_for(@1.begin.line, @1.begin.column,$3,$5,$7,$10);}
; 

STRUCT_DECLARATION : STRUCT ID LLAVA DEC_LIST LLAVC {$$ = new dec_struct(@1.begin.line, @1.begin.column,$4,$2); }
;

DEC_LIST : DEC_LIST TYPES ID ';'
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

STRUCT_CREATION : STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
                {
                    $$ = new create_struct(@1.begin.line, @1.begin.column,$2,$3,$6);
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

TYPES : INT { $$ = INTEGER; }
    | TSTRING { $$ = STRING; }
    | BOOLEAN { $$ = BOOL; }
    | FLOAT {$$ = FLOAT;}
    | VOID { $$ = NULO; }
    | RVECTOR { $$ = VECTOR; }
;

EXP : EXP SUMA EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "+"); }
    | EXP MENOS EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "-"); }
    | EXP POR EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "*"); }
    | EXP DIV EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "/"); }
    | EXP MEN EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "<"); }
    | EXP MAY EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, ">"); }
    | EXP MEN_IG EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "<="); }
    | EXP MAY_IG EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, ">="); }
    | EXP DIF EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "!="); }
    | EXP IG EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "=="); }
    | EXP AND EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "&&"); }
    | EXP OR EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "||"); }
    | NOT EXP {    $$ = new operation(@1.begin.line, @1.begin.column, $2, new primitive(0,0,BOOL, "", 0,0.0,false), "!");}
    | EXP MOD EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "%"); }
    | EXP INC { $$ = new operation(@1.begin.line, @1.begin.column, $1, new primitive(0,0,INTEGER, "", 0,0.0,false), "++"); }
    | IOTA {$$ = $1;}
    | ATOI {$$ = $1;}
    | ATOF {$$ = $1;}
    | MEAN {$$ = $1;}
    | MEDIAN {$$ = $1;}
    | MODE {$$ = $1;} 
    | SIZE {$$ = $1;}
    | GET {$$ = $1;}
    | PARA EXP PARC { $$ = $2; }
    | CORA EXP_LIST CORC { $$ = new vector_exp(@1.begin.line, @1.begin.column,$2); }
    | MENOS EXP { $$ = new operation(@1.begin.line, @1.begin.column, new primitive(@1.begin.line, @1.begin.column,INTEGER, "", 0,0.0,false), $2, "-"); }
    | PRIMITIVE { $$ = $1; }
    | CALL_EXP { $$ = $1; }
;

IOTA : RIOTA PARA EXP PARC {$$ = new func_iota(@1.begin.line, @1.begin.column,$3);}
;

ATOI : RATOI PARA PRIMITIVE PARC {$$ = new func_atoi(@1.begin.line, @1.begin.column,$3);}
;

ATOF : RATOF PARA PRIMITIVE PARC {$$ = new func_atof(@1.begin.line, @1.begin.column,$3);}
;

MEAN : RMEAN PARA ID PARC {$$ = new func_mean(@1.begin.line, @1.begin.column,$3);}
;

MEDIAN : RMEDIAN PARA ID PARC {$$ = new func_median(@1.begin.line, @1.begin.column,$3);}
;

MODE : RMODE PARA ID PARC {$$ = new func_mode(@1.begin.line, @1.begin.column,$3);}
;

SIZE : ID '.' VSIZE PARA PARC {$$ = new func_size(@1.begin.line, @1.begin.column, $1);}
;

GET : ID '.' VGET PARA EXP PARC {$$ = new func_get(@1.begin.line, @1.begin.column, $1,$5);}
;

PRIMITIVE : NUMERO {
                std::string cadena = $1;
                if(cadena.find(".") == -1)
                {
                    int num = stoi($1);
                    $$ = new primitive(@1.begin.line, @1.begin.column,INTEGER, "", num,0.0,false); }
                else
                {
                    float num = stof($1);
                    $$ = new primitive(@1.begin.line, @1.begin.column,FLOAT, "", 0, num,false);}

            }
            | STRING
            {
                std::string str1 = $1.erase(0,1);
                std::string str2 = str1.erase(str1.length()-1,1);
                $$ = new primitive(@1.begin.line, @1.begin.column,STRING,str2,0,0.0,false);
            }
            | NLL {$$ = new primitive(@1.begin.line, @1.begin.column,NULO,"",0,0.0,false);}
            | BOOL { $$ = $1; }
            | LIST_ARR { $$ = $1; }
;

BOOL : RTRUE { $$ = new primitive(@1.begin.line, @1.begin.column,BOOL,"",0,0.0,true); }
    | RFALSE { $$ = new primitive(@1.begin.line, @1.begin.column,BOOL,"",0,0.0,false); }
;

LIST_ARR : LIST_ARR CORA EXP CORC { $$ = new vector_access(@1.begin.line, @1.begin.column,$1,$3); }
        | LIST_ARR '.' ID { $$ = new struct_access(@1.begin.line, @1.begin.column,$1,$3); }
        | ID {$$ = new access(@1.begin.line, @1.begin.column,$1); }
;

CALL_EXP : ID PARA EXP_LIST PARC { $$ = new call_exp(@1.begin.line, @1.begin.column,$1,$3); }
        | ID PARA PARC { $$ = new call_exp(@1.begin.line, @1.begin.column,$1,nullptr); }
;

CALL_INST : ID PARA EXP_LIST PARC ';' { $$ = new call_inst(@1.begin.line, @1.begin.column,$1,$3);}
        | ID PARA PARC ';' { $$ = new call_inst(@1.begin.line, @1.begin.column,$1,nullptr); }
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
    QTextEdit* textEdit = mainWindow->findChild<QTextEdit*>("textEdit_3");
        // Append the error message to the existing textEdit_3 widget
        textEdit->append(QString::fromStdString(error_message));
}

