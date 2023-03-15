// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 90 "parser.y"
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx); 

#line 49 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 141 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Calc::ParserCtx & ctx_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      ctx (ctx_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.YY_MOVE_OR_COPY< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_INCREMENT: // INCREMENT
      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_EXPRESSION: // EXPRESSION
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.YY_MOVE_OR_COPY< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_MAYEQU: // MAYEQU
      case symbol_kind::S_MENEQU: // MENEQU
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_DIFF: // DIFF
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_INCREMENT: // INCREMENT
      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_EXPRESSION: // EXPRESSION
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.move< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_MAYEQU: // MAYEQU
      case symbol_kind::S_MENEQU: // MENEQU
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_DIFF: // DIFF
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.copy< TipoDato > (that.value);
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_INCREMENT: // INCREMENT
      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_EXPRESSION: // EXPRESSION
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.copy< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_MAYEQU: // MAYEQU
      case symbol_kind::S_MENEQU: // MENEQU
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_DIFF: // DIFF
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (that.value);
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_INCREMENT: // INCREMENT
      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (that.value);
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_EXPRESSION: // EXPRESSION
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.move< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_MAYEQU: // MAYEQU
      case symbol_kind::S_MENEQU: // MENEQU
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_DIFF: // DIFF
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 726 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 732 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 738 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 744 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 750 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 756 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_ARRAY: // ARRAY
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_NLL: // NLL
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_INC: // INC
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_MOD: // MOD
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_RWHILE: // RWHILE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 894 "parser.cpp"
        break;

      case symbol_kind::S_RFOR: // RFOR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 900 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 906 "parser.cpp"
        break;

      case symbol_kind::S_MEDIA: // MEDIA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 912 "parser.cpp"
        break;

      case symbol_kind::S_MEDIANA: // MEDIANA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 918 "parser.cpp"
        break;

      case symbol_kind::S_MODA: // MODA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 924 "parser.cpp"
        break;

      case symbol_kind::S_RATOI: // RATOI
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 930 "parser.cpp"
        break;

      case symbol_kind::S_RATOF: // RATOF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 936 "parser.cpp"
        break;

      case symbol_kind::S_RIOTA: // RIOTA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 942 "parser.cpp"
        break;

      case symbol_kind::S_RBREAK: // RBREAK
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 948 "parser.cpp"
        break;

      case symbol_kind::S_RCONTINUE: // RCONTINUE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 954 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 960 "parser.cpp"
        break;

      case symbol_kind::S_MAYOR: // MAYOR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 966 "parser.cpp"
        break;

      case symbol_kind::S_MENOR: // MENOR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 972 "parser.cpp"
        break;

      case symbol_kind::S_MAYEQU: // MAYEQU
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 978 "parser.cpp"
        break;

      case symbol_kind::S_MENEQU: // MENEQU
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 984 "parser.cpp"
        break;

      case symbol_kind::S_EQU: // EQU
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 990 "parser.cpp"
        break;

      case symbol_kind::S_DIFF: // DIFF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 996 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1002 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1008 "parser.cpp"
        break;

      case symbol_kind::S_NOT: // NOT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1014 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1020 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1026 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1032 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1038 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1044 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1050 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1056 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1062 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1068 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1074 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1080 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1086 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1092 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1098 "parser.cpp"
        break;

      case symbol_kind::S_EXPRESSION: // EXPRESSION
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1104 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1110 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1116 "parser.cpp"
        break;

      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1122 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1128 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1134 "parser.cpp"
        break;

      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1140 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1146 "parser.cpp"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1152 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1158 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1164 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1170 "parser.cpp"
        break;

      case symbol_kind::S_ATOI: // ATOI
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1176 "parser.cpp"
        break;

      case symbol_kind::S_ATOF: // ATOF
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1182 "parser.cpp"
        break;

      case symbol_kind::S_IOTA: // IOTA
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1188 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1194 "parser.cpp"
        break;

      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1200 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1206 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1212 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1218 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 179 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1224 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner, loc, ctx));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TYPES: // TYPES
        yylhs.value.emplace< TipoDato > ();
        break;

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_INCREMENT: // INCREMENT
      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_CALL_EXP: // CALL_EXP
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< func_main* > ();
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_EXPRESSION: // EXPRESSION
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CALL_INST: // CALL_INST
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        yylhs.value.emplace< map_struct_dec* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_ARRAY: // ARRAY
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_SUMA: // SUMA
      case symbol_kind::S_MENOS: // MENOS
      case symbol_kind::S_POR: // POR
      case symbol_kind::S_DIV: // DIV
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_RWHILE: // RWHILE
      case symbol_kind::S_RFOR: // RFOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_MAYOR: // MAYOR
      case symbol_kind::S_MENOR: // MENOR
      case symbol_kind::S_MAYEQU: // MAYEQU
      case symbol_kind::S_MENEQU: // MENEQU
      case symbol_kind::S_EQU: // EQU
      case symbol_kind::S_DIFF: // DIFF
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // START: MAIN
#line 187 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1589 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 193 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1600 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNCTION
#line 202 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1609 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNCTION
#line 207 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1618 "parser.cpp"
    break;

  case 6: // FUNCTION: TYPES ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
#line 214 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1626 "parser.cpp"
    break;

  case 7: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 218 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1634 "parser.cpp"
    break;

  case 8: // FUNCTION_LIST: FUNCTION_LIST ',' TYPES ID
#line 224 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1643 "parser.cpp"
    break;

  case 9: // FUNCTION_LIST: TYPES ID
#line 229 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1652 "parser.cpp"
    break;

  case 10: // MAIN: TYPES RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 236 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < TipoDato > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1660 "parser.cpp"
    break;

  case 11: // LIST_INST: LIST_INST INSTRUCTION
#line 242 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1669 "parser.cpp"
    break;

  case 12: // LIST_INST: INSTRUCTION
#line 247 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1678 "parser.cpp"
    break;

  case 13: // INSTRUCTION: PRINT ';'
#line 253 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1684 "parser.cpp"
    break;

  case 14: // INSTRUCTION: EXPRESSION ';'
#line 254 "parser.y"
                            {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1690 "parser.cpp"
    break;

  case 15: // INSTRUCTION: IF
#line 255 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1696 "parser.cpp"
    break;

  case 16: // INSTRUCTION: WHILE
#line 256 "parser.y"
                    { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1702 "parser.cpp"
    break;

  case 17: // INSTRUCTION: FOR
#line 257 "parser.y"
                  { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1708 "parser.cpp"
    break;

  case 18: // INSTRUCTION: DECLARATION ';'
#line 258 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1714 "parser.cpp"
    break;

  case 19: // INSTRUCTION: ASSIGNATION ';'
#line 259 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1720 "parser.cpp"
    break;

  case 20: // INSTRUCTION: DECLARE_STRUCT
#line 260 "parser.y"
                             { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1726 "parser.cpp"
    break;

  case 21: // INSTRUCTION: CREATE_STRUCT
#line 261 "parser.y"
                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1732 "parser.cpp"
    break;

  case 22: // INSTRUCTION: BREAK ';'
#line 262 "parser.y"
                        {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1738 "parser.cpp"
    break;

  case 23: // INSTRUCTION: CONTINUE ';'
#line 263 "parser.y"
                           {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1744 "parser.cpp"
    break;

  case 24: // INSTRUCTION: RETURN ';'
#line 264 "parser.y"
                         {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1750 "parser.cpp"
    break;

  case 25: // INSTRUCTION: CALL_INST
#line 265 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1756 "parser.cpp"
    break;

  case 26: // PRINT: PRINTF PARA EXP PARC
#line 271 "parser.y"
                             { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1762 "parser.cpp"
    break;

  case 27: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 275 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1770 "parser.cpp"
    break;

  case 28: // IF: RIF EXP LLAVA LIST_INST LLAVC
#line 279 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (),nullptr,nullptr);
    }
#line 1778 "parser.cpp"
    break;

  case 29: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
#line 283 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > (),nullptr);
    }
#line 1786 "parser.cpp"
    break;

  case 30: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 287 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1794 "parser.cpp"
    break;

  case 31: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 293 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1803 "parser.cpp"
    break;

  case 32: // ELSEIF_LIST: ELSEIF
#line 298 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1812 "parser.cpp"
    break;

  case 33: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 305 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1820 "parser.cpp"
    break;

  case 34: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 310 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1826 "parser.cpp"
    break;

  case 35: // ELSE: %empty
#line 311 "parser.y"
             { }
#line 1832 "parser.cpp"
    break;

  case 36: // WHILE: RWHILE PARA EXP PARC LLAVA LIST_INST LLAVC
#line 315 "parser.y"
                                                  {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1838 "parser.cpp"
    break;

  case 37: // FOR: RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC
#line 318 "parser.y"
                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line, yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1844 "parser.cpp"
    break;

  case 38: // EXPRESSION: EXP
#line 321 "parser.y"
                 {yylhs.value.as < instruction* > () = new func_expression(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 1850 "parser.cpp"
    break;

  case 39: // DECLARE_STRUCT: STRUCT ID LLAVA DECLARE_LIST LLAVC
#line 324 "parser.y"
                                                   {yylhs.value.as < instruction* > () = new declare_struct(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 1856 "parser.cpp"
    break;

  case 40: // DECLARE_LIST: DECLARE_LIST TYPES ID ';'
#line 328 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1865 "parser.cpp"
    break;

  case 41: // DECLARE_LIST: TYPES ID ';'
#line 333 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 1874 "parser.cpp"
    break;

  case 42: // CREATE_STRUCT: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 340 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 1882 "parser.cpp"
    break;

  case 43: // EXP_LIST: EXP_LIST ',' EXP
#line 346 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1891 "parser.cpp"
    break;

  case 44: // EXP_LIST: EXP
#line 351 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1900 "parser.cpp"
    break;

  case 45: // DECLARATION: TYPES ID '=' EXP
#line 357 "parser.y"
                               {yylhs.value.as < instruction* > () = new declare(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1906 "parser.cpp"
    break;

  case 46: // DECLARATION: TYPES ID
#line 358 "parser.y"
                       {yylhs.value.as < instruction* > () = new declare(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),nullptr);}
#line 1912 "parser.cpp"
    break;

  case 47: // ASSIGNATION: ID '=' EXP
#line 360 "parser.y"
                         {yylhs.value.as < instruction* > () = new assign(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1918 "parser.cpp"
    break;

  case 48: // BREAK: RBREAK
#line 363 "parser.y"
               {yylhs.value.as < instruction* > () = new func_break(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 1924 "parser.cpp"
    break;

  case 49: // CONTINUE: RCONTINUE
#line 366 "parser.y"
                     {yylhs.value.as < instruction* > () = new func_continue(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 1930 "parser.cpp"
    break;

  case 50: // RETURN: RRETURN EXP
#line 369 "parser.y"
                     { yylhs.value.as < instruction* > () = new func_return(0,0,yystack_[0].value.as < expression* > ()); }
#line 1936 "parser.cpp"
    break;

  case 51: // RETURN: RRETURN
#line 370 "parser.y"
                  { yylhs.value.as < instruction* > () = new func_return(0,0,nullptr); }
#line 1942 "parser.cpp"
    break;

  case 52: // TYPES: INT
#line 384 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1948 "parser.cpp"
    break;

  case 53: // TYPES: TSTRING
#line 385 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 1954 "parser.cpp"
    break;

  case 54: // TYPES: BOOLEAN
#line 386 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1960 "parser.cpp"
    break;

  case 55: // TYPES: FLOAT
#line 387 "parser.y"
            { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1966 "parser.cpp"
    break;

  case 56: // TYPES: VOID
#line 388 "parser.y"
           {yylhs.value.as < TipoDato > () = VOID;}
#line 1972 "parser.cpp"
    break;

  case 57: // TYPES: ARRAY
#line 389 "parser.y"
            { yylhs.value.as < TipoDato > () = ARRAY; }
#line 1978 "parser.cpp"
    break;

  case 58: // EXP: EXP SUMA EXP
#line 393 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1984 "parser.cpp"
    break;

  case 59: // EXP: EXP MENOS EXP
#line 394 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1990 "parser.cpp"
    break;

  case 60: // EXP: EXP POR EXP
#line 395 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1996 "parser.cpp"
    break;

  case 61: // EXP: EXP DIV EXP
#line 396 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2002 "parser.cpp"
    break;

  case 62: // EXP: EXP MOD EXP
#line 397 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2008 "parser.cpp"
    break;

  case 63: // EXP: INCREMENT
#line 399 "parser.y"
                {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2014 "parser.cpp"
    break;

  case 64: // EXP: EXP MAYOR EXP
#line 401 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">");}
#line 2020 "parser.cpp"
    break;

  case 65: // EXP: EXP MAYEQU EXP
#line 402 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">=");}
#line 2026 "parser.cpp"
    break;

  case 66: // EXP: EXP MENOR EXP
#line 403 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<");}
#line 2032 "parser.cpp"
    break;

  case 67: // EXP: EXP MENEQU EXP
#line 404 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<=");}
#line 2038 "parser.cpp"
    break;

  case 68: // EXP: EXP EQU EXP
#line 405 "parser.y"
                  {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "==");}
#line 2044 "parser.cpp"
    break;

  case 69: // EXP: EXP DIFF EXP
#line 406 "parser.y"
                   {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!=");}
#line 2050 "parser.cpp"
    break;

  case 70: // EXP: EXP AND EXP
#line 408 "parser.y"
                  {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&");}
#line 2056 "parser.cpp"
    break;

  case 71: // EXP: EXP OR EXP
#line 409 "parser.y"
                 {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||");}
#line 2062 "parser.cpp"
    break;

  case 72: // EXP: NOT EXP
#line 411 "parser.y"
    {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
#line 2070 "parser.cpp"
    break;

  case 73: // EXP: MENOS EXP
#line 415 "parser.y"
                {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < expression* > (),new primitive(0,0,INTEGER, "", 0,0.0,false),"NEG");
        }
#line 2078 "parser.cpp"
    break;

  case 74: // EXP: PARA EXP PARC
#line 419 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2084 "parser.cpp"
    break;

  case 75: // EXP: ATOI
#line 420 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2090 "parser.cpp"
    break;

  case 76: // EXP: ATOF
#line 421 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2096 "parser.cpp"
    break;

  case 77: // EXP: IOTA
#line 422 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2102 "parser.cpp"
    break;

  case 78: // EXP: LLAVA EXP_LIST LLAVC
#line 423 "parser.y"
                           { yylhs.value.as < expression* > () = new expression_array(0,0,yystack_[1].value.as < list_expression* > ()); }
#line 2108 "parser.cpp"
    break;

  case 79: // EXP: CALL_EXP
#line 424 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2114 "parser.cpp"
    break;

  case 80: // EXP: PRIMITIVE
#line 426 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2120 "parser.cpp"
    break;

  case 81: // ATOI: RATOI PARA PRIMITIVE PARC
#line 430 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atoi(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2126 "parser.cpp"
    break;

  case 82: // ATOF: RATOF PARA PRIMITIVE PARC
#line 433 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atof(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2132 "parser.cpp"
    break;

  case 83: // IOTA: RIOTA PARA PRIMITIVE PARC
#line 436 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_iota(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2138 "parser.cpp"
    break;

  case 84: // INCREMENT: PREFIX_INCREMENT
#line 440 "parser.y"
                            { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2144 "parser.cpp"
    break;

  case 85: // INCREMENT: EXP INC
#line 441 "parser.y"
                      { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, yystack_[1].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
#line 2150 "parser.cpp"
    break;

  case 86: // PREFIX_INCREMENT: INC EXP
#line 444 "parser.y"
                          { yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++B"); }
#line 2156 "parser.cpp"
    break;

  case 87: // PREFIX_INCREMENT: EXP PREFIX_INCREMENT
#line 445 "parser.y"
                                       {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2162 "parser.cpp"
    break;

  case 88: // PRIMITIVE: NUMERO
#line 448 "parser.y"
                   {
            std::string cadena = yystack_[0].value.as < std::string > ();
            if(cadena.find(".") == -1)
            {
                int num = stoi(yystack_[0].value.as < std::string > ());
                yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,INTEGER, "", num,0.0,false); }
            else
            {
                float num = stof(yystack_[0].value.as < std::string > ());
                yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,FLOAT, "", 0, num,false);}

            }
#line 2179 "parser.cpp"
    break;

  case 89: // PRIMITIVE: STRING
#line 461 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,STRING,str2,0,0.0,false);
        }
#line 2189 "parser.cpp"
    break;

  case 90: // PRIMITIVE: BOOLTRUE
#line 466 "parser.y"
                  {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, true);}
#line 2195 "parser.cpp"
    break;

  case 91: // PRIMITIVE: BOOLFALSE
#line 467 "parser.y"
                   {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, false);}
#line 2201 "parser.cpp"
    break;

  case 92: // PRIMITIVE: LIST_ARR
#line 468 "parser.y"
                  {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2207 "parser.cpp"
    break;

  case 93: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 471 "parser.y"
                                  { yylhs.value.as < expression* > () = new array_access(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2213 "parser.cpp"
    break;

  case 94: // LIST_ARR: LIST_ARR '.' ID
#line 472 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 2219 "parser.cpp"
    break;

  case 95: // LIST_ARR: ID
#line 473 "parser.y"
             {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ()); }
#line 2225 "parser.cpp"
    break;

  case 96: // CALL_EXP: ID PARA EXP_LIST PARC
#line 475 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 2231 "parser.cpp"
    break;

  case 97: // CALL_EXP: ID PARA PARC
#line 476 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 2237 "parser.cpp"
    break;

  case 98: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 479 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 2243 "parser.cpp"
    break;

  case 99: // CALL_INST: ID PARA PARC ';'
#line 480 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr); }
#line 2249 "parser.cpp"
    break;


#line 2253 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char Parser::yypact_ninf_ = -75;

  const signed char Parser::yytable_ninf_ = -88;

  const short
  Parser::yypact_[] =
  {
     265,   -75,   -75,   -75,   -75,   -75,   -75,    20,   265,   -75,
     -75,    14,   -75,   -75,   -75,     9,    17,   107,    26,    18,
     -14,    39,    31,   771,    34,   265,   -75,   771,   -75,    -7,
     -75,    48,   -75,   -75,  1194,  1194,  1194,  1194,  1194,    45,
      46,    47,    49,    57,    58,   -75,   -75,  1194,  1194,   379,
     -75,    10,   -75,   -75,   -75,    21,   -75,   -75,    22,    23,
      24,    44,    54,    93,  1047,   -75,   -75,   -75,   -75,   -75,
     -75,   -13,   -75,   -75,   771,    95,   428,   126,  1194,     6,
      87,   802,    -9,  1047,  1302,  1285,  1096,  1194,   265,  1194,
     131,   131,   131,  1047,  1211,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,    56,  1194,  1194,  1194,  1194,   212,
    1194,  1194,  1194,  1194,  1194,  1194,  1194,  1194,  1194,  1047,
      13,  1194,   103,   477,   -75,   -75,    64,    -6,  1047,    66,
     265,   194,   -75,   -75,  1194,   771,   851,    69,   900,   -75,
     108,   109,   111,  1194,  1302,  1302,    65,    65,    65,  1285,
    1285,  1285,  1285,  1248,  1248,  1211,  1211,   949,   -75,   -75,
     -75,    76,   116,  1325,   129,   -75,     2,  1047,   526,   279,
     121,  1194,   -75,   -75,   -75,   -75,  1047,   -75,   -75,  1194,
     -75,   142,   100,   -75,   117,   771,   329,     4,   102,   -75,
       0,   117,   -75,   -75,   575,  1194,   -75,   -75,   771,  1194,
     -75,   -75,   -75,   998,   624,  1145,   139,   -75,   771,   771,
     673,   722,   -75,   -75
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    53,    55,    54,    57,    52,    56,     0,     0,     5,
       2,     0,     1,     4,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    88,    95,
      89,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    51,     0,     0,
      12,     0,    15,    16,    17,     0,    20,    21,     0,     0,
       0,     0,     0,     0,    38,    75,    76,    77,    63,    84,
      80,    92,    79,    25,     0,     0,     0,     0,     0,     0,
      95,     0,     0,    44,    73,    86,     0,     0,     0,     0,
       0,     0,     0,    50,    72,     7,    11,    13,    14,    18,
      19,    22,    23,    24,    46,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     8,    10,    97,     0,    47,     0,
       0,     0,    74,    78,     0,     0,     0,     0,     0,    95,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    64,
      66,    65,    67,    68,    69,    70,    71,     0,    94,     6,
      99,    96,     0,     0,     0,    97,     0,    43,     0,    44,
       0,     0,    26,    81,    82,    83,    45,    93,    98,     0,
      39,     0,     0,    96,    28,     0,     0,     0,     0,    41,
       0,    29,    32,    30,     0,     0,    42,    40,     0,     0,
      31,    27,    36,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    33,    37
  };

  const short
  Parser::yypgoto_[] =
  {
     -75,   -75,   -75,   149,   -75,   150,   -25,   -43,   -75,   -75,
     -75,   -32,   -22,   -75,   -75,   -75,   -75,   -75,   -75,   -74,
      78,   -75,   -75,   -75,   -75,    19,   -23,   -75,   -75,   -75,
     -75,   110,   -53,   -75,   -75,   -75
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    20,    10,    49,    50,    51,    52,
     191,   192,   193,    53,    54,    55,    56,   163,    57,    82,
      58,    59,    60,    61,    62,    63,   119,    65,    66,    67,
      68,    69,    70,    71,    72,    73
  };

  const short
  Parser::yytable_[] =
  {
      64,    24,    76,   127,    64,   121,    96,    77,   133,   161,
     129,    81,    83,    84,    85,    86,   198,   183,    15,    11,
      12,   196,   130,    17,    93,    94,    64,    11,   -87,   199,
     -87,    18,   -87,    96,    23,    16,    21,   140,   141,   142,
      25,    22,   122,    26,    75,   134,    78,    27,   134,   123,
      74,    64,    79,    64,    83,   128,   134,   166,   134,    87,
      88,    89,    97,    90,   136,   -87,   138,   -87,    28,    80,
      30,    91,    92,    98,    99,   100,   101,    32,    33,    34,
      96,    35,   144,   145,   146,   147,    85,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   102,   104,   157,   124,
      64,   131,    42,    43,    44,   187,   103,   158,    83,   143,
     168,   167,   169,     1,     2,     3,   160,     4,     5,   162,
     176,   171,    19,   173,   174,    96,   175,     6,   178,    28,
      80,    30,   179,   182,    28,   139,    30,   185,    32,    33,
      34,   126,    35,    32,    33,    64,   188,   190,   186,   164,
      36,    96,   189,    37,   197,   209,    83,    13,    14,   200,
     194,    96,    64,    42,    43,    44,   137,    96,    96,   201,
       0,    64,   203,   204,   120,    64,   205,    48,     0,     0,
       0,    64,   181,   210,   211,   169,    64,    64,    64,     0,
       0,   120,     0,   120,   120,   120,   120,    28,    80,    30,
       0,     0,     0,   120,   120,     0,    32,    33,    34,   165,
      35,     0,     0,     0,     0,    28,    80,    30,    36,     0,
       0,    37,     0,     0,    32,    33,    34,     0,    35,   120,
       0,    42,    43,    44,     0,     0,    36,     0,   120,    37,
       0,     0,     0,     0,     0,    48,   120,     0,   120,    42,
      43,    44,     0,     0,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,     0,     0,
       0,     1,     2,     3,     0,     4,     5,   120,     0,   120,
       0,     0,    28,    80,    30,     6,   120,     0,     0,     0,
       0,    32,    33,    34,     0,    35,   120,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,   120,     0,   120,    42,    43,    44,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
      48,   -38,    28,    80,    30,     0,     0,     0,     0,     0,
       0,    32,    33,    34,     0,    35,     0,     0,     0,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    44,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
      48,   195,    28,    29,    30,     1,     2,     3,    31,     4,
       5,    32,    33,    34,     0,    35,    95,     0,     0,     6,
       0,     0,     0,    36,     0,     0,    37,     0,    38,     0,
      39,    40,    41,     0,     0,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    28,    29,    30,     1,     2,     3,    31,     4,     5,
      32,    33,    34,     0,    35,   125,     0,     0,     6,     0,
       0,     0,    36,     0,     0,    37,     0,    38,     0,    39,
      40,    41,     0,     0,     0,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,    48,
      28,    29,    30,     1,     2,     3,    31,     4,     5,    32,
      33,    34,     0,    35,   159,     0,     0,     6,     0,     0,
       0,    36,     0,     0,    37,     0,    38,     0,    39,    40,
      41,     0,     0,     0,    42,    43,    44,    45,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    28,
      29,    30,     1,     2,     3,    31,     4,     5,    32,    33,
      34,     0,    35,   184,     0,     0,     6,     0,     0,     0,
      36,     0,     0,    37,     0,    38,     0,    39,    40,    41,
       0,     0,     0,    42,    43,    44,    45,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    28,    29,
      30,     1,     2,     3,    31,     4,     5,    32,    33,    34,
       0,    35,   202,     0,     0,     6,     0,     0,     0,    36,
       0,     0,    37,     0,    38,     0,    39,    40,    41,     0,
       0,     0,    42,    43,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    28,    29,    30,
       1,     2,     3,    31,     4,     5,    32,    33,    34,     0,
      35,   207,     0,     0,     6,     0,     0,     0,    36,     0,
       0,    37,     0,    38,     0,    39,    40,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    28,    29,    30,     1,
       2,     3,    31,     4,     5,    32,    33,    34,     0,    35,
     212,     0,     0,     6,     0,     0,     0,    36,     0,     0,
      37,     0,    38,     0,    39,    40,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,    48,    28,    29,    30,     1,     2,
       3,    31,     4,     5,    32,    33,    34,     0,    35,   213,
       0,     0,     6,     0,     0,     0,    36,     0,     0,    37,
       0,    38,     0,    39,    40,    41,     0,     0,     0,    42,
      43,    44,    45,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    28,    29,    30,     1,     2,     3,
      31,     4,     5,    32,    33,    34,     0,    35,     0,     0,
       0,     6,     0,     0,     0,    36,     0,     0,    37,     0,
      38,     0,    39,    40,    41,    28,    80,    30,    42,    43,
      44,    45,    46,    47,    32,    33,    34,   132,    35,     0,
       0,     0,    48,     0,     0,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,    48,    28,    80,    30,     0,     0,     0,
       0,     0,     0,    32,    33,    34,   170,    35,     0,     0,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    42,    43,
      44,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,    48,    28,    80,    30,     0,     0,     0,     0,
       0,     0,    32,    33,    34,   172,    35,     0,     0,     0,
       0,     0,     0,   105,   106,   107,   108,   109,   110,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    43,    44,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,    48,    28,    80,    30,     0,     0,     0,     0,     0,
       0,    32,    33,    34,     0,    35,     0,     0,   177,     0,
       0,     0,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,    44,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
      48,    28,    80,    30,     0,     0,     0,     0,     0,     0,
      32,    33,    34,   206,    35,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,    48,
      28,    80,    30,     0,     0,     0,     0,     0,     0,    32,
      33,    34,     0,    35,     0,     0,     0,     0,     0,     0,
     105,   106,   107,   108,   109,   110,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,    48,    28,
      80,    30,     0,     0,     0,     0,     0,     0,    32,    33,
      34,     0,   135,     0,     0,     0,     0,     0,     0,   105,
     106,   107,   108,   109,   110,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,    44,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,    48,    28,    80,
      30,     0,     0,     0,     0,     0,     0,    32,    33,    34,
       0,   208,     0,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    44,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,    48,    28,    80,    30,
       0,     0,     0,     0,     0,     0,    32,    33,    34,     0,
      35,     0,     0,     0,    28,    80,    30,     0,    36,     0,
       0,    37,     0,    32,    33,    34,     0,    35,     0,     0,
       0,    42,    43,    44,   105,   106,   107,   108,   109,   110,
       0,     0,     0,     0,     0,    48,     0,     0,    42,    43,
      44,    28,    80,    30,   111,   112,   113,   114,   115,   116,
      32,    33,    34,     0,    35,     0,     0,     0,     0,     0,
       0,   105,   106,   107,   108,   109,   110,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    28,    80,
      30,   111,   112,   113,   114,     0,     0,    32,    33,    34,
       0,    35,     0,     0,     0,    28,    80,    30,   105,   106,
     107,   108,   109,   110,    32,    33,    34,     0,    35,     0,
       0,     0,    42,    43,    44,     0,     0,   107,   108,     0,
     110,     1,     2,     3,     0,     4,     5,     0,     0,    42,
      43,    44,   180,     0,     0,     6
  };

  const short
  Parser::yycheck_[] =
  {
      23,    15,    27,    77,    27,    18,    49,    14,    17,    15,
       4,    34,    35,    36,    37,    38,    16,    15,     4,     0,
       0,    17,    16,    14,    47,    48,    49,     8,    15,    29,
      17,    14,    19,    76,    16,    21,    17,    90,    91,    92,
      54,    15,    55,     4,    25,    54,    53,    16,    54,    74,
      16,    74,     4,    76,    77,    78,    54,   131,    54,    14,
      14,    14,    52,    14,    87,    52,    89,    54,     3,     4,
       5,    14,    14,    52,    52,    52,    52,    12,    13,    14,
     123,    16,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    52,     4,   121,     4,
     123,    14,    37,    38,    39,   179,    52,     4,   131,    53,
     135,   134,   135,     6,     7,     8,    52,    10,    11,    53,
     143,    52,    15,    15,    15,   168,    15,    20,    52,     3,
       4,     5,    16,     4,     3,     4,     5,    16,    12,    13,
      14,    15,    16,    12,    13,   168,     4,    30,   171,   130,
      24,   194,    52,    27,    52,    16,   179,     8,     8,   191,
     185,   204,   185,    37,    38,    39,    88,   210,   211,   191,
      -1,   194,   195,   198,    64,   198,   199,    51,    -1,    -1,
      -1,   204,   163,   208,   209,   208,   209,   210,   211,    -1,
      -1,    81,    -1,    83,    84,    85,    86,     3,     4,     5,
      -1,    -1,    -1,    93,    94,    -1,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,     3,     4,     5,    24,    -1,
      -1,    27,    -1,    -1,    12,    13,    14,    -1,    16,   119,
      -1,    37,    38,    39,    -1,    -1,    24,    -1,   128,    27,
      -1,    -1,    -1,    -1,    -1,    51,   136,    -1,   138,    37,
      38,    39,    -1,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,   167,    -1,   169,
      -1,    -1,     3,     4,     5,    20,   176,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,   186,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,   203,    -1,   205,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    20,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    29,    -1,
      31,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,
      -1,    -1,    24,    -1,    -1,    27,    -1,    29,    -1,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      -1,    24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,
      24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,
      -1,    27,    -1,    29,    -1,    31,    32,    33,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      27,    -1,    29,    -1,    31,    32,    33,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    16,    17,
      -1,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    31,    32,    33,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    27,    -1,
      29,    -1,    31,    32,    33,     3,     4,     5,    37,    38,
      39,    40,    41,    42,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    51,    -1,    -1,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    -1,    -1,    19,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,     3,     4,     5,    -1,    24,    -1,
      -1,    27,    -1,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    37,    38,    39,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    37,    38,
      39,     3,     4,     5,    43,    44,    45,    46,    47,    48,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,     3,     4,
       5,    43,    44,    45,    46,    -1,    -1,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,     3,     4,     5,    23,    24,
      25,    26,    27,    28,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    37,    38,    39,    -1,    -1,    25,    26,    -1,
      28,     6,     7,     8,    -1,    10,    11,    -1,    -1,    37,
      38,    39,    17,    -1,    -1,    20
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     6,     7,     8,    10,    11,    20,    57,    58,    59,
      61,    81,     0,    59,    61,     4,    21,    14,    14,    15,
      60,    81,    15,    16,    15,    54,     4,    16,     3,     4,
       5,     9,    12,    13,    14,    16,    24,    27,    29,    31,
      32,    33,    37,    38,    39,    40,    41,    42,    51,    62,
      63,    64,    65,    69,    70,    71,    72,    74,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    16,    81,    62,    14,    53,     4,
       4,    82,    75,    82,    82,    82,    82,    14,    14,    14,
      14,    14,    14,    82,    82,    17,    63,    52,    52,    52,
      52,    52,    52,    52,     4,    23,    24,    25,    26,    27,
      28,    43,    44,    45,    46,    47,    48,    49,    50,    82,
      87,    18,    55,    62,     4,    17,    15,    75,    82,     4,
      16,    14,    15,    17,    54,    16,    82,    76,    82,     4,
      88,    88,    88,    53,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,     4,    17,
      52,    15,    53,    73,    81,    15,    75,    82,    62,    82,
      15,    52,    15,    15,    15,    15,    82,    19,    52,    16,
      17,    81,     4,    15,    17,    16,    82,    75,     4,    52,
      30,    66,    67,    68,    62,    52,    17,    52,    16,    29,
      67,    68,    17,    82,    62,    82,    15,    17,    16,    16,
      62,    62,    17,    17
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    65,    65,    65,
      65,    66,    66,    67,    68,    68,    69,    70,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    78,    79,
      80,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    84,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    89,    89,    89,    90,    90,    91,    91
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     8,     7,     4,     2,
       7,     2,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     2,     1,     4,     7,     5,     6,
       6,     2,     1,     6,     4,     0,     7,    11,     1,     5,
       4,     3,     7,     3,     1,     4,     2,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     1,     3,     1,
       1,     4,     4,     4,     1,     2,     2,     2,     1,     1,
       1,     1,     1,     4,     3,     1,     4,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING",
  "TSTRING", "FLOAT", "BOOLEAN", "STRUCT", "ARRAY", "INT", "BOOLTRUE",
  "BOOLFALSE", "PARA", "PARC", "LLAVA", "LLAVC", "CORA", "CORC", "VOID",
  "RMAIN", "NLL", "SUMA", "MENOS", "POR", "DIV", "INC", "MOD", "RIF",
  "RELSE", "RWHILE", "RFOR", "PRINTF", "MEDIA", "MEDIANA", "MODA", "RATOI",
  "RATOF", "RIOTA", "RBREAK", "RCONTINUE", "RRETURN", "MAYOR", "MENOR",
  "MAYEQU", "MENEQU", "EQU", "DIFF", "AND", "OR", "NOT", "';'", "'='",
  "','", "'.'", "$accept", "START", "LIST_FUNC", "FUNCTION",
  "FUNCTION_LIST", "MAIN", "LIST_INST", "INSTRUCTION", "PRINT", "IF",
  "ELSEIF_LIST", "ELSEIF", "ELSE", "WHILE", "FOR", "EXPRESSION",
  "DECLARE_STRUCT", "DECLARE_LIST", "CREATE_STRUCT", "EXP_LIST",
  "DECLARATION", "ASSIGNATION", "BREAK", "CONTINUE", "RETURN", "TYPES",
  "EXP", "ATOI", "ATOF", "IOTA", "INCREMENT", "PREFIX_INCREMENT",
  "PRIMITIVE", "LIST_ARR", "CALL_EXP", "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   186,   186,   192,   201,   206,   213,   217,   223,   228,
     235,   241,   246,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   271,   274,   278,   282,
     286,   292,   297,   304,   310,   311,   315,   318,   321,   324,
     327,   332,   339,   345,   350,   357,   358,   360,   363,   366,
     369,   370,   384,   385,   386,   387,   388,   389,   393,   394,
     395,   396,   397,   399,   401,   402,   403,   404,   405,   406,
     408,   409,   410,   415,   419,   420,   421,   422,   423,   424,
     426,   430,   433,   436,   440,   441,   444,   445,   448,   460,
     466,   467,   468,   471,   472,   473,   475,   476,   479,   480
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2925 "parser.cpp"

#line 483 "parser.y"


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
