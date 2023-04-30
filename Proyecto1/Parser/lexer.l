/* se convierte con: flex --verbose lexer.l*/
/* opcciones para encapsulamiento */

%option reentrant noyywrap nounput batch noinput
%option debug
/*%option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/
%{
    #include <iostream>
    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
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
/// código adicinoal aquí

%}

/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+("."{DIGITO}+)?
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*

/* Cambiar al estado IN_COMMENT */
%x IN_COMMENT 

%%

%{
// inicia la lectura
    loc.step();
%}

    /* inicia la defincion de tokens   */

    /* caracteres ignorados */
"/*"           { BEGIN(IN_COMMENT); } /* Cambiar al estado IN_COMMENT */
<IN_COMMENT>{
  "*/"        { BEGIN(INITIAL); }    /* Volver al estado inicial */
  [^*\n]+     { }                    /* Ignorar todo lo demás */
  \n          { loc.lines(yyleng);loc.step(); }        /* Contar las nuevas líneas */
  "*"         { /* Ignorar */ }      /* Ignorar los asteriscos */
  "*"+        { /* Ignorar */ }      /* Ignorar más de un asterisco */
}
"//"[^\n]*            ; /* comentarios de una linea */
\n                  {loc.lines(yyleng);loc.step();}
[ \t\v\r\n\f]             {loc.step();} /* caracteres en blanco */                
    /* Lexemas */
    /* defincion moderna
        token::ID ID sin caracteres especiales
    */
    /* defincion clásica / para caracteres especiales */

"+"     return Parser::symbol_type( token::SUMA, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"*"     return Parser::symbol_type( token::POR, loc );
"/"     return Parser::symbol_type( token::DIV, loc );
"%"     return Parser::symbol_type( token::MOD, loc );
"++"     return Parser::symbol_type( token::INC, loc );

">"     return Parser::symbol_type( token::MAY, loc );
"<"     return Parser::symbol_type( token::MEN, loc );
">="     return Parser::symbol_type( token::MAY_IG, loc );
"<="     return Parser::symbol_type( token::MEN_IG, loc );
"!="     return Parser::symbol_type( token::DIF, loc );
"=="     return Parser::symbol_type( token::IG, loc );

"&&"     return Parser::symbol_type( token::AND, loc );
"||"     return Parser::symbol_type( token::OR, loc );
"!"  return Parser::symbol_type(token::NOT, loc);

";"     return Parser::symbol_type( token_type(';'), loc );
"="     return Parser::symbol_type( token_type('='), loc );
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
"return"    return Parser::symbol_type( token::RRETURN, loc );
"atoi"  return Parser::symbol_type( token::RATOI, loc );
"atof"  return Parser::symbol_type( token::RATOF, loc );
"iota"  return Parser::symbol_type( token::RIOTA, loc );
"mean"  return Parser::symbol_type( token::RMEAN, loc );
"median"  return Parser::symbol_type( token::RMEDIAN, loc );
"mode"  return Parser::symbol_type( token::RMODE, loc );
"NULL"    return Parser::symbol_type( token::NLL, loc);

    /* VECTOR FUNCTIONS  */
"push_back"    return Parser::symbol_type( token::VPBACK, loc );
"get"    return Parser::symbol_type( token::VGET, loc );
"remove"    return Parser::symbol_type( token::VREMOVE, loc );
"size"    return Parser::symbol_type( token::VSIZE, loc );
"push_front"    return Parser::symbol_type( token::VPFRONT, loc );

    /* TIPOS DE DATOS */
"int"    return Parser::symbol_type( token::INT, loc );
"float"  return Parser::symbol_type( token::FLOAT, loc );
"string"    return Parser::symbol_type( token::TSTRING, loc );
"bool"    return Parser::symbol_type( token::BOOLEAN, loc );
"true"    return Parser::symbol_type( token::RTRUE, loc );
"false"    return Parser::symbol_type( token::RFALSE, loc );
"struct"    return Parser::symbol_type( token::STRUCT, loc );
"vector"  return Parser::symbol_type(token::RVECTOR, loc);

{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores

