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
#line 95 "parser.y"
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

      case symbol_kind::S_GET: // GET
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
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
      case symbol_kind::S_PUSHBACK: // PUSHBACK
      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
      case symbol_kind::S_REMOVE: // REMOVE
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
      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
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
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_VPBACK: // VPBACK
      case symbol_kind::S_VGET: // VGET
      case symbol_kind::S_VREMOVE: // VREMOVE
      case symbol_kind::S_VSIZE: // VSIZE
      case symbol_kind::S_VPFRONT: // VPFRONT
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

      case symbol_kind::S_GET: // GET
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
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
      case symbol_kind::S_PUSHBACK: // PUSHBACK
      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
      case symbol_kind::S_REMOVE: // REMOVE
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
      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
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
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_VPBACK: // VPBACK
      case symbol_kind::S_VGET: // VGET
      case symbol_kind::S_VREMOVE: // VREMOVE
      case symbol_kind::S_VSIZE: // VSIZE
      case symbol_kind::S_VPFRONT: // VPFRONT
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

      case symbol_kind::S_GET: // GET
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
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
      case symbol_kind::S_PUSHBACK: // PUSHBACK
      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
      case symbol_kind::S_REMOVE: // REMOVE
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
      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
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
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_VPBACK: // VPBACK
      case symbol_kind::S_VGET: // VGET
      case symbol_kind::S_VREMOVE: // VREMOVE
      case symbol_kind::S_VSIZE: // VSIZE
      case symbol_kind::S_VPFRONT: // VPFRONT
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

      case symbol_kind::S_GET: // GET
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
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
      case symbol_kind::S_PUSHBACK: // PUSHBACK
      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
      case symbol_kind::S_REMOVE: // REMOVE
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
      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
      case symbol_kind::S_CALL_INST: // CALL_INST
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
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
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_VPBACK: // VPBACK
      case symbol_kind::S_VGET: // VGET
      case symbol_kind::S_VREMOVE: // VREMOVE
      case symbol_kind::S_VSIZE: // VSIZE
      case symbol_kind::S_VPFRONT: // VPFRONT
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
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_RSTRUCT: // RSTRUCT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_RVECTOR: // RVECTOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_NLL: // NLL
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_INC: // INC
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_MOD: // MOD
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_RWHILE: // RWHILE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_RFOR: // RFOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 964 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 970 "parser.cpp"
        break;

      case symbol_kind::S_RMEAN: // RMEAN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 976 "parser.cpp"
        break;

      case symbol_kind::S_RMEDIAN: // RMEDIAN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 982 "parser.cpp"
        break;

      case symbol_kind::S_RMODE: // RMODE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 988 "parser.cpp"
        break;

      case symbol_kind::S_RATOI: // RATOI
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 994 "parser.cpp"
        break;

      case symbol_kind::S_RATOF: // RATOF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1000 "parser.cpp"
        break;

      case symbol_kind::S_RIOTA: // RIOTA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1006 "parser.cpp"
        break;

      case symbol_kind::S_RBREAK: // RBREAK
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1012 "parser.cpp"
        break;

      case symbol_kind::S_RCONTINUE: // RCONTINUE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1018 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1024 "parser.cpp"
        break;

      case symbol_kind::S_MAYOR: // MAYOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1030 "parser.cpp"
        break;

      case symbol_kind::S_MENOR: // MENOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1036 "parser.cpp"
        break;

      case symbol_kind::S_MAYEQU: // MAYEQU
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1042 "parser.cpp"
        break;

      case symbol_kind::S_MENEQU: // MENEQU
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1048 "parser.cpp"
        break;

      case symbol_kind::S_EQU: // EQU
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1054 "parser.cpp"
        break;

      case symbol_kind::S_DIFF: // DIFF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1060 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1066 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1072 "parser.cpp"
        break;

      case symbol_kind::S_NOT: // NOT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1078 "parser.cpp"
        break;

      case symbol_kind::S_VPBACK: // VPBACK
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1084 "parser.cpp"
        break;

      case symbol_kind::S_VGET: // VGET
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1090 "parser.cpp"
        break;

      case symbol_kind::S_VREMOVE: // VREMOVE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1096 "parser.cpp"
        break;

      case symbol_kind::S_VSIZE: // VSIZE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1102 "parser.cpp"
        break;

      case symbol_kind::S_VPFRONT: // VPFRONT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1108 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1114 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1120 "parser.cpp"
        break;

      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1126 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1132 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1138 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1144 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1150 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1156 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1162 "parser.cpp"
        break;

      case symbol_kind::S_PUSHBACK: // PUSHBACK
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1168 "parser.cpp"
        break;

      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1174 "parser.cpp"
        break;

      case symbol_kind::S_GET: // GET
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1180 "parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1186 "parser.cpp"
        break;

      case symbol_kind::S_REMOVE: // REMOVE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1192 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1198 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1204 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1210 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1216 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1222 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1228 "parser.cpp"
        break;

      case symbol_kind::S_EXPRESSION: // EXPRESSION
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1234 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1240 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1246 "parser.cpp"
        break;

      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1252 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1258 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1264 "parser.cpp"
        break;

      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1270 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1276 "parser.cpp"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1282 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1288 "parser.cpp"
        break;

      case symbol_kind::S_MEAN: // MEAN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1294 "parser.cpp"
        break;

      case symbol_kind::S_MEDIAN: // MEDIAN
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1300 "parser.cpp"
        break;

      case symbol_kind::S_MODE: // MODE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1306 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1312 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1318 "parser.cpp"
        break;

      case symbol_kind::S_ATOI: // ATOI
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1324 "parser.cpp"
        break;

      case symbol_kind::S_ATOF: // ATOF
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1330 "parser.cpp"
        break;

      case symbol_kind::S_IOTA: // IOTA
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1336 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1342 "parser.cpp"
        break;

      case symbol_kind::S_PREFIX_INCREMENT: // PREFIX_INCREMENT
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1348 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1354 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1360 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1366 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1372 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1378 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 195 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1384 "parser.cpp"
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

      case symbol_kind::S_GET: // GET
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
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
      case symbol_kind::S_PUSHBACK: // PUSHBACK
      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
      case symbol_kind::S_REMOVE: // REMOVE
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
      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
      case symbol_kind::S_CALL_INST: // CALL_INST
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
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
      case symbol_kind::S_RSTRUCT: // RSTRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_VPBACK: // VPBACK
      case symbol_kind::S_VGET: // VGET
      case symbol_kind::S_VREMOVE: // VREMOVE
      case symbol_kind::S_VSIZE: // VSIZE
      case symbol_kind::S_VPFRONT: // VPFRONT
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
#line 203 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1765 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 209 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1776 "parser.cpp"
    break;

  case 4: // START: LIST_STRUCT LIST_FUNC MAIN
#line 216 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Structs = yystack_[2].value.as < list_instruction* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1788 "parser.cpp"
    break;

  case 5: // LIST_FUNC: LIST_FUNC FUNCTION
#line 226 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1797 "parser.cpp"
    break;

  case 6: // LIST_FUNC: FUNCTION
#line 231 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1806 "parser.cpp"
    break;

  case 7: // LIST_STRUCT: LIST_STRUCT DECLARE_STRUCT
#line 238 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1815 "parser.cpp"
    break;

  case 8: // LIST_STRUCT: DECLARE_STRUCT
#line 243 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1824 "parser.cpp"
    break;

  case 9: // FUNCTION: TYPES ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
#line 250 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1832 "parser.cpp"
    break;

  case 10: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 254 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1840 "parser.cpp"
    break;

  case 11: // FUNCTION: ID ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
#line 258 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,STRUCT,yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1848 "parser.cpp"
    break;

  case 12: // FUNCTION_LIST: FUNCTION_LIST ',' TYPES ID
#line 264 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1857 "parser.cpp"
    break;

  case 13: // FUNCTION_LIST: FUNCTION_LIST ',' RVECTOR MENOR TYPES MAYOR ID
#line 269 "parser.y"
        {
            yystack_[6].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),VECTOR);
            yylhs.value.as < map_struct_dec* > () = yystack_[6].value.as < map_struct_dec* > ();
        }
#line 1866 "parser.cpp"
    break;

  case 14: // FUNCTION_LIST: TYPES ID
#line 274 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1875 "parser.cpp"
    break;

  case 15: // FUNCTION_LIST: RVECTOR MENOR TYPES MAYOR ID
#line 279 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), VECTOR);
        }
#line 1884 "parser.cpp"
    break;

  case 16: // MAIN: TYPES RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 286 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < TipoDato > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1892 "parser.cpp"
    break;

  case 17: // LIST_INST: LIST_INST INSTRUCTION
#line 292 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1901 "parser.cpp"
    break;

  case 18: // LIST_INST: INSTRUCTION
#line 297 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1910 "parser.cpp"
    break;

  case 19: // INSTRUCTION: PRINT ';'
#line 303 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1916 "parser.cpp"
    break;

  case 20: // INSTRUCTION: EXPRESSION ';'
#line 304 "parser.y"
                            {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1922 "parser.cpp"
    break;

  case 21: // INSTRUCTION: IF
#line 305 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1928 "parser.cpp"
    break;

  case 22: // INSTRUCTION: WHILE
#line 306 "parser.y"
                    { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1934 "parser.cpp"
    break;

  case 23: // INSTRUCTION: FOR
#line 307 "parser.y"
                  { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1940 "parser.cpp"
    break;

  case 24: // INSTRUCTION: DECLARATION ';'
#line 308 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1946 "parser.cpp"
    break;

  case 25: // INSTRUCTION: ASSIGNATION ';'
#line 309 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1952 "parser.cpp"
    break;

  case 26: // INSTRUCTION: DECLARE_STRUCT
#line 310 "parser.y"
                             { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1958 "parser.cpp"
    break;

  case 27: // INSTRUCTION: CREATE_STRUCT
#line 311 "parser.y"
                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1964 "parser.cpp"
    break;

  case 28: // INSTRUCTION: DECLARE_VECTOR ';'
#line 312 "parser.y"
                                 {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1970 "parser.cpp"
    break;

  case 29: // INSTRUCTION: DECLARE_MATRIX ';'
#line 313 "parser.y"
                                 {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1976 "parser.cpp"
    break;

  case 30: // INSTRUCTION: BREAK ';'
#line 314 "parser.y"
                        {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1982 "parser.cpp"
    break;

  case 31: // INSTRUCTION: CONTINUE ';'
#line 315 "parser.y"
                           {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1988 "parser.cpp"
    break;

  case 32: // INSTRUCTION: RETURN ';'
#line 316 "parser.y"
                         {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1994 "parser.cpp"
    break;

  case 33: // INSTRUCTION: CALL_INST
#line 317 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 2000 "parser.cpp"
    break;

  case 34: // INSTRUCTION: PUSHBACK ';'
#line 318 "parser.y"
                           {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2006 "parser.cpp"
    break;

  case 35: // INSTRUCTION: PUSHFRONT ';'
#line 319 "parser.y"
                            {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2012 "parser.cpp"
    break;

  case 36: // INSTRUCTION: REMOVE ';'
#line 320 "parser.y"
                         {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2018 "parser.cpp"
    break;

  case 37: // PRINT: PRINTF PARA EXP_LIST PARC
#line 323 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 2024 "parser.cpp"
    break;

  case 38: // PUSHBACK: ID '.' VPBACK PARA EXP PARC
#line 326 "parser.y"
                                       {yylhs.value.as < instruction* > () = new func_pushback(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2030 "parser.cpp"
    break;

  case 39: // PUSHFRONT: ID '.' VPFRONT PARA EXP PARC
#line 329 "parser.y"
                                         {yylhs.value.as < instruction* > () = new func_pushfront(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2036 "parser.cpp"
    break;

  case 40: // GET: ID '.' VGET PARA EXP PARC
#line 332 "parser.y"
                                {yylhs.value.as < expression* > () = new func_get(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2042 "parser.cpp"
    break;

  case 41: // SIZE: ID '.' VSIZE PARA PARC
#line 335 "parser.y"
                              {yylhs.value.as < expression* > () = new func_size(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[4].value.as < std::string > ());}
#line 2048 "parser.cpp"
    break;

  case 42: // REMOVE: ID '.' VREMOVE PARA EXP PARC
#line 338 "parser.y"
                                      {yylhs.value.as < instruction* > () = new func_remove(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2054 "parser.cpp"
    break;

  case 43: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 342 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 2062 "parser.cpp"
    break;

  case 44: // IF: RIF EXP LLAVA LIST_INST LLAVC
#line 346 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (),nullptr,nullptr);
    }
#line 2070 "parser.cpp"
    break;

  case 45: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
#line 350 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > (),nullptr);
    }
#line 2078 "parser.cpp"
    break;

  case 46: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 354 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 2086 "parser.cpp"
    break;

  case 47: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 360 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 2095 "parser.cpp"
    break;

  case 48: // ELSEIF_LIST: ELSEIF
#line 365 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 2104 "parser.cpp"
    break;

  case 49: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 372 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 2112 "parser.cpp"
    break;

  case 50: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 377 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 2118 "parser.cpp"
    break;

  case 51: // ELSE: %empty
#line 378 "parser.y"
             { }
#line 2124 "parser.cpp"
    break;

  case 52: // WHILE: RWHILE PARA EXP PARC LLAVA LIST_INST LLAVC
#line 382 "parser.y"
                                                  {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 2130 "parser.cpp"
    break;

  case 53: // FOR: RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC
#line 385 "parser.y"
                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line, yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 2136 "parser.cpp"
    break;

  case 54: // EXPRESSION: EXP
#line 388 "parser.y"
                 {yylhs.value.as < instruction* > () = new func_expression(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 2142 "parser.cpp"
    break;

  case 55: // DECLARE_STRUCT: RSTRUCT ID LLAVA DECLARE_LIST LLAVC
#line 391 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new declare_struct(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 2148 "parser.cpp"
    break;

  case 56: // DECLARE_LIST: DECLARE_LIST TYPES ID ';'
#line 395 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2157 "parser.cpp"
    break;

  case 57: // DECLARE_LIST: DECLARE_LIST ID ID ';'
#line 400 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),STRUCT);
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2166 "parser.cpp"
    break;

  case 58: // DECLARE_LIST: TYPES ID ';'
#line 405 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 2175 "parser.cpp"
    break;

  case 59: // DECLARE_LIST: ID ID ';'
#line 410 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), STRUCT);
        }
#line 2184 "parser.cpp"
    break;

  case 60: // CREATE_STRUCT: RSTRUCT ID ID '=' LLAVA EXP_LIST LLAVC ';'
#line 417 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(yystack_[7].location.begin.line, yystack_[7].location.begin.column,yystack_[6].value.as < std::string > (),yystack_[5].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());
                }
#line 2192 "parser.cpp"
    break;

  case 61: // EXP_LIST: EXP_LIST ',' EXP
#line 423 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 2201 "parser.cpp"
    break;

  case 62: // EXP_LIST: EXP
#line 428 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 2210 "parser.cpp"
    break;

  case 63: // DECLARATION: TYPES ID '=' EXP
#line 434 "parser.y"
                               {yylhs.value.as < instruction* > () = new declare(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 2216 "parser.cpp"
    break;

  case 64: // DECLARATION: TYPES ID
#line 435 "parser.y"
                       {yylhs.value.as < instruction* > () = new declare(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),nullptr);}
#line 2222 "parser.cpp"
    break;

  case 65: // ASSIGNATION: ID '=' EXP
#line 437 "parser.y"
                         {yylhs.value.as < instruction* > () = new assign(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 2228 "parser.cpp"
    break;

  case 66: // ASSIGNATION: ID CORA PRIMITIVE CORC '=' PRIMITIVE
#line 438 "parser.y"
                                                   {yylhs.value.as < instruction* > () = new assign_vector(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[3].value.as < expression* > (),yystack_[0].value.as < expression* > ());}
#line 2234 "parser.cpp"
    break;

  case 67: // BREAK: RBREAK
#line 441 "parser.y"
               {yylhs.value.as < instruction* > () = new func_break(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 2240 "parser.cpp"
    break;

  case 68: // CONTINUE: RCONTINUE
#line 444 "parser.y"
                     {yylhs.value.as < instruction* > () = new func_continue(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 2246 "parser.cpp"
    break;

  case 69: // RETURN: RRETURN EXP
#line 447 "parser.y"
                     { yylhs.value.as < instruction* > () = new func_return(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ()); }
#line 2252 "parser.cpp"
    break;

  case 70: // RETURN: RRETURN
#line 448 "parser.y"
                  { yylhs.value.as < instruction* > () = new func_return(yystack_[0].location.begin.line, yystack_[0].location.begin.column,nullptr); }
#line 2258 "parser.cpp"
    break;

  case 71: // MEAN: RMEAN PARA ID PARC
#line 451 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mean(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2264 "parser.cpp"
    break;

  case 72: // MEDIAN: RMEDIAN PARA ID PARC
#line 454 "parser.y"
                              {yylhs.value.as < expression* > () = new func_median(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2270 "parser.cpp"
    break;

  case 73: // MODE: RMODE PARA ID PARC
#line 457 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mode(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2276 "parser.cpp"
    break;

  case 74: // TYPES: INT
#line 460 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 2282 "parser.cpp"
    break;

  case 75: // TYPES: TSTRING
#line 461 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 2288 "parser.cpp"
    break;

  case 76: // TYPES: BOOLEAN
#line 462 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 2294 "parser.cpp"
    break;

  case 77: // TYPES: FLOAT
#line 463 "parser.y"
            { yylhs.value.as < TipoDato > () = FLOAT; }
#line 2300 "parser.cpp"
    break;

  case 78: // TYPES: VOID
#line 464 "parser.y"
           {yylhs.value.as < TipoDato > () = VOID;}
#line 2306 "parser.cpp"
    break;

  case 79: // TYPES: RVECTOR
#line 465 "parser.y"
              {yylhs.value.as < TipoDato > () = VECTOR;}
#line 2312 "parser.cpp"
    break;

  case 80: // EXP: EXP SUMA EXP
#line 469 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 2318 "parser.cpp"
    break;

  case 81: // EXP: EXP MENOS EXP
#line 470 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 2324 "parser.cpp"
    break;

  case 82: // EXP: EXP POR EXP
#line 471 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 2330 "parser.cpp"
    break;

  case 83: // EXP: EXP DIV EXP
#line 472 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2336 "parser.cpp"
    break;

  case 84: // EXP: EXP MOD EXP
#line 473 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2342 "parser.cpp"
    break;

  case 85: // EXP: INCREMENT
#line 475 "parser.y"
                {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2348 "parser.cpp"
    break;

  case 86: // EXP: EXP MAYOR EXP
#line 477 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">");}
#line 2354 "parser.cpp"
    break;

  case 87: // EXP: EXP MAYEQU EXP
#line 478 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">=");}
#line 2360 "parser.cpp"
    break;

  case 88: // EXP: EXP MENOR EXP
#line 479 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<");}
#line 2366 "parser.cpp"
    break;

  case 89: // EXP: EXP MENEQU EXP
#line 480 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<=");}
#line 2372 "parser.cpp"
    break;

  case 90: // EXP: EXP EQU EXP
#line 481 "parser.y"
                  {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "==");}
#line 2378 "parser.cpp"
    break;

  case 91: // EXP: EXP DIFF EXP
#line 482 "parser.y"
                   {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!=");}
#line 2384 "parser.cpp"
    break;

  case 92: // EXP: EXP AND EXP
#line 484 "parser.y"
                  {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&");}
#line 2390 "parser.cpp"
    break;

  case 93: // EXP: EXP OR EXP
#line 485 "parser.y"
                 {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||");}
#line 2396 "parser.cpp"
    break;

  case 94: // EXP: NOT EXP
#line 487 "parser.y"
    {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
#line 2404 "parser.cpp"
    break;

  case 95: // EXP: MENOS EXP
#line 491 "parser.y"
                {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < expression* > (),new primitive(0,0,INTEGER, "", 0,0.0,false),"NEG");
        }
#line 2412 "parser.cpp"
    break;

  case 96: // EXP: PARA EXP PARC
#line 495 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2418 "parser.cpp"
    break;

  case 97: // EXP: ATOI
#line 496 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2424 "parser.cpp"
    break;

  case 98: // EXP: ATOF
#line 497 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2430 "parser.cpp"
    break;

  case 99: // EXP: IOTA
#line 498 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2436 "parser.cpp"
    break;

  case 100: // EXP: CORA EXP_LIST CORC
#line 499 "parser.y"
                         { yylhs.value.as < expression* > () = new expression_vector(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 2442 "parser.cpp"
    break;

  case 101: // EXP: CALL_EXP
#line 500 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2448 "parser.cpp"
    break;

  case 102: // EXP: GET
#line 501 "parser.y"
          {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2454 "parser.cpp"
    break;

  case 103: // EXP: SIZE
#line 502 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2460 "parser.cpp"
    break;

  case 104: // EXP: MEAN
#line 503 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2466 "parser.cpp"
    break;

  case 105: // EXP: MEDIAN
#line 504 "parser.y"
             {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2472 "parser.cpp"
    break;

  case 106: // EXP: MODE
#line 505 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2478 "parser.cpp"
    break;

  case 107: // EXP: PRIMITIVE
#line 507 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2484 "parser.cpp"
    break;

  case 108: // ATOI: RATOI PARA PRIMITIVE PARC
#line 511 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atoi(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2490 "parser.cpp"
    break;

  case 109: // ATOF: RATOF PARA PRIMITIVE PARC
#line 514 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atof(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2496 "parser.cpp"
    break;

  case 110: // IOTA: RIOTA PARA EXP PARC
#line 517 "parser.y"
                           {yylhs.value.as < expression* > () = new func_iota(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2502 "parser.cpp"
    break;

  case 111: // INCREMENT: PREFIX_INCREMENT
#line 521 "parser.y"
                            { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2508 "parser.cpp"
    break;

  case 112: // INCREMENT: EXP INC
#line 522 "parser.y"
                      { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, yystack_[1].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
#line 2514 "parser.cpp"
    break;

  case 113: // PREFIX_INCREMENT: INC EXP
#line 525 "parser.y"
                          { yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++B"); }
#line 2520 "parser.cpp"
    break;

  case 114: // PREFIX_INCREMENT: EXP PREFIX_INCREMENT
#line 526 "parser.y"
                                       {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2526 "parser.cpp"
    break;

  case 115: // PRIMITIVE: NUMERO
#line 529 "parser.y"
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
#line 2543 "parser.cpp"
    break;

  case 116: // PRIMITIVE: STRING
#line 542 "parser.y"
        {
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,STRING,str2,0,0.0,false);
        }
#line 2553 "parser.cpp"
    break;

  case 117: // PRIMITIVE: NLL
#line 547 "parser.y"
              {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,NULO,"",0,0.0,false);}
#line 2559 "parser.cpp"
    break;

  case 118: // PRIMITIVE: BOOLTRUE
#line 548 "parser.y"
                  {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, true);}
#line 2565 "parser.cpp"
    break;

  case 119: // PRIMITIVE: BOOLFALSE
#line 549 "parser.y"
                   {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, false);}
#line 2571 "parser.cpp"
    break;

  case 120: // PRIMITIVE: LIST_ARR
#line 550 "parser.y"
                  {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2577 "parser.cpp"
    break;

  case 121: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 553 "parser.y"
                                  { yylhs.value.as < expression* > () = new vector_access(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2583 "parser.cpp"
    break;

  case 122: // LIST_ARR: LIST_ARR '.' ID
#line 554 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 2589 "parser.cpp"
    break;

  case 123: // LIST_ARR: ID
#line 555 "parser.y"
             {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ()); }
#line 2595 "parser.cpp"
    break;

  case 124: // DECLARE_VECTOR: RVECTOR MENOR TYPES MAYOR ID '=' EXP
#line 558 "parser.y"
                                                       {yylhs.value.as < instruction* > () = new declare_vector(yystack_[6].location.begin.line, yystack_[6].location.begin.column, yystack_[4].value.as < TipoDato > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > ());}
#line 2601 "parser.cpp"
    break;

  case 125: // DECLARE_VECTOR: RVECTOR MENOR TYPES MAYOR ID
#line 559 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declare_vector(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[2].value.as < TipoDato > (), yystack_[0].value.as < std::string > (), nullptr);}
#line 2607 "parser.cpp"
    break;

  case 126: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 562 "parser.y"
                                                                     {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[8].location.begin.line, yystack_[8].location.begin.column,yystack_[8].value.as < TipoDato > (), yystack_[7].value.as < std::string > (), yystack_[5].value.as < expression* > (), nullptr, nullptr, yystack_[1].value.as < list_expression* > ());}
#line 2613 "parser.cpp"
    break;

  case 127: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 563 "parser.y"
                                                                                          {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[11].location.begin.line, yystack_[11].location.begin.column,yystack_[11].value.as < TipoDato > (), yystack_[10].value.as < std::string > (), yystack_[8].value.as < expression* > () , yystack_[5].value.as < expression* > (), nullptr, yystack_[1].value.as < list_expression* > ());}
#line 2619 "parser.cpp"
    break;

  case 128: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 564 "parser.y"
                                                                                                              {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[14].location.begin.line, yystack_[14].location.begin.column,yystack_[14].value.as < TipoDato > (), yystack_[13].value.as < std::string > (), yystack_[11].value.as < expression* > (), yystack_[8].value.as < expression* > (), yystack_[5].value.as < expression* > (), yystack_[1].value.as < list_expression* > ());}
#line 2625 "parser.cpp"
    break;

  case 129: // CALL_EXP: ID PARA EXP_LIST PARC
#line 568 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 2631 "parser.cpp"
    break;

  case 130: // CALL_EXP: ID PARA PARC
#line 569 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 2637 "parser.cpp"
    break;

  case 131: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 572 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 2643 "parser.cpp"
    break;

  case 132: // CALL_INST: ID PARA PARC ';'
#line 573 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr); }
#line 2649 "parser.cpp"
    break;


#line 2653 "parser.cpp"

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





  const signed char Parser::yypact_ninf_ = -120;

  const signed char Parser::yytable_ninf_ = -115;

  const short
  Parser::yypact_[] =
  {
     273,    29,  -120,  -120,  -120,    36,  -120,  -120,  -120,    42,
     309,   273,  -120,  -120,  -120,    57,     0,    68,  -120,  -120,
    -120,   309,  -120,    93,    92,    95,   351,   329,  -120,    79,
      96,    69,    -9,   108,   110,   169,   112,   115,     1,   116,
    1448,   122,  1553,  -120,    82,   136,  -120,   137,    88,   860,
     130,   860,   106,   860,   103,   146,  -120,    98,    99,  -120,
    -120,   -13,  -120,   148,   113,  -120,  -120,  1544,  1544,  -120,
    1544,  1544,  1544,   152,   153,   155,   158,   167,   168,   170,
     171,   174,  -120,  -120,  1544,  1544,   419,  -120,   126,   133,
     134,  -120,  -120,   140,  -120,  -120,  -120,   141,  -120,  -120,
     142,   143,   144,   149,   150,  -120,  -120,  -120,   199,  1439,
    -120,  -120,  -120,  -120,  -120,  -120,    14,   154,   156,  -120,
    -120,   860,   468,   201,   517,  1448,  -120,  -120,  -120,  1488,
     131,  1544,   109,    75,  1448,    -7,   900,   -11,  1439,  1686,
    1658,   949,  1544,  1448,  1544,   206,   208,   211,   131,   131,
    1544,  1439,  1584,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,     8,  1544,  1544,  1544,  1544,
    1714,  1544,  1544,  1544,  1544,  1544,  1544,  1544,  1544,  1544,
    1439,    39,  1544,   216,  -120,  -120,   566,  -120,  -120,  -120,
     178,   165,     5,  -120,   207,  1439,   213,   217,   219,   222,
     224,   182,   198,  1516,   -43,  -120,  -120,  1544,   860,   998,
     187,   241,     9,   231,   232,   235,   236,   237,  1047,   131,
    1544,  1686,  1686,  1742,  1742,  1742,  1658,  1658,  1658,  1658,
    1621,  1621,  1584,  1584,  1096,  -120,  -120,   249,  -120,   197,
     202,  1544,  1544,  1544,   246,  1544,   240,   258,  -120,    10,
    1439,   615,   250,  1544,   209,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,   251,  1439,  -120,  -120,  -120,   131,  1145,  1194,
    1243,  -120,  1292,  1544,   214,  -120,   255,   860,   364,    13,
    -120,  -120,  -120,  -120,  -120,    -8,  1544,    47,   255,  -120,
    -120,   664,  1544,   131,   247,   229,  1439,   860,  1544,  -120,
    -120,  -120,  1341,   257,  1544,  -120,   713,  1390,   272,    44,
      46,  -120,   860,   860,   131,   271,  -120,   762,   811,   275,
    1544,  -120,  -120,   233,    48,   274,  -120,  1544,    51,  -120
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,    75,    77,    76,     0,    79,    74,    78,     0,
       0,     0,     6,     2,     8,     0,     0,     0,     1,     5,
       3,     0,     7,     0,     0,     0,     0,     0,     4,     0,
       0,    79,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,    79,     0,    59,     0,     0,    58,
     115,   123,   116,     0,    79,   118,   119,     0,     0,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    70,     0,     0,    18,     0,     0,
       0,   102,   103,     0,    21,    22,    23,     0,    26,    27,
       0,     0,     0,     0,     0,   104,   105,   106,     0,    54,
      97,    98,    99,    85,   111,   107,   120,     0,     0,   101,
      33,     0,     0,     0,     0,     0,    12,    57,    56,     0,
       0,     0,     0,     0,     0,   123,     0,     0,    62,    95,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    94,    10,    17,    19,    34,    35,    36,    20,
      24,    25,    30,    31,    32,    64,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,    28,    29,     0,    16,    15,    11,
       0,   130,     0,   123,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    82,    83,    84,    86,    88,    87,    89,
      90,    91,    92,    93,     0,   122,     9,     0,   132,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
      61,     0,     0,     0,    64,    37,    71,    72,    73,   108,
     109,   110,     0,    63,   121,    13,   131,     0,     0,     0,
       0,    41,     0,     0,   125,   129,    44,     0,     0,     0,
      66,    38,    40,    42,    39,     0,     0,     0,    45,    48,
      46,     0,     0,     0,     0,     0,   124,     0,     0,    47,
      43,    52,     0,     0,     0,    60,     0,     0,     0,     0,
       0,    50,     0,     0,     0,     0,   126,     0,     0,     0,
       0,    49,    53,     0,     0,     0,   127,     0,     0,   128
  };

  const short
  Parser::yypgoto_[] =
  {
    -120,  -120,   279,  -120,    67,   266,    71,   -38,   -83,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,    26,    30,  -120,
    -120,  -120,   104,  -120,  -120,   -95,   179,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,    17,   -49,  -120,  -120,  -120,  -120,
      78,  -119,  -120,  -120,  -120,  -120,  -120
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    32,    13,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   288,   289,   290,    95,
      96,    97,    98,    35,    99,   137,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   180,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120
  };

  const short
  Parser::yytable_[] =
  {
     109,   129,   109,   154,   109,   130,    41,   203,   206,   295,
     197,   194,   199,   122,    26,   124,    50,    15,   136,   138,
     239,   139,   140,   141,   255,   275,   219,    15,    23,   216,
     217,   293,   182,    16,   192,   151,   152,   109,    15,   154,
      17,   154,    18,    33,    36,   131,    33,   132,   207,   212,
      42,   207,    47,   204,  -114,  -114,  -114,    52,  -114,    55,
      42,    24,   314,   297,   207,   316,   220,   326,   207,   207,
     329,   294,   109,   109,   183,   109,   298,    19,    25,   201,
     138,    20,   195,   186,    27,     2,     3,     4,    19,    31,
       7,    27,    28,   209,    37,   138,  -114,    24,  -114,     8,
     262,   218,   315,   154,    14,   207,    29,   207,   249,    30,
     207,    39,    43,    40,    44,    22,    48,   221,   222,   223,
     224,   140,   225,   226,   227,   228,   229,   230,   231,   232,
     233,    49,    51,   234,    60,   193,    62,   109,    53,    56,
      57,    58,   190,    65,    66,    59,   121,   125,   280,   123,
     126,   202,   133,    69,   138,   127,   128,   134,   250,   109,
     211,   196,   197,   198,   199,   200,   142,   143,   154,   144,
     251,   263,   145,    45,   303,     2,     3,     4,   285,     6,
       7,   146,   147,   155,   148,   149,    46,   181,   150,     8,
     156,   157,   268,   269,   270,   319,   272,   158,   159,   160,
     161,   162,   109,   165,   278,   188,   163,   164,   154,   310,
     213,   184,   214,   185,   181,   215,   181,   181,   181,   181,
     235,   237,   238,   154,   138,   324,   240,   241,   109,   181,
     181,   242,   328,   243,   154,   154,   244,   296,   245,   291,
     246,   247,   109,   302,   253,   254,   256,   257,   109,   307,
     258,   259,   260,   265,   266,   138,   273,   109,   181,   306,
     267,   271,   274,   109,   109,   304,   277,   220,   109,   109,
     279,   138,   286,   181,   317,   318,   309,     1,   138,     2,
       3,     4,     5,     6,     7,   287,   305,   181,   313,   320,
      21,   325,   327,     8,   323,    38,   181,     0,     0,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,     1,   299,     2,     3,     4,   300,     6,
       7,     0,   210,     0,     0,     0,     0,     0,   181,     8,
       0,     0,     0,    34,     0,     2,     3,     4,     0,     6,
       7,   181,     0,     0,     0,     0,   181,   181,   181,     8,
     181,     0,     0,     0,     0,     0,   181,     2,     3,     4,
       0,    31,     7,     0,     0,     0,     0,    60,   135,    62,
       0,     8,     0,     0,   181,     0,    65,    66,    67,     0,
     181,     0,    68,     0,     0,   181,    69,   166,   167,   168,
     169,   170,   171,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,    85,     0,     0,     0,     0,
       0,   292,    60,    61,    62,     2,     3,     4,    63,    64,
       7,    65,    66,    67,     0,     0,   153,    68,     0,     8,
       0,    69,     0,    70,     0,     0,    71,     0,    72,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    60,    61,    62,     2,     3,     4,    63,    64,     7,
      65,    66,    67,     0,     0,   187,    68,     0,     8,     0,
      69,     0,    70,     0,     0,    71,     0,    72,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      60,    61,    62,     2,     3,     4,    63,    64,     7,    65,
      66,    67,     0,     0,   189,    68,     0,     8,     0,    69,
       0,    70,     0,     0,    71,     0,    72,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    60,
      61,    62,     2,     3,     4,    63,    64,     7,    65,    66,
      67,     0,     0,   236,    68,     0,     8,     0,    69,     0,
      70,     0,     0,    71,     0,    72,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    60,    61,
      62,     2,     3,     4,    63,    64,     7,    65,    66,    67,
       0,     0,   276,    68,     0,     8,     0,    69,     0,    70,
       0,     0,    71,     0,    72,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    60,    61,    62,
       2,     3,     4,    63,    64,     7,    65,    66,    67,     0,
       0,   301,    68,     0,     8,     0,    69,     0,    70,     0,
       0,    71,     0,    72,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    60,    61,    62,     2,
       3,     4,    63,    64,     7,    65,    66,    67,     0,     0,
     311,    68,     0,     8,     0,    69,     0,    70,     0,     0,
      71,     0,    72,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    60,    61,    62,     2,     3,
       4,    63,    64,     7,    65,    66,    67,     0,     0,   321,
      68,     0,     8,     0,    69,     0,    70,     0,     0,    71,
       0,    72,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    60,    61,    62,     2,     3,     4,
      63,    64,     7,    65,    66,    67,     0,     0,   322,    68,
       0,     8,     0,    69,     0,    70,     0,     0,    71,     0,
      72,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    60,    61,    62,     2,     3,     4,    63,
      64,     7,    65,    66,    67,     0,     0,     0,    68,     0,
       8,     0,    69,     0,    70,     0,     0,    71,     0,    72,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    60,   135,    62,     0,     0,     0,     0,
       0,    85,    65,    66,    67,   205,     0,     0,    68,     0,
       0,     0,    69,   166,   167,   168,   169,   170,   171,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,    85,    60,   135,    62,     0,     0,     0,     0,     0,
       0,    65,    66,    67,     0,   208,     0,    68,     0,     0,
       0,    69,   166,   167,   168,   169,   170,   171,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,     0,
       0,     0,   172,   173,   174,   175,   176,   177,   178,   179,
      85,    60,   135,    62,     0,     0,     0,     0,     0,     0,
      65,    66,    67,   252,     0,     0,    68,     0,     0,     0,
      69,   166,   167,   168,   169,   170,   171,     0,     0,     0,
       0,     0,    76,    77,    78,    79,    80,    81,     0,     0,
       0,   172,   173,   174,   175,   176,   177,   178,   179,    85,
      60,   135,    62,     0,     0,     0,     0,     0,     0,    65,
      66,    67,   261,     0,     0,    68,     0,     0,     0,    69,
     166,   167,   168,   169,   170,   171,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,     0,     0,     0,
     172,   173,   174,   175,   176,   177,   178,   179,    85,    60,
     135,    62,     0,     0,     0,     0,     0,     0,    65,    66,
      67,     0,     0,     0,    68,   264,     0,     0,    69,   166,
     167,   168,   169,   170,   171,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,     0,     0,     0,   172,
     173,   174,   175,   176,   177,   178,   179,    85,    60,   135,
      62,     0,     0,     0,     0,     0,     0,    65,    66,    67,
     281,     0,     0,    68,     0,     0,     0,    69,   166,   167,
     168,   169,   170,   171,     0,     0,     0,     0,     0,    76,
      77,    78,    79,    80,    81,     0,     0,     0,   172,   173,
     174,   175,   176,   177,   178,   179,    85,    60,   135,    62,
       0,     0,     0,     0,     0,     0,    65,    66,    67,   282,
       0,     0,    68,     0,     0,     0,    69,   166,   167,   168,
     169,   170,   171,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,     0,     0,     0,   172,   173,   174,
     175,   176,   177,   178,   179,    85,    60,   135,    62,     0,
       0,     0,     0,     0,     0,    65,    66,    67,   283,     0,
       0,    68,     0,     0,     0,    69,   166,   167,   168,   169,
     170,   171,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,     0,     0,     0,   172,   173,   174,   175,
     176,   177,   178,   179,    85,    60,   135,    62,     0,     0,
       0,     0,     0,     0,    65,    66,    67,   284,     0,     0,
      68,     0,     0,     0,    69,   166,   167,   168,   169,   170,
     171,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81,     0,     0,     0,   172,   173,   174,   175,   176,
     177,   178,   179,    85,    60,   135,    62,     0,     0,     0,
       0,     0,     0,    65,    66,    67,   308,     0,     0,    68,
       0,     0,     0,    69,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,     0,     0,     0,   172,   173,   174,   175,   176,   177,
     178,   179,    85,    60,   135,    62,     0,     0,     0,     0,
       0,     0,    65,    66,    67,     0,   312,     0,    68,     0,
       0,     0,    69,   166,   167,   168,   169,   170,   171,     0,
       0,     0,     0,     0,    76,    77,    78,    79,    80,    81,
       0,     0,     0,   172,   173,   174,   175,   176,   177,   178,
     179,    85,    60,   135,    62,     0,     0,     0,     0,     0,
       0,    65,    66,    67,     2,     3,     4,    68,     6,     7,
       0,    69,   166,   167,   168,   169,   170,   171,     8,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,     0,
       0,     0,   172,   173,   174,   175,   176,   177,   178,   179,
      85,    60,   135,    62,     0,     0,     0,     0,     0,     0,
      65,    66,    67,   191,     0,     0,    68,     0,     0,     0,
      69,     0,    70,     0,     0,    71,     0,     0,     0,    60,
     135,    62,    76,    77,    78,    79,    80,    81,    65,    66,
      67,   248,     0,     0,    68,     0,     0,     0,    69,    85,
      70,     0,     0,    71,     0,     0,     0,    60,   135,    62,
      76,    77,    78,    79,    80,    81,    65,    66,    67,     2,
       3,     4,    68,    54,     7,     0,    69,    85,    70,     0,
       0,    71,     0,     8,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    60,   135,    62,
       0,     0,     0,     0,     0,    85,    65,    66,    67,     0,
       0,     0,    68,     0,     0,     0,    69,   166,   167,   168,
     169,   170,   171,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81,    60,   135,    62,   172,   173,   174,
     175,   176,   177,    65,    66,    67,     0,     0,     0,    68,
       0,     0,     0,    69,   166,   167,   168,   169,   170,   171,
       0,     0,     0,     0,     0,    76,    77,    78,    79,    80,
      81,    60,   135,    62,   172,   173,   174,   175,     0,     0,
      65,    66,    67,     0,     0,     0,    68,     0,     0,     0,
      69,   166,   167,   168,   169,   170,   171,     0,     0,    60,
     135,    62,    76,    77,    78,    79,    80,    81,    65,    66,
      67,     0,     0,     0,    68,     0,     0,     0,    69,     0,
       0,   168,   169,     0,   171,     0,     0,    60,   135,    62,
      76,    77,    78,    79,    80,    81,    65,    66,    67,     0,
       0,     0,    68,     0,     0,     0,    69,     0,    70,     0,
       0,    71,     0,     0,     0,    60,   135,    62,    76,    77,
      78,    79,    80,    81,    65,    66,    67,     0,     0,     0,
      68,     0,     0,     0,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    76,    77,    78,    79,
      80,    81
  };

  const short
  Parser::yycheck_[] =
  {
      49,    14,    51,    86,    53,    18,    15,    14,    19,    17,
      53,   130,    55,    51,    14,    53,    15,     0,    67,    68,
      15,    70,    71,    72,    15,    15,    18,    10,    11,   148,
     149,    18,    18,     4,   129,    84,    85,    86,    21,   122,
       4,   124,     0,    26,    27,    58,    29,    60,    59,   144,
      59,    59,    35,    60,    15,    16,    17,    40,    19,    42,
      59,     4,    18,    16,    59,    19,    58,    19,    59,    59,
      19,    58,   121,   122,    60,   124,    29,    10,    21,     4,
     129,    10,   131,   121,    16,     6,     7,     8,    21,    10,
      11,    16,    21,   142,    15,   144,    57,     4,    59,    20,
     219,   150,    58,   186,     0,    59,    14,    59,   203,    14,
      59,    15,     4,    44,     4,    11,     4,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,    16,    16,   182,     3,     4,     5,   186,    16,    57,
       4,     4,   125,    12,    13,    57,    16,    44,   267,    43,
       4,   134,     4,    22,   203,    57,    57,    44,   207,   208,
     143,    52,    53,    54,    55,    56,    14,    14,   251,    14,
     208,   220,    14,     4,   293,     6,     7,     8,   273,    10,
      11,    14,    14,    57,    14,    14,    17,   109,    14,    20,
      57,    57,   241,   242,   243,   314,   245,    57,    57,    57,
      57,    57,   251,     4,   253,     4,    57,    57,   291,   304,
       4,    57,     4,    57,   136,     4,   138,   139,   140,   141,
       4,    43,    57,   306,   273,   320,    19,    14,   277,   151,
     152,    14,   327,    14,   317,   318,    14,   286,    14,   277,
      58,    43,   291,   292,    57,     4,    15,    15,   297,   298,
      15,    15,    15,     4,    57,   304,    16,   306,   180,   297,
      58,    15,     4,   312,   313,    18,    16,    58,   317,   318,
      19,   320,    58,   195,   312,   313,    19,     4,   327,     6,
       7,     8,     9,    10,    11,    30,    57,   209,    16,    18,
      11,    58,    18,    20,    19,    29,   218,    -1,    -1,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     4,   288,     6,     7,     8,   288,    10,
      11,    -1,   143,    -1,    -1,    -1,    -1,    -1,   250,    20,
      -1,    -1,    -1,     4,    -1,     6,     7,     8,    -1,    10,
      11,   263,    -1,    -1,    -1,    -1,   268,   269,   270,    20,
     272,    -1,    -1,    -1,    -1,    -1,   278,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,    20,    -1,    -1,   296,    -1,    12,    13,    14,    -1,
     302,    -1,    18,    -1,    -1,   307,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      -1,    57,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    17,    18,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    27,    -1,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    -1,    20,    -1,
      22,    -1,    24,    -1,    -1,    27,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    27,    -1,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      -1,    27,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      27,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,    27,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    17,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    27,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    -1,    18,    -1,
      20,    -1,    22,    -1,    24,    -1,    -1,    27,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    51,    12,    13,    14,    15,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    51,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    -1,    16,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,     6,     7,     8,    18,    10,    11,
      -1,    22,    23,    24,    25,    26,    27,    28,    20,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,    -1,
      22,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,     3,
       4,     5,    34,    35,    36,    37,    38,    39,    12,    13,
      14,    15,    -1,    -1,    18,    -1,    -1,    -1,    22,    51,
      24,    -1,    -1,    27,    -1,    -1,    -1,     3,     4,     5,
      34,    35,    36,    37,    38,    39,    12,    13,    14,     6,
       7,     8,    18,    10,    11,    -1,    22,    51,    24,    -1,
      -1,    27,    -1,    20,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    51,    12,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,     3,     4,     5,    43,    44,    45,
      46,    47,    48,    12,    13,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,     3,     4,     5,    43,    44,    45,    46,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,     3,
       4,     5,    34,    35,    36,    37,    38,    39,    12,    13,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    -1,
      -1,    25,    26,    -1,    28,    -1,    -1,     3,     4,     5,
      34,    35,    36,    37,    38,    39,    12,    13,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    22,    -1,    24,    -1,
      -1,    27,    -1,    -1,    -1,     3,     4,     5,    34,    35,
      36,    37,    38,    39,    12,    13,    14,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    39
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,     7,     8,     9,    10,    11,    20,    62,
      63,    64,    65,    67,    83,    95,     4,     4,     0,    65,
      67,    63,    83,    95,     4,    21,    14,    16,    67,    14,
      14,    10,    66,    95,     4,    84,    95,    15,    66,    15,
      44,    15,    59,     4,     4,     4,    17,    95,     4,    16,
      15,    16,    95,    16,    10,    95,    57,     4,     4,    57,
       3,     4,     5,     9,    10,    12,    13,    14,    18,    22,
      24,    27,    29,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    51,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    80,    81,    82,    83,    85,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    16,    68,    43,    68,    44,     4,    57,    57,    14,
      18,    58,    60,     4,    44,     4,    96,    86,    96,    96,
      96,    96,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    96,    96,    17,    69,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,     4,    23,    24,    25,    26,
      27,    28,    43,    44,    45,    46,    47,    48,    49,    50,
      96,   101,    18,    60,    57,    57,    68,    17,     4,    17,
      95,    15,    86,     4,   102,    96,    52,    53,    54,    55,
      56,     4,    95,    14,    60,    15,    19,    59,    16,    96,
      87,    95,    86,     4,     4,     4,   102,   102,    96,    18,
      58,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,     4,    17,    43,    57,    15,
      19,    14,    14,    14,    14,    14,    58,    43,    15,    86,
      96,    68,    15,    57,     4,    15,    15,    15,    15,    15,
      15,    15,   102,    96,    19,     4,    57,    58,    96,    96,
      96,    15,    96,    16,     4,    15,    17,    16,    96,    19,
     102,    15,    15,    15,    15,    86,    58,    30,    77,    78,
      79,    68,    57,    18,    58,    17,    96,    16,    29,    78,
      79,    17,    96,   102,    18,    57,    68,    96,    15,    19,
      86,    17,    16,    16,    18,    58,    19,    68,    68,   102,
      18,    17,    17,    19,    86,    58,    19,    18,    86,    19
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    67,    68,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    71,    72,
      73,    74,    75,    76,    76,    76,    76,    77,    77,    78,
      79,    79,    80,    81,    82,    83,    84,    84,    84,    84,
      85,    86,    86,    87,    87,    88,    88,    89,    90,    91,
      91,    92,    93,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    98,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   105,   106,
     106,   107,   107
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     2,     1,     2,     1,     8,
       7,     8,     4,     7,     2,     5,     7,     2,     1,     2,
       2,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     4,     6,     6,
       6,     5,     6,     7,     5,     6,     6,     2,     1,     6,
       4,     0,     7,    11,     1,     5,     4,     4,     3,     3,
       8,     3,     1,     4,     2,     3,     6,     1,     1,     2,
       1,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     4,     3,     1,     7,     5,     9,    12,    15,     4,
       3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING",
  "TSTRING", "FLOAT", "BOOLEAN", "RSTRUCT", "RVECTOR", "INT", "BOOLTRUE",
  "BOOLFALSE", "PARA", "PARC", "LLAVA", "LLAVC", "CORA", "CORC", "VOID",
  "RMAIN", "NLL", "SUMA", "MENOS", "POR", "DIV", "INC", "MOD", "RIF",
  "RELSE", "RWHILE", "RFOR", "PRINTF", "RMEAN", "RMEDIAN", "RMODE",
  "RATOI", "RATOF", "RIOTA", "RBREAK", "RCONTINUE", "RRETURN", "MAYOR",
  "MENOR", "MAYEQU", "MENEQU", "EQU", "DIFF", "AND", "OR", "NOT", "VPBACK",
  "VGET", "VREMOVE", "VSIZE", "VPFRONT", "';'", "'='", "','", "'.'",
  "$accept", "START", "LIST_FUNC", "LIST_STRUCT", "FUNCTION",
  "FUNCTION_LIST", "MAIN", "LIST_INST", "INSTRUCTION", "PRINT", "PUSHBACK",
  "PUSHFRONT", "GET", "SIZE", "REMOVE", "IF", "ELSEIF_LIST", "ELSEIF",
  "ELSE", "WHILE", "FOR", "EXPRESSION", "DECLARE_STRUCT", "DECLARE_LIST",
  "CREATE_STRUCT", "EXP_LIST", "DECLARATION", "ASSIGNATION", "BREAK",
  "CONTINUE", "RETURN", "MEAN", "MEDIAN", "MODE", "TYPES", "EXP", "ATOI",
  "ATOF", "IOTA", "INCREMENT", "PREFIX_INCREMENT", "PRIMITIVE", "LIST_ARR",
  "DECLARE_VECTOR", "DECLARE_MATRIX", "CALL_EXP", "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   202,   202,   208,   215,   225,   230,   237,   242,   249,
     253,   257,   263,   268,   273,   278,   285,   291,   296,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   323,   326,   329,
     332,   335,   338,   341,   345,   349,   353,   359,   364,   371,
     377,   378,   382,   385,   388,   391,   394,   399,   404,   409,
     416,   422,   427,   434,   435,   437,   438,   441,   444,   447,
     448,   451,   454,   457,   460,   461,   462,   463,   464,   465,
     469,   470,   471,   472,   473,   475,   477,   478,   479,   480,
     481,   482,   484,   485,   486,   491,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   507,   511,   514,
     517,   521,   522,   525,   526,   529,   541,   547,   548,   549,
     550,   553,   554,   555,   558,   559,   562,   563,   564,   568,
     569,   572,   573
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
#line 3462 "parser.cpp"

#line 576 "parser.y"


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
