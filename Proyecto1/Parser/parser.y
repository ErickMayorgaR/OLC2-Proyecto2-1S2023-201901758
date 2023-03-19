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
    #include <iostream>
    #include <string>
    #include <vector>
    #include "parserctx.hpp"

    /* enviroments */
    #include "../Proyecto1/Environment/type.h"
    /*interfaces*/
    #include "../Proyecto1/Interfaces/expression.hpp"
    /* expressions */
    #include "../Proyecto1/Expression/primitive.hpp"
    #include "../Proyecto1/Expression/access.hpp"
    #include "../Proyecto1/Expression/vector_access.hpp"
    #include "../Proyecto1/Expression/operation.hpp"
    #include "../Proyecto1/Expression/func_atoi.hpp"
    #include "../Proyecto1/Expression/func_atof.hpp"
    #include "../Proyecto1/Expression/func_iota.hpp"
    #include "../Proyecto1/Expression/func_mean.hpp"
    #include "../Proyecto1/Expression/func_median.hpp"
    #include "../Proyecto1/Expression/func_mode.hpp"
    #include "../Proyecto1/Expression/struct_access.hpp"
    #include "../Proyecto1/Expression/map_struct_dec.hpp"
    #include "../Proyecto1/Expression/list_expression.hpp"
    #include "../Proyecto1/Expression/call_exp.hpp"
    #include "../Proyecto1/Expression/expression_vector.hpp"
    #include "../Proyecto1/Expression/func_get.hpp"
    #include "../Proyecto1/Expression/func_size.hpp"
    /* instructions */
    #include "../Proyecto1/Interfaces/instruction.hpp"
    #include "../Proyecto1/Instruction/print.hpp"
    #include "../Proyecto1/Instruction/func_expression.hpp"
    #include "../Proyecto1/Instruction/list_instruction.hpp"
    #include "../Proyecto1/Instruction/func_main.hpp"
    #include "../Proyecto1/Instruction/func_if.hpp"
    #include "../Proyecto1/Instruction/func_for.hpp"
    #include "../Proyecto1/Instruction/func_while.hpp"
    #include "../Proyecto1/Instruction/func_break.hpp"
    #include "../Proyecto1/Instruction/func_return.hpp"
    #include "../Proyecto1/Instruction/func_continue.hpp"
    #include "../Proyecto1/Instruction/declare.hpp"
    #include "../Proyecto1/Instruction/assign.hpp"
    #include "../Proyecto1/Instruction/declare_struct.hpp"
    #include "../Proyecto1/Instruction/declare_vector.hpp"
    #include "../Proyecto1/Instruction/declare_matrix.hpp"
    #include "../Proyecto1/Instruction/assign_vector.hpp"
    #include "../Proyecto1/Instruction/func_pushback.hpp"
    #include "../Proyecto1/Instruction/func_remove.hpp"
    #include "../Proyecto1/Instruction/func_pushfront.hpp"
    #include "../Proyecto1/Instruction/create_struct.hpp"
    #include "../Proyecto1/Instruction/function.hpp"
    #include "../Proyecto1/Instruction/call_inst.hpp"

    #include "../Proyecto1/mainwindow.hpp"
    #include <QApplication>
    #include <QMainWindow>
    #include "ui_mainwindow.h"

}

/* enlace con la función del retorno de simbolos */
%code {yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); }

/* token de salida*/
%token END 0;

/*tokens*/
%token <std::string> NUMERO ID STRING TSTRING FLOAT BOOLEAN RSTRUCT RVECTOR INT BOOLTRUE BOOLFALSE
%token <std::string> PARA PARC LLAVA LLAVC CORA CORC
%token <std::string> VOID RMAIN NLL
%token <std::string> SUMA MENOS POR DIV INC MOD 
%token <std::string> RIF RELSE RWHILE RFOR
%token <std::string> PRINTF RMEAN RMEDIAN RMODE RATOI RATOF RIOTA
%token <std::string> RBREAK RCONTINUE RRETURN
%token <std::string> MAYOR MENOR MAYEQU MENEQU EQU DIFF
%token <std::string> AND OR NOT 
%token <std::string> VPBACK VGET VREMOVE VSIZE VPFRONT
%token ';' '=' ',' '.'

/* precedencia de operadores */
%left AND OR NOT
%left EQU DIFF
%left MENOR MENEQU MAYEQU MAYOR
%right INC
%left SUMA MENOS
%left DIV MOD POR
%left PARA PARC LLAVA LLAVC
%left RELSE

/* instancia de la clase que creamos */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }

/* definicion de no terminales */
//Expresiones
%type<expression*> PRIMITIVE;
%type<expression*> EXP;
%type<expression*> INCREMENT;
%type<expression*> PREFIX_INCREMENT;
%type<expression*> LIST_ARR;
%type<expression*> CALL_EXP;

//INICIO
%type<func_main*> START;
%type<func_main*> MAIN;

//INSTRUCCIONES
%type<list_instruction*> LIST_INST;
%type<list_instruction*> ELSEIF_LIST;
%type<list_instruction*> ELSE;
%type<list_expression*> EXP_LIST;
%type<list_instruction*> LIST_FUNC;
%type<list_instruction*> LIST_STRUCT;
%type<instruction*> INSTRUCTION;

//FUNCIONES EMBEBIDAS
%type<instruction*> PRINT;
%type<instruction*> EXPRESSION;
%type<expression*> ATOI;
%type<expression*> ATOF;
%type<expression*> IOTA;
%type<instruction*> FUNCTION;
%type<instruction*> CALL_INST;
%type<instruction*> DECLARE_VECTOR;
%type<instruction*> DECLARE_MATRIX;
%type<expression*> MEAN;
%type<expression*> MEDIAN;
%type<expression*> MODE;  

//FUNCIONES DE ASIGNACION
%type<instruction*> ASSIGNATION; 
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
 %type<instruction*> DECLARE_STRUCT;
 %type<instruction*> CREATE_STRUCT;

 //FUNCIONES DE VECTORES
%type<instruction*> PUSHBACK;
%type<instruction*> PUSHFRONT;
%type<expression*> GET;
%type<expression*> SIZE;
%type<instruction*> REMOVE;

//TYPES DATA
%type<TipoDato> TYPES;
%type<map_struct_dec*> DECLARE_LIST;
%type<map_struct_dec*> FUNCTION_LIST; 

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
    | LIST_FUNC MAIN
    {
        ctx.Main = $2;
        ctx.Functions = $1;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $2;
    }
    | LIST_STRUCT LIST_FUNC MAIN
    {
        ctx.Main = $3;
        ctx.Structs = $1;
        ctx.Functions = $2;
        ctx.Salida = "!Ejecución realizada con éxito!";
        $$ = $3;
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

LIST_STRUCT : LIST_STRUCT DECLARE_STRUCT 
        { 
            $1->newInst($2);
            $$ = $1;
        }  
        | DECLARE_STRUCT 
        {
            $$ = new list_instruction();
            $$->newInst($1);
        }
;

FUNCTION : TYPES ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
        {
            $$ = new function(0,0,$1,$2,$4,$7);
        }
        | TYPES ID PARA PARC LLAVA LIST_INST LLAVC
        {
            $$ = new function(0,0,$1,$2,nullptr,$6);
        }
        | ID ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
        {
            $$ = new function(0,0,STRUCT,$2,$4,$7);
        }
;

FUNCTION_LIST : FUNCTION_LIST ',' TYPES ID 
        {
            $1->newMap($4,$3);
            $$ = $1;
        }
        | FUNCTION_LIST ',' RVECTOR MENOR TYPES MAYOR ID 
        {
            $1->newMap($7,VECTOR);
            $$ = $1;
        }
        | TYPES ID 
        {   
            $$ = new map_struct_dec();
            $$->newMap($2, $1);
        }
        | RVECTOR MENOR TYPES MAYOR ID 
        {
            $$ = new map_struct_dec();
            $$->newMap($5, VECTOR);
        }
;

MAIN : TYPES RMAIN PARA PARC LLAVA LIST_INST LLAVC
{
    $$ = new func_main(0, 0, $1, $6);
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
            | EXPRESSION ';'{$$ = $1;}
            | IF { $$ = $1; }
            | WHILE { $$ = $1; } 
            | FOR { $$ = $1; }
            | DECLARATION ';' {$$ = $1;}
            | ASSIGNATION ';' {$$ = $1;}
            | DECLARE_STRUCT { $$ = $1; }
            | CREATE_STRUCT { $$ = $1; }
            | DECLARE_VECTOR ';' {$$ = $1;}
            | DECLARE_MATRIX ';' {$$ = $1;}
            | BREAK ';' {$$ = $1;}
            | CONTINUE ';' {$$ = $1;}
            | RETURN ';' {$$ = $1;}
            | CALL_INST { $$ = $1; }
            | PUSHBACK ';' {$$ = $1;}
            | PUSHFRONT ';' {$$ = $1;}
            | REMOVE ';' {$$ = $1;}
;

PRINT : PRINTF PARA EXP_LIST  PARC { $$ = new print(@1.begin.line, @1.begin.column,$3); }
;

PUSHBACK : ID '.' VPBACK PARA EXP PARC {$$ = new func_pushback(@1.begin.line, @1.begin.column, $1,$5);}
;

PUSHFRONT : ID '.' VPFRONT PARA EXP PARC {$$ = new func_pushfront(@1.begin.line, @1.begin.column, $1,$5);}
;

GET : ID '.' VGET PARA EXP PARC {$$ = new func_get(@1.begin.line, @1.begin.column, $1,$5);}
;

SIZE : ID '.' VSIZE PARA PARC {$$ = new func_size(@1.begin.line, @1.begin.column, $1);}
;

REMOVE : ID '.' VREMOVE PARA EXP PARC {$$ = new func_remove(@1.begin.line, @1.begin.column, $1,$5);}
;

IF : RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
    {
        $$ = new func_if(@1.begin.line, @1.begin.column,$2,$4,$6,$7);
    }
    | RIF EXP LLAVA LIST_INST LLAVC
    {
        $$ = new func_if(@1.begin.line, @1.begin.column,$2,$4,nullptr,nullptr);
    }
    | RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
    {
        $$ = new func_if(@1.begin.line, @1.begin.column,$2,$4,$6,nullptr);
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
            $$ = new func_if(@1.begin.line, @1.begin.column,$3,$5, nullptr, nullptr);
        }
;

ELSE : RELSE LLAVA LIST_INST LLAVC { $$ = $3; }
    | %empty { }
;


WHILE : RWHILE PARA EXP PARC LLAVA LIST_INST LLAVC{$$ = new func_while(@1.begin.line, @1.begin.column,$3,$6);}
;

FOR : RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC {$$ = new func_for(@1.begin.line, @1.begin.column,$3,$5,$7,$10);}
; 

EXPRESSION : EXP {$$ = new func_expression(@1.begin.line, @1.begin.column,$1);}
;

DECLARE_STRUCT: RSTRUCT ID LLAVA DECLARE_LIST LLAVC {$$ = new declare_struct(@1.begin.line, @1.begin.column,$4,$2); }
;

DECLARE_LIST : DECLARE_LIST TYPES ID ';'
        {
            $1->newMap($3,$2);
            $$ = $1;
        }
        | DECLARE_LIST ID ID ';'
        {
            $1->newMap($3,STRUCT);
            $$ = $1;
        }
        | TYPES ID ';'
        {
            $$ = new map_struct_dec();
            $$->newMap($2, $1);
        }
        | ID ID ';'
        {
            $$ = new map_struct_dec();
            $$->newMap($2, STRUCT);
        }
;

CREATE_STRUCT : RSTRUCT ID ID '=' LLAVA EXP_LIST LLAVC ';'
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

DECLARATION : TYPES ID '=' EXP {$$ = new declare(@1.begin.line, @1.begin.column,$1,$2,$4);}
            | TYPES ID {$$ = new declare(@1.begin.line, @1.begin.column,$1,$2,nullptr);}

ASSIGNATION : ID '=' EXP {$$ = new assign(@1.begin.line, @1.begin.column,$1,$3);}
            | ID CORA PRIMITIVE CORC '=' PRIMITIVE {$$ = new assign_vector(@1.begin.line, @1.begin.column, $1,$3,$6);}
;   

BREAK : RBREAK {$$ = new func_break(@1.begin.line, @1.begin.column);}
;

CONTINUE : RCONTINUE {$$ = new func_continue(@1.begin.line, @1.begin.column);}
;

RETURN : RRETURN EXP { $$ = new func_return(@1.begin.line, @1.begin.column,$2); }
        | RRETURN { $$ = new func_return(@1.begin.line, @1.begin.column,nullptr); }
;

MEAN : RMEAN PARA ID PARC {$$ = new func_mean(@1.begin.line, @1.begin.column,$3);}
;

MEDIAN : RMEDIAN PARA ID PARC {$$ = new func_median(@1.begin.line, @1.begin.column,$3);}
;

MODE : RMODE PARA ID PARC {$$ = new func_mode(@1.begin.line, @1.begin.column,$3);}
;
 
TYPES : INT { $$ = INTEGER; }
    | TSTRING { $$ = STRING; }
    | BOOLEAN { $$ = BOOL; }
    | FLOAT { $$ = FLOAT; }
    | VOID {$$ = VOID;}
    | RVECTOR {$$ = VECTOR;}
;
//OPERADORES ARITMÉTICOS Y LÓGICOS

EXP : EXP SUMA EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "+"); }
    | EXP MENOS EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "-"); }
    | EXP POR EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "*"); }
    | EXP DIV EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "/"); }
    | EXP MOD EXP { $$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "%"); }
   //OPERADOR ++
    | INCREMENT {$$ = $1;}
   //OPERADORES DE COMPARACION Y RELACIONALES
    | EXP MAYOR EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, ">");}
    | EXP MAYEQU EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, ">=");}
    | EXP MENOR EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, "<");}
    | EXP MENEQU EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, "<=");}
    | EXP EQU EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, "==");}
    | EXP DIFF EXP {$$ =  new operation(@1.begin.line, @1.begin.column, $1, $3, "!=");}
    //OPERADORES LOGICOS
    | EXP AND EXP {$$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "&&");}
    | EXP OR EXP {$$ = new operation(@1.begin.line, @1.begin.column, $1, $3, "||");}
    | NOT EXP
    {
        $$ = new operation(@2.begin.line, @2.begin.column, $2, new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
    //NEGACION UNARIA
    | MENOS EXP {
        $$ = new operation(@2.begin.line, @2.begin.column,$2,new primitive(0,0,INTEGER, "", 0,0.0,false),"NEG");
        }
    //OTRAS EXPRESIONES
    | PARA EXP PARC { $$ = $2; }
    | ATOI {$$ = $1;}
    | ATOF {$$ = $1;}
    | IOTA {$$ = $1;}
    | CORA EXP_LIST CORC { $$ = new expression_vector(@1.begin.line, @1.begin.column,$2); }
    | CALL_EXP { $$ = $1; }
    | GET {$$ = $1;}
    | SIZE {$$ = $1;}
    | MEAN {$$ = $1;}
    | MEDIAN {$$ = $1;}
    | MODE {$$ = $1;}   
    //VALOR
    | PRIMITIVE { $$ = $1; }
    
;

ATOI : RATOI PARA PRIMITIVE PARC {$$ = new func_atoi(@1.begin.line, @1.begin.column,$3);}
;

ATOF : RATOF PARA PRIMITIVE PARC {$$ = new func_atof(@1.begin.line, @1.begin.column,$3);}
;

IOTA : RIOTA PARA EXP PARC {$$ = new func_iota(@1.begin.line, @1.begin.column,$3);}
;


INCREMENT: PREFIX_INCREMENT { $$ = $1; }
            | EXP INC { $$ = new operation(@1.begin.line, @1.begin.column, $1, new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
;

PREFIX_INCREMENT: INC EXP { $$ = new operation(@2.begin.line, @2.begin.column, $2, new primitive(0,0,INTEGER, "", 0,0.0,false), "++B"); }
                | EXP PREFIX_INCREMENT {$$ = $2;}
;
// TIPOS DE DATOS PRIMITIVOS
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
        |BOOLTRUE {$$ = new primitive(@1.begin.line, @1.begin.column,BOOL, "", 0, 0.0, true);}
        |BOOLFALSE {$$ = new primitive(@1.begin.line, @1.begin.column,BOOL, "", 0, 0.0, false);}
        |LIST_ARR {$$ = $1;}
;

LIST_ARR : LIST_ARR CORA EXP CORC { $$ = new vector_access(@1.begin.line, @1.begin.column,$1,$3); }
        | LIST_ARR '.' ID { $$ = new struct_access(@1.begin.line, @1.begin.column,$1,$3); }
        | ID {$$ = new access(@1.begin.line, @1.begin.column,$1); }
;

DECLARE_VECTOR : RVECTOR MENOR TYPES MAYOR ID '=' EXP  {$$ = new declare_vector(@1.begin.line, @1.begin.column, $3, $5, $7);}
                | RVECTOR MENOR TYPES MAYOR ID  {$$ = new declare_vector(@1.begin.line, @1.begin.column, $3, $5, nullptr);}
;

DECLARE_MATRIX : TYPES ID CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC {$$ = new declare_matrix(@1.begin.line, @1.begin.column,$1, $2, $4, nullptr, nullptr, $8);}
                | TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC {$$ = new declare_matrix(@1.begin.line, @1.begin.column,$1, $2, $4 , $7, nullptr, $11);}
                | TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC {$$ = new declare_matrix(@1.begin.line, @1.begin.column,$1, $2, $4, $7, $10, $14);}
;

;
CALL_EXP : ID PARA EXP_LIST PARC { $$ = new call_exp(0,0,$1,$3); }
        | ID PARA PARC { $$ = new call_exp(0,0,$1,nullptr); }
;

CALL_INST : ID PARA EXP_LIST PARC ';' { $$ = new call_inst(0,0,$1,$3);}
        | ID PARA PARC ';' { $$ = new call_inst(0,0,$1,nullptr); }
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
