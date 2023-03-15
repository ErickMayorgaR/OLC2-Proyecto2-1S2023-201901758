/* se convierte con: flex --verbose lexer.l*/
%option reentrant noyywrap nounput batch noinput
%option debug 
%option case-sensitive 
/* %option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/
%{
    #include <iostream>
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);

    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    
    //se incrusta el parser
    #include "parser.hpp"

    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;


%}

/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+("."{DIGITO}+)?
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*

%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */



    /* caracteres ignorados */

"//"[^\n]*            ; /* comentarios de una linea */
\n                  {loc.lines(yyleng);loc.step();}
[ \t\v\r\n\f]             {loc.step();} /* caracteres en blanco */                
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales


"^"     return Parser::symbol_type( token::POT, loc );
"NULL"    return Parser::symbol_type( token::NLL, loc);

    */

"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"*"     return Parser::symbol_type( token::POR, loc );
"/"     return Parser::symbol_type( token::DIV, loc );
"%"     return Parser::symbol_type( token::MOD, loc );
"++"     return Parser::symbol_type( token::INC, loc );
 
    /* Caracteres para operaciones lógicas */
"&&" return Parser::symbol_type(token::AND, loc);
"||" return Parser::symbol_type(token::OR, loc);
"!"  return Parser::symbol_type(token::NOT, loc);

    /*Caracteres para operaciones comparativas */
"==" return Parser::symbol_type(token::EQU, loc); //Equal
"!=" return Parser::symbol_type(token::DIFF, loc);//Not Equal 
">" return Parser::symbol_type(token::MAYOR, loc);
"<" return Parser::symbol_type(token::MENOR, loc);
">=" return Parser::symbol_type(token::MAYEQU, loc);
"<=" return Parser::symbol_type(token::MENEQU, loc);

    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token_type(';'), loc );
"="     return Parser::symbol_type(token_type('='), loc); //PARA ASIGNACION DE VARIABLES
"."     return Parser::symbol_type( token_type('.'), loc );
","     return Parser::symbol_type( token_type(','), loc );

"("     return Parser::symbol_type( token::PARA, loc );
")"     return Parser::symbol_type( token::PARC, loc );
"{"     return Parser::symbol_type( token::LLAVA, loc );
"}"     return Parser::symbol_type( token::LLAVC, loc );
"["     return Parser::symbol_type( token::CORA, loc );
"]"     return Parser::symbol_type( token::CORC, loc );

    /* TOKENS  */
"printf"    return Parser::symbol_type( token::PRINTF, loc );
"void"    return Parser::symbol_type( token::VOID, loc );
"main"    return Parser::symbol_type( token::RMAIN, loc );
"if"    return Parser::symbol_type( token::RIF, loc );
"else"    return Parser::symbol_type( token::RELSE, loc );
"for"    return Parser::symbol_type( token::RFOR, loc );
"while"    return Parser::symbol_type( token::RWHILE, loc );
"break"  return Parser::symbol_type( token::RBREAK, loc );
"continue"  return Parser::symbol_type( token::RCONTINUE, loc );
"atoi"  return Parser::symbol_type( token::RATOI, loc );
"atof"  return Parser::symbol_type( token::RATOF, loc );
"iota"  return Parser::symbol_type( token::RIOTA, loc );
"return"    return Parser::symbol_type( token::RRETURN, loc );

    /* TIPOS DE DATOS */
"int"    return Parser::symbol_type( token::INT, loc );
"float"  return Parser::symbol_type( token::FLOAT, loc );
"string"    return Parser::symbol_type( token::TSTRING, loc );
"bool"   return Parser::symbol_type( token::BOOLEAN, loc );
"struct"    return Parser::symbol_type( token::STRUCT, loc );
"true"   return Parser::symbol_type( token::BOOLTRUE, loc );
"false"   return Parser::symbol_type( token::BOOLFALSE, loc );
"array"    return Parser::symbol_type( token::ARRAY, loc );

{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */

%%


