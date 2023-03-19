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
#line 99 "parser.y"
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
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
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 790 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 796 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 802 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 808 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 814 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 820 "parser.cpp"
        break;

      case symbol_kind::S_RSTRUCT: // RSTRUCT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 826 "parser.cpp"
        break;

      case symbol_kind::S_RVECTOR: // RVECTOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 832 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 838 "parser.cpp"
        break;

      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 844 "parser.cpp"
        break;

      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 850 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 856 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 862 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 868 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 874 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 880 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 886 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 892 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 898 "parser.cpp"
        break;

      case symbol_kind::S_NLL: // NLL
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 904 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 910 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 916 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 922 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 928 "parser.cpp"
        break;

      case symbol_kind::S_INC: // INC
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 934 "parser.cpp"
        break;

      case symbol_kind::S_MOD: // MOD
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 940 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 946 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 952 "parser.cpp"
        break;

      case symbol_kind::S_RWHILE: // RWHILE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 958 "parser.cpp"
        break;

      case symbol_kind::S_RFOR: // RFOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 964 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 970 "parser.cpp"
        break;

      case symbol_kind::S_RMEAN: // RMEAN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 976 "parser.cpp"
        break;

      case symbol_kind::S_RMEDIAN: // RMEDIAN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 982 "parser.cpp"
        break;

      case symbol_kind::S_RMODE: // RMODE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 988 "parser.cpp"
        break;

      case symbol_kind::S_RATOI: // RATOI
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 994 "parser.cpp"
        break;

      case symbol_kind::S_RATOF: // RATOF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1000 "parser.cpp"
        break;

      case symbol_kind::S_RIOTA: // RIOTA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1006 "parser.cpp"
        break;

      case symbol_kind::S_RBREAK: // RBREAK
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1012 "parser.cpp"
        break;

      case symbol_kind::S_RCONTINUE: // RCONTINUE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1018 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1024 "parser.cpp"
        break;

      case symbol_kind::S_MAYOR: // MAYOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1030 "parser.cpp"
        break;

      case symbol_kind::S_MENOR: // MENOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1036 "parser.cpp"
        break;

      case symbol_kind::S_MAYEQU: // MAYEQU
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1042 "parser.cpp"
        break;

      case symbol_kind::S_MENEQU: // MENEQU
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1048 "parser.cpp"
        break;

      case symbol_kind::S_EQU: // EQU
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1054 "parser.cpp"
        break;

      case symbol_kind::S_DIFF: // DIFF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1060 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1066 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1072 "parser.cpp"
        break;

      case symbol_kind::S_NOT: // NOT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1078 "parser.cpp"
        break;

      case symbol_kind::S_VPBACK: // VPBACK
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1084 "parser.cpp"
        break;

      case symbol_kind::S_VGET: // VGET
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1090 "parser.cpp"
        break;

      case symbol_kind::S_VREMOVE: // VREMOVE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1096 "parser.cpp"
        break;

      case symbol_kind::S_VSIZE: // VSIZE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1102 "parser.cpp"
        break;

      case symbol_kind::S_VPFRONT: // VPFRONT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1108 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1114 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1120 "parser.cpp"
        break;

      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1126 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1132 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1138 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1144 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1150 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1156 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1162 "parser.cpp"
        break;

      case symbol_kind::S_PUSHBACK: // PUSHBACK
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1168 "parser.cpp"
        break;

      case symbol_kind::S_PUSHFRONT: // PUSHFRONT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1174 "parser.cpp"
        break;

      case symbol_kind::S_GET: // GET
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1180 "parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1186 "parser.cpp"
        break;

      case symbol_kind::S_REMOVE: // REMOVE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1192 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1198 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1204 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1210 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1216 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1222 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1228 "parser.cpp"
        break;

      case symbol_kind::S_EXPRESSION: // EXPRESSION
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1234 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1240 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1246 "parser.cpp"
        break;

      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1252 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1258 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1264 "parser.cpp"
        break;

      case symbol_kind::S_ASSIGNATION: // ASSIGNATION
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1270 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1276 "parser.cpp"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1282 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1288 "parser.cpp"
        break;

      case symbol_kind::S_MEAN: // MEAN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1294 "parser.cpp"
        break;

      case symbol_kind::S_MEDIAN: // MEDIAN
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1300 "parser.cpp"
        break;

      case symbol_kind::S_MODE: // MODE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1306 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1312 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1318 "parser.cpp"
        break;

      case symbol_kind::S_ATOI: // ATOI
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1324 "parser.cpp"
        break;

      case symbol_kind::S_ATOF: // ATOF
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1330 "parser.cpp"
        break;

      case symbol_kind::S_IOTA: // IOTA
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1336 "parser.cpp"
        break;

      case symbol_kind::S_INCREMENT: // INCREMENT
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1342 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1348 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1354 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1360 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_VECTOR: // DECLARE_VECTOR
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1366 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_MATRIX: // DECLARE_MATRIX
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1372 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 202 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1378 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 202 "parser.y"
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
      case symbol_kind::S_STRUCT_ACCESS: // STRUCT_ACCESS
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
#line 210 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1765 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 216 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1776 "parser.cpp"
    break;

  case 4: // START: LIST_STRUCT LIST_FUNC MAIN
#line 223 "parser.y"
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
#line 233 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1797 "parser.cpp"
    break;

  case 6: // LIST_FUNC: FUNCTION
#line 238 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1806 "parser.cpp"
    break;

  case 7: // LIST_STRUCT: LIST_STRUCT DECLARE_STRUCT
#line 245 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1815 "parser.cpp"
    break;

  case 8: // LIST_STRUCT: DECLARE_STRUCT
#line 250 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1824 "parser.cpp"
    break;

  case 9: // FUNCTION: TYPES ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
#line 257 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1832 "parser.cpp"
    break;

  case 10: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 261 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1840 "parser.cpp"
    break;

  case 11: // FUNCTION: ID ID PARA FUNCTION_LIST PARC LLAVA LIST_INST LLAVC
#line 265 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(0,0,STRUCT,yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1848 "parser.cpp"
    break;

  case 12: // FUNCTION_LIST: FUNCTION_LIST ',' TYPES ID
#line 271 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1857 "parser.cpp"
    break;

  case 13: // FUNCTION_LIST: FUNCTION_LIST ',' RVECTOR MENOR TYPES MAYOR ID
#line 276 "parser.y"
        {
            yystack_[6].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),VECTOR);
            yylhs.value.as < map_struct_dec* > () = yystack_[6].value.as < map_struct_dec* > ();
        }
#line 1866 "parser.cpp"
    break;

  case 14: // FUNCTION_LIST: FUNCTION_LIST ',' TYPES ID CORA EXP CORC
#line 281 "parser.y"
        {
            yystack_[6].value.as < map_struct_dec* > ()->newMap(yystack_[3].value.as < std::string > (),yystack_[4].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[6].value.as < map_struct_dec* > ();
        }
#line 1875 "parser.cpp"
    break;

  case 15: // FUNCTION_LIST: FUNCTION_LIST ',' TYPES ID CORA EXP CORC CORA EXP CORC CORA EXP CORC
#line 286 "parser.y"
        {
            yystack_[12].value.as < map_struct_dec* > ()->newMap(yystack_[9].value.as < std::string > (),yystack_[10].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[12].value.as < map_struct_dec* > ();
        }
#line 1884 "parser.cpp"
    break;

  case 16: // FUNCTION_LIST: TYPES ID
#line 291 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1893 "parser.cpp"
    break;

  case 17: // FUNCTION_LIST: RVECTOR MENOR TYPES MAYOR ID
#line 296 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), VECTOR);
        }
#line 1902 "parser.cpp"
    break;

  case 18: // FUNCTION_LIST: TYPES ID CORA EXP CORC
#line 301 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[3].value.as < std::string > (), yystack_[4].value.as < TipoDato > ());
        }
#line 1911 "parser.cpp"
    break;

  case 19: // FUNCTION_LIST: TYPES ID CORA EXP CORC CORA EXP CORC CORA EXP CORC
#line 306 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[9].value.as < std::string > (), yystack_[10].value.as < TipoDato > ());
        }
#line 1920 "parser.cpp"
    break;

  case 20: // MAIN: TYPES RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 313 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < TipoDato > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1928 "parser.cpp"
    break;

  case 21: // LIST_INST: LIST_INST INSTRUCTION
#line 319 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1937 "parser.cpp"
    break;

  case 22: // LIST_INST: INSTRUCTION
#line 324 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1946 "parser.cpp"
    break;

  case 23: // INSTRUCTION: PRINT ';'
#line 330 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1952 "parser.cpp"
    break;

  case 24: // INSTRUCTION: EXPRESSION ';'
#line 331 "parser.y"
                            {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1958 "parser.cpp"
    break;

  case 25: // INSTRUCTION: IF
#line 332 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1964 "parser.cpp"
    break;

  case 26: // INSTRUCTION: WHILE
#line 333 "parser.y"
                    { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1970 "parser.cpp"
    break;

  case 27: // INSTRUCTION: FOR
#line 334 "parser.y"
                  { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1976 "parser.cpp"
    break;

  case 28: // INSTRUCTION: DECLARATION ';'
#line 335 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1982 "parser.cpp"
    break;

  case 29: // INSTRUCTION: ASSIGNATION ';'
#line 336 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1988 "parser.cpp"
    break;

  case 30: // INSTRUCTION: CREATE_STRUCT
#line 337 "parser.y"
                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1994 "parser.cpp"
    break;

  case 31: // INSTRUCTION: DECLARE_STRUCT
#line 338 "parser.y"
                             { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 2000 "parser.cpp"
    break;

  case 32: // INSTRUCTION: DECLARE_VECTOR ';'
#line 339 "parser.y"
                                 {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2006 "parser.cpp"
    break;

  case 33: // INSTRUCTION: DECLARE_MATRIX ';'
#line 340 "parser.y"
                                 {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2012 "parser.cpp"
    break;

  case 34: // INSTRUCTION: BREAK ';'
#line 341 "parser.y"
                        {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2018 "parser.cpp"
    break;

  case 35: // INSTRUCTION: CONTINUE ';'
#line 342 "parser.y"
                           {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2024 "parser.cpp"
    break;

  case 36: // INSTRUCTION: RETURN ';'
#line 343 "parser.y"
                         {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2030 "parser.cpp"
    break;

  case 37: // INSTRUCTION: CALL_INST
#line 344 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 2036 "parser.cpp"
    break;

  case 38: // INSTRUCTION: PUSHBACK ';'
#line 345 "parser.y"
                           {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2042 "parser.cpp"
    break;

  case 39: // INSTRUCTION: PUSHFRONT ';'
#line 346 "parser.y"
                            {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2048 "parser.cpp"
    break;

  case 40: // INSTRUCTION: REMOVE ';'
#line 347 "parser.y"
                         {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 2054 "parser.cpp"
    break;

  case 41: // PRINT: PRINTF PARA EXP_LIST PARC
#line 350 "parser.y"
                                   { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 2060 "parser.cpp"
    break;

  case 42: // PUSHBACK: ID '.' VPBACK PARA EXP PARC
#line 353 "parser.y"
                                       {yylhs.value.as < instruction* > () = new func_pushback(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2066 "parser.cpp"
    break;

  case 43: // PUSHFRONT: ID '.' VPFRONT PARA EXP PARC
#line 356 "parser.y"
                                         {yylhs.value.as < instruction* > () = new func_pushfront(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2072 "parser.cpp"
    break;

  case 44: // GET: ID '.' VGET PARA EXP PARC
#line 359 "parser.y"
                                {yylhs.value.as < expression* > () = new func_get(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2078 "parser.cpp"
    break;

  case 45: // SIZE: ID '.' VSIZE PARA PARC
#line 362 "parser.y"
                              {yylhs.value.as < expression* > () = new func_size(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[4].value.as < std::string > ());}
#line 2084 "parser.cpp"
    break;

  case 46: // REMOVE: ID '.' VREMOVE PARA EXP PARC
#line 365 "parser.y"
                                      {yylhs.value.as < instruction* > () = new func_remove(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2090 "parser.cpp"
    break;

  case 47: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 369 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 2098 "parser.cpp"
    break;

  case 48: // IF: RIF EXP LLAVA LIST_INST LLAVC
#line 373 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (),nullptr,nullptr);
    }
#line 2106 "parser.cpp"
    break;

  case 49: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
#line 377 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > (),nullptr);
    }
#line 2114 "parser.cpp"
    break;

  case 50: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 381 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 2122 "parser.cpp"
    break;

  case 51: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 387 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 2131 "parser.cpp"
    break;

  case 52: // ELSEIF_LIST: ELSEIF
#line 392 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 2140 "parser.cpp"
    break;

  case 53: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 399 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 2148 "parser.cpp"
    break;

  case 54: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 404 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 2154 "parser.cpp"
    break;

  case 55: // WHILE: RWHILE PARA EXP PARC LLAVA LIST_INST LLAVC
#line 408 "parser.y"
                                                  {yylhs.value.as < instruction* > () = new func_while(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 2160 "parser.cpp"
    break;

  case 56: // FOR: RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC
#line 411 "parser.y"
                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line, yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 2166 "parser.cpp"
    break;

  case 57: // EXPRESSION: EXP
#line 414 "parser.y"
                 {yylhs.value.as < instruction* > () = new func_expression(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < expression* > ());}
#line 2172 "parser.cpp"
    break;

  case 58: // DECLARE_STRUCT: RSTRUCT ID LLAVA DECLARE_LIST LLAVC
#line 417 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new declare_struct(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 2178 "parser.cpp"
    break;

  case 59: // DECLARE_LIST: DECLARE_LIST TYPES ID ';'
#line 421 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2187 "parser.cpp"
    break;

  case 60: // DECLARE_LIST: DECLARE_LIST ID ID ';'
#line 426 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),STRUCT);
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2196 "parser.cpp"
    break;

  case 61: // DECLARE_LIST: TYPES ID ';'
#line 431 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 2205 "parser.cpp"
    break;

  case 62: // DECLARE_LIST: ID ID ';'
#line 436 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), STRUCT);
        }
#line 2214 "parser.cpp"
    break;

  case 63: // CREATE_STRUCT: RSTRUCT ID ID '=' LLAVA EXP_LIST LLAVC ';'
#line 442 "parser.y"
                                                           { yylhs.value.as < instruction* > () = new create_struct(yystack_[7].location.begin.line, yystack_[7].location.begin.column,yystack_[6].value.as < std::string > (),yystack_[5].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 2220 "parser.cpp"
    break;

  case 64: // EXP_LIST: EXP_LIST ',' EXP
#line 446 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 2229 "parser.cpp"
    break;

  case 65: // EXP_LIST: EXP
#line 451 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 2238 "parser.cpp"
    break;

  case 66: // DECLARATION: TYPES ID '=' EXP
#line 457 "parser.y"
                               {yylhs.value.as < instruction* > () = new declare(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 2244 "parser.cpp"
    break;

  case 67: // DECLARATION: TYPES ID
#line 458 "parser.y"
                       {yylhs.value.as < instruction* > () = new declare(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),nullptr);}
#line 2250 "parser.cpp"
    break;

  case 68: // ASSIGNATION: ID '=' EXP
#line 460 "parser.y"
                         {yylhs.value.as < instruction* > () = new assign(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 2256 "parser.cpp"
    break;

  case 69: // ASSIGNATION: ID CORA PRIMITIVE CORC '=' PRIMITIVE
#line 461 "parser.y"
                                                   {yylhs.value.as < instruction* > () = new assign_vector(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[3].value.as < expression* > (),yystack_[0].value.as < expression* > ());}
#line 2262 "parser.cpp"
    break;

  case 70: // ASSIGNATION: ID '.' ID '=' EXP
#line 462 "parser.y"
                                {yylhs.value.as < instruction* > () = new assign_struct(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[4].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 2268 "parser.cpp"
    break;

  case 71: // BREAK: RBREAK
#line 465 "parser.y"
               {yylhs.value.as < instruction* > () = new func_break(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 2274 "parser.cpp"
    break;

  case 72: // CONTINUE: RCONTINUE
#line 468 "parser.y"
                     {yylhs.value.as < instruction* > () = new func_continue(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 2280 "parser.cpp"
    break;

  case 73: // RETURN: RRETURN EXP
#line 471 "parser.y"
                     { yylhs.value.as < instruction* > () = new func_return(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ()); }
#line 2286 "parser.cpp"
    break;

  case 74: // RETURN: RRETURN
#line 472 "parser.y"
                  { yylhs.value.as < instruction* > () = new func_return(yystack_[0].location.begin.line, yystack_[0].location.begin.column,nullptr); }
#line 2292 "parser.cpp"
    break;

  case 75: // MEAN: RMEAN PARA ID PARC
#line 475 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mean(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2298 "parser.cpp"
    break;

  case 76: // MEDIAN: RMEDIAN PARA ID PARC
#line 478 "parser.y"
                              {yylhs.value.as < expression* > () = new func_median(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2304 "parser.cpp"
    break;

  case 77: // MODE: RMODE PARA ID PARC
#line 481 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mode(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2310 "parser.cpp"
    break;

  case 78: // TYPES: INT
#line 484 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 2316 "parser.cpp"
    break;

  case 79: // TYPES: TSTRING
#line 485 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 2322 "parser.cpp"
    break;

  case 80: // TYPES: BOOLEAN
#line 486 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 2328 "parser.cpp"
    break;

  case 81: // TYPES: FLOAT
#line 487 "parser.y"
            { yylhs.value.as < TipoDato > () = FLOAT; }
#line 2334 "parser.cpp"
    break;

  case 82: // TYPES: VOID
#line 488 "parser.y"
           {yylhs.value.as < TipoDato > () = VOID;}
#line 2340 "parser.cpp"
    break;

  case 83: // TYPES: RVECTOR
#line 489 "parser.y"
              {yylhs.value.as < TipoDato > () = VECTOR;}
#line 2346 "parser.cpp"
    break;

  case 84: // EXP: EXP SUMA EXP
#line 493 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+");}
#line 2352 "parser.cpp"
    break;

  case 85: // EXP: EXP MENOS EXP
#line 494 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 2358 "parser.cpp"
    break;

  case 86: // EXP: EXP POR EXP
#line 495 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 2364 "parser.cpp"
    break;

  case 87: // EXP: EXP DIV EXP
#line 496 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2370 "parser.cpp"
    break;

  case 88: // EXP: EXP MOD EXP
#line 497 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2376 "parser.cpp"
    break;

  case 89: // EXP: INCREMENT
#line 499 "parser.y"
                {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2382 "parser.cpp"
    break;

  case 90: // EXP: EXP MAYOR EXP
#line 501 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">");}
#line 2388 "parser.cpp"
    break;

  case 91: // EXP: EXP MAYEQU EXP
#line 502 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">=");}
#line 2394 "parser.cpp"
    break;

  case 92: // EXP: EXP MENOR EXP
#line 503 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<");}
#line 2400 "parser.cpp"
    break;

  case 93: // EXP: EXP MENEQU EXP
#line 504 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<=");}
#line 2406 "parser.cpp"
    break;

  case 94: // EXP: EXP EQU EXP
#line 505 "parser.y"
                  {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "==");}
#line 2412 "parser.cpp"
    break;

  case 95: // EXP: EXP DIFF EXP
#line 506 "parser.y"
                   {yylhs.value.as < expression* > () =  new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!=");}
#line 2418 "parser.cpp"
    break;

  case 96: // EXP: EXP AND EXP
#line 508 "parser.y"
                  {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&");}
#line 2424 "parser.cpp"
    break;

  case 97: // EXP: EXP OR EXP
#line 509 "parser.y"
                 {yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||");}
#line 2430 "parser.cpp"
    break;

  case 98: // EXP: NOT EXP
#line 511 "parser.y"
    {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
#line 2438 "parser.cpp"
    break;

  case 99: // EXP: MENOS EXP
#line 515 "parser.y"
                {
        yylhs.value.as < expression* > () = new operation(yystack_[0].location.begin.line, yystack_[0].location.begin.column,new primitive(0,0,INTEGER, "", 0,0.0,false),yystack_[0].value.as < expression* > (),"-");
        }
#line 2446 "parser.cpp"
    break;

  case 100: // EXP: PARA EXP PARC
#line 519 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2452 "parser.cpp"
    break;

  case 101: // EXP: ATOI
#line 520 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2458 "parser.cpp"
    break;

  case 102: // EXP: ATOF
#line 521 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2464 "parser.cpp"
    break;

  case 103: // EXP: IOTA
#line 522 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2470 "parser.cpp"
    break;

  case 104: // EXP: CORA EXP_LIST CORC
#line 523 "parser.y"
                         { yylhs.value.as < expression* > () = new expression_vector(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 2476 "parser.cpp"
    break;

  case 105: // EXP: CALL_EXP
#line 524 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2482 "parser.cpp"
    break;

  case 106: // EXP: GET
#line 525 "parser.y"
          {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2488 "parser.cpp"
    break;

  case 107: // EXP: SIZE
#line 526 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2494 "parser.cpp"
    break;

  case 108: // EXP: MEAN
#line 527 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2500 "parser.cpp"
    break;

  case 109: // EXP: MEDIAN
#line 528 "parser.y"
             {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2506 "parser.cpp"
    break;

  case 110: // EXP: MODE
#line 529 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2512 "parser.cpp"
    break;

  case 111: // EXP: PRIMITIVE
#line 531 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2518 "parser.cpp"
    break;

  case 112: // EXP: STRUCT_ACCESS
#line 532 "parser.y"
                   {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2524 "parser.cpp"
    break;

  case 113: // ATOI: RATOI PARA PRIMITIVE PARC
#line 536 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atoi(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2530 "parser.cpp"
    break;

  case 114: // ATOF: RATOF PARA PRIMITIVE PARC
#line 539 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atof(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2536 "parser.cpp"
    break;

  case 115: // IOTA: RIOTA PARA EXP PARC
#line 542 "parser.y"
                           {yylhs.value.as < expression* > () = new func_iota(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2542 "parser.cpp"
    break;

  case 116: // INCREMENT: PRIMITIVE INC
#line 546 "parser.y"
                         { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, yystack_[1].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
#line 2548 "parser.cpp"
    break;

  case 117: // PRIMITIVE: NUMERO
#line 550 "parser.y"
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
#line 2565 "parser.cpp"
    break;

  case 118: // PRIMITIVE: STRING
#line 563 "parser.y"
            {
                std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
                std::string str2 = str1.erase(str1.length()-1,1);
                yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,STRING,str2,0,0.0,false);
            }
#line 2575 "parser.cpp"
    break;

  case 119: // PRIMITIVE: NLL
#line 568 "parser.y"
                  {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,NULO,"",0,0.0,false);}
#line 2581 "parser.cpp"
    break;

  case 120: // PRIMITIVE: BOOLTRUE
#line 569 "parser.y"
                      {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, true);}
#line 2587 "parser.cpp"
    break;

  case 121: // PRIMITIVE: BOOLFALSE
#line 570 "parser.y"
                       {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL, "", 0, 0.0, false);}
#line 2593 "parser.cpp"
    break;

  case 122: // PRIMITIVE: LIST_ARR
#line 571 "parser.y"
                      {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2599 "parser.cpp"
    break;

  case 123: // LIST_ARR: LIST_ARR CORA EXP CORC CORA EXP CORC
#line 574 "parser.y"
                                               { yylhs.value.as < expression* > () = new matrix_access(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[6].value.as < expression* > (),yystack_[4].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2605 "parser.cpp"
    break;

  case 124: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 575 "parser.y"
                                { yylhs.value.as < expression* > () = new vector_access(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2611 "parser.cpp"
    break;

  case 125: // LIST_ARR: ID
#line 576 "parser.y"
             {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ()); }
#line 2617 "parser.cpp"
    break;

  case 126: // STRUCT_ACCESS: ID '.' ID
#line 580 "parser.y"
                { 
                    std::string str1 = "NO";
                    yylhs.value.as < expression* > () = new struct_access(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > (),str1);
                }
#line 2626 "parser.cpp"
    break;

  case 127: // STRUCT_ACCESS: ID '.' ID '.' ID
#line 584 "parser.y"
                                 { yylhs.value.as < expression* > () = new struct_access(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[4].value.as < std::string > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < std::string > ()); }
#line 2632 "parser.cpp"
    break;

  case 128: // DECLARE_VECTOR: RVECTOR MENOR TYPES MAYOR ID '=' EXP
#line 587 "parser.y"
                                                       {yylhs.value.as < instruction* > () = new declare_vector(yystack_[6].location.begin.line, yystack_[6].location.begin.column, yystack_[4].value.as < TipoDato > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > ());}
#line 2638 "parser.cpp"
    break;

  case 129: // DECLARE_VECTOR: RVECTOR MENOR TYPES MAYOR ID
#line 588 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declare_vector(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[2].value.as < TipoDato > (), yystack_[0].value.as < std::string > (), nullptr);}
#line 2644 "parser.cpp"
    break;

  case 130: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 591 "parser.y"
                                                                     {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[8].location.begin.line, yystack_[8].location.begin.column,yystack_[8].value.as < TipoDato > (), yystack_[7].value.as < std::string > (), yystack_[5].value.as < expression* > (), nullptr, nullptr, yystack_[1].value.as < list_expression* > ());}
#line 2650 "parser.cpp"
    break;

  case 131: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 592 "parser.y"
                                                                                          {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[11].location.begin.line, yystack_[11].location.begin.column,yystack_[11].value.as < TipoDato > (), yystack_[10].value.as < std::string > (), yystack_[8].value.as < expression* > () , yystack_[5].value.as < expression* > (), nullptr, yystack_[1].value.as < list_expression* > ());}
#line 2656 "parser.cpp"
    break;

  case 132: // DECLARE_MATRIX: TYPES ID CORA PRIMITIVE CORC CORA PRIMITIVE CORC CORA PRIMITIVE CORC '=' CORA EXP_LIST CORC
#line 593 "parser.y"
                                                                                                              {yylhs.value.as < instruction* > () = new declare_matrix(yystack_[14].location.begin.line, yystack_[14].location.begin.column,yystack_[14].value.as < TipoDato > (), yystack_[13].value.as < std::string > (), yystack_[11].value.as < expression* > (), yystack_[8].value.as < expression* > (), yystack_[5].value.as < expression* > (), yystack_[1].value.as < list_expression* > ());}
#line 2662 "parser.cpp"
    break;

  case 133: // CALL_EXP: ID PARA EXP_LIST PARC
#line 597 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 2668 "parser.cpp"
    break;

  case 134: // CALL_EXP: ID PARA PARC
#line 598 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(0,0,yystack_[2].value.as < std::string > (),nullptr); }
#line 2674 "parser.cpp"
    break;

  case 135: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 601 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 2680 "parser.cpp"
    break;

  case 136: // CALL_INST: ID PARA PARC ';'
#line 602 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(0,0,yystack_[3].value.as < std::string > (),nullptr); }
#line 2686 "parser.cpp"
    break;


#line 2690 "parser.cpp"

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





  const short Parser::yypact_ninf_ = -129;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     200,     5,  -129,  -129,  -129,    15,  -129,  -129,  -129,    18,
     192,   200,  -129,  -129,  -129,    74,     0,    30,  -129,  -129,
    -129,   192,  -129,    81,    83,    84,   120,   267,  -129,  1276,
      85,    59,   -10,    98,   100,   162,   102,    91,    -7,    92,
     836,    93,   902,   105,    68,   125,  -129,   134,    90,   731,
     126,   731,   107,   731,    97,   144,   827,  -129,   106,   108,
    -129,  -129,    12,  -129,   155,   130,  -129,  -129,   827,   827,
    -129,   827,   827,   161,   163,   164,   166,   167,   169,   170,
     172,   173,  -129,  -129,   827,   827,   290,  -129,   131,   133,
     137,  -129,  -129,   156,  -129,  -129,  -129,   157,  -129,  -129,
     158,   159,   160,   165,   168,  -129,  -129,  -129,   217,  1231,
    -129,  -129,  -129,  -129,   196,   206,  -129,   171,   174,  -129,
    -129,   731,   339,   225,   388,   836,   212,     3,  1071,  -129,
    -129,   771,   140,   827,     2,    80,   836,   844,   -12,  1231,
      64,   220,   827,   836,   827,   230,   233,   234,   140,   140,
     827,  1231,   292,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,     9,   827,   827,   827,   827,
     827,   827,   827,   827,   827,   827,   827,   827,   827,  -129,
     827,  -129,  -129,   437,  -129,  -129,  -129,   197,   827,   799,
       7,   224,   193,    10,  -129,   232,  1231,   -16,   235,   241,
     243,   244,   245,   202,   236,  -129,  -129,   827,   731,   856,
     219,   276,    17,   268,   270,   271,   273,   274,   892,   140,
     827,    64,    64,  -129,  -129,  -129,   341,   341,   341,   341,
     111,   111,   292,   292,  1103,  -129,   286,  1111,  -129,    21,
     231,   827,  -129,   248,   251,   827,   302,   827,   827,   827,
     296,   827,   297,   329,  1231,   486,   318,   827,   300,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,   335,  1231,   337,  -129,
     342,  -129,  1143,  -129,   140,  1231,  -129,   904,   940,   952,
    -129,   988,   827,   304,   352,   731,  1028,    23,   827,   827,
     365,  -129,  -129,  -129,  -129,  -129,    14,   827,    58,   352,
    -129,  -129,   535,   827,   140,   366,  1151,  1183,   827,   328,
    1231,   731,   827,  -129,  -129,  -129,  1000,   367,   827,  -129,
     369,  1191,  -129,   584,  1063,   372,    25,    20,   827,  -129,
    -129,   731,   731,   140,   371,  -129,  1223,   633,   682,   384,
     827,  -129,  -129,  -129,   346,    42,   389,  -129,   827,    46,
    -129
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,    79,    81,    80,     0,    83,    78,    82,     0,
       0,     0,     6,     2,     8,     0,     0,     0,     1,     5,
       3,     0,     7,     0,     0,     0,     0,     0,     4,     0,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,    83,     0,     0,    62,     0,     0,
      61,   117,   125,   118,     0,    83,   120,   121,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,    74,     0,     0,    22,     0,     0,
       0,   106,   107,     0,    25,    26,    27,     0,    31,    30,
       0,     0,     0,     0,     0,   108,   109,   110,     0,    57,
     101,   102,   103,    89,   111,   122,   112,     0,     0,   105,
      37,     0,     0,     0,     0,     0,    12,   125,     0,    60,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    98,    10,    21,    23,    38,    39,    40,    24,
      28,    29,    34,    35,    36,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,    32,    33,     0,    20,    17,    11,     0,     0,     0,
       0,    18,   134,     0,   125,     0,    68,   126,     0,     0,
       0,     0,     0,     0,     0,   100,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    90,    92,    91,    93,
      94,    95,    96,    97,     0,     9,     0,     0,   134,     0,
     126,     0,   136,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,     0,     0,    67,    41,
      75,    76,    77,   113,   114,   115,     0,    66,   124,    13,
      14,   133,     0,   135,     0,    70,   127,     0,     0,     0,
      45,     0,     0,   129,    48,     0,     0,     0,     0,     0,
       0,    69,    42,    44,    46,    43,     0,     0,     0,    49,
      52,    50,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,    51,    47,    55,     0,     0,     0,   123,
       0,     0,    63,     0,     0,     0,     0,     0,     0,    19,
      54,     0,     0,     0,     0,   130,     0,     0,     0,     0,
       0,    15,    53,    56,     0,     0,     0,   131,     0,     0,
     132
  };

  const short
  Parser::yypgoto_[] =
  {
    -129,  -129,   398,  -129,    27,   382,    72,   -50,   -84,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,   114,   115,  -129,
    -129,  -129,    22,  -129,  -129,  -121,   272,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,    24,   -56,  -129,  -129,  -129,  -129,
    -128,  -129,  -129,  -129,  -129,  -129,  -129
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     9,    10,    11,    12,    32,    13,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   299,   300,   301,    95,
      96,    97,    98,    35,    99,   138,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120
  };

  const short
  Parser::yytable_[] =
  {
     128,   122,   154,   124,   195,    41,   197,   206,    50,    16,
     193,   240,   137,   139,    26,   140,   141,   189,    18,    17,
     216,   217,    14,   212,    15,   243,   131,   219,   151,   152,
     132,   309,   259,    22,    15,    23,   271,    19,   154,   335,
     154,   304,   245,   333,   246,    15,    27,   207,    19,    42,
      33,    36,    42,    33,   198,   199,   200,   201,   202,    47,
     199,   347,   201,   190,    52,   350,    55,   220,   239,   207,
     133,   183,   134,   207,   311,   139,   207,   196,    24,   207,
     207,   305,    20,   334,   203,    24,   209,   312,   139,   168,
     169,   266,   170,    28,   218,    25,    27,    29,    30,   154,
      39,   207,    43,    40,    44,   207,    48,    49,    51,    53,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,    56,   234,    57,     2,     3,     4,    58,
      31,     7,   237,   139,   166,   167,   168,   169,    59,   170,
       8,   125,   121,    61,   194,    63,   291,    60,   126,   187,
     123,   254,    66,    67,   171,   172,   173,   174,   255,   135,
     204,   296,    70,   129,   267,   130,    45,   211,     2,     3,
       4,   154,     6,     7,   136,   142,   317,   143,   144,    46,
     145,   146,     8,   147,   148,   272,   149,   150,   155,   275,
     156,   277,   278,   279,   157,   281,     1,   327,     2,     3,
       4,   286,     6,     7,     1,   339,     2,     3,     4,     5,
       6,     7,     8,   158,   159,   160,   161,   162,   154,   345,
       8,   165,   163,   179,   180,   164,   139,   349,   181,   185,
     188,   182,   306,   307,   213,   302,   208,   214,   215,   154,
     236,   310,   241,   166,   167,   168,   169,   316,   170,   247,
     242,   244,   321,   154,   154,   248,   324,   249,   250,   251,
     252,   323,   139,   171,   172,   173,   174,   175,   176,   177,
     178,    34,   336,     2,     3,     4,   257,     6,     7,   253,
     258,   337,   338,   260,   139,   261,   262,     8,   263,   264,
     269,   246,   139,    61,    62,    63,     2,     3,     4,    64,
      65,     7,    66,    67,    68,   273,   276,   153,    69,   274,
       8,   280,    70,   282,    71,   166,   167,   168,   169,    72,
     170,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,   283,   285,   171,   172,   173,   174,   175,
     176,    85,    61,    62,    63,     2,     3,     4,    64,    65,
       7,    66,    67,    68,   287,   288,   184,    69,   220,     8,
     289,    70,   297,    71,   166,   167,   168,   169,    72,   170,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   298,   308,   318,   322,   326,   328,   332,   340,
      85,    61,    62,    63,     2,     3,     4,    64,    65,     7,
      66,    67,    68,   344,   346,   186,    69,   348,     8,    21,
      70,    38,    71,   313,   314,   210,     0,    72,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      61,    62,    63,     2,     3,     4,    64,    65,     7,    66,
      67,    68,     0,     0,   235,    69,     0,     8,     0,    70,
       0,    71,     0,     0,     0,     0,    72,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    61,
      62,    63,     2,     3,     4,    64,    65,     7,    66,    67,
      68,     0,     0,   284,    69,     0,     8,     0,    70,     0,
      71,     0,     0,     0,     0,    72,     0,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    61,    62,
      63,     2,     3,     4,    64,    65,     7,    66,    67,    68,
       0,     0,   315,    69,     0,     8,     0,    70,     0,    71,
       0,     0,     0,     0,    72,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    61,    62,    63,
       2,     3,     4,    64,    65,     7,    66,    67,    68,     0,
       0,   330,    69,     0,     8,     0,    70,     0,    71,     0,
       0,     0,     0,    72,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    61,    62,    63,     2,
       3,     4,    64,    65,     7,    66,    67,    68,     0,     0,
     342,    69,     0,     8,     0,    70,     0,    71,     0,     0,
       0,     0,    72,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    61,    62,    63,     2,     3,
       4,    64,    65,     7,    66,    67,    68,     0,     0,   343,
      69,     0,     8,     0,    70,     0,    71,     0,     0,     0,
       0,    72,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    61,    62,    63,     2,     3,     4,
      64,    65,     7,    66,    67,    68,     0,     0,     0,    69,
       0,     8,     0,    70,     0,    71,     0,     0,     0,     0,
      72,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    61,   127,    63,     0,     0,     0,
       0,     0,    85,    66,    67,    68,   192,     0,     0,    69,
       0,     0,     0,    70,     0,    71,     0,     0,     0,     0,
       0,     0,    61,   127,    63,    76,    77,    78,    79,    80,
      81,    66,    67,    68,   238,     0,     0,    69,     0,     0,
       0,    70,    85,    71,     0,     0,     0,     0,     0,     0,
      61,   127,    63,    76,    77,    78,    79,    80,    81,    66,
      67,    68,     2,     3,     4,    69,     6,     7,     0,    70,
      85,    71,     0,     0,     0,     0,     8,     0,     0,   205,
       0,    76,    77,    78,    79,    80,    81,   166,   167,   168,
     169,   256,   170,     0,     0,     0,     0,     0,    85,   166,
     167,   168,   169,     0,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,     0,     0,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   265,     2,     3,
       4,     0,    54,     7,     0,   166,   167,   168,   169,   292,
     170,     0,     8,     0,     0,     0,     0,   166,   167,   168,
     169,     0,   170,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,     0,     0,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   293,     0,     0,     0,     0,
       0,     0,     0,   166,   167,   168,   169,   294,   170,     0,
       0,     0,     0,     0,     0,   166,   167,   168,   169,     0,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,     0,     0,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   295,     0,     0,     0,     0,     0,     0,
       0,   166,   167,   168,   169,   325,   170,     0,     0,     0,
       0,     0,     0,   166,   167,   168,   169,     0,   170,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,     0,
       0,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   166,   167,   168,   169,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   331,
       0,     0,     0,     0,     0,   303,   166,   167,   168,   169,
     191,   170,     0,     0,   166,   167,   168,   169,     0,   170,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   171,   172,   173,   174,   175,   176,
     177,   178,   268,     0,     0,     0,   166,   167,   168,   169,
     270,   170,     0,     0,   166,   167,   168,   169,     0,   170,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   171,   172,   173,   174,   175,   176,
     177,   178,   290,     0,     0,     0,   166,   167,   168,   169,
     319,   170,     0,     0,   166,   167,   168,   169,     0,   170,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   171,   172,   173,   174,   175,   176,
     177,   178,   320,     0,     0,     0,   166,   167,   168,   169,
     329,   170,     0,     0,   166,   167,   168,   169,     0,   170,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   171,   172,   173,   174,   175,   176,
     177,   178,   341,     0,     0,     0,   166,   167,   168,   169,
       0,   170,     0,     0,   166,   167,   168,   169,     0,   170,
       0,     0,     0,     0,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   171,   172,   173,   174,   175,   176,
     177,   178,     2,     3,     4,     0,    31,     7,     0,     0,
       0,    37,     0,     0,     0,     0,     8
  };

  const short
  Parser::yycheck_[] =
  {
      56,    51,    86,    53,   132,    15,     4,    19,    15,     4,
     131,     4,    68,    69,    14,    71,    72,    14,     0,     4,
     148,   149,     0,   144,     0,    15,    14,    18,    84,    85,
      18,    17,    15,    11,    10,    11,    15,    10,   122,    19,
     124,    18,    58,    18,    60,    21,    16,    59,    21,    59,
      26,    27,    59,    29,    52,    53,    54,    55,    56,    35,
      53,    19,    55,    60,    40,    19,    42,    58,   189,    59,
      58,   121,    60,    59,    16,   131,    59,   133,     4,    59,
      59,    58,    10,    58,     4,     4,   142,    29,   144,    25,
      26,   219,    28,    21,   150,    21,    16,    14,    14,   183,
      15,    59,     4,    44,     4,    59,     4,    16,    16,    16,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,    18,   180,    57,     6,     7,     8,     4,
      10,    11,   188,   189,    23,    24,    25,    26,     4,    28,
      20,    44,    16,     3,     4,     5,   274,    57,     4,   125,
      43,   207,    12,    13,    43,    44,    45,    46,   208,     4,
     136,   282,    22,    57,   220,    57,     4,   143,     6,     7,
       8,   255,    10,    11,    44,    14,   304,    14,    14,    17,
      14,    14,    20,    14,    14,   241,    14,    14,    57,   245,
      57,   247,   248,   249,    57,   251,     4,   318,     6,     7,
       8,   257,    10,    11,     4,   333,     6,     7,     8,     9,
      10,    11,    20,    57,    57,    57,    57,    57,   302,   340,
      20,     4,    57,    27,    18,    57,   282,   348,    57,     4,
      18,    57,   288,   289,     4,   285,    16,     4,     4,   323,
      43,   297,    18,    23,    24,    25,    26,   303,    28,    14,
      57,    19,   308,   337,   338,    14,   312,    14,    14,    14,
      58,   311,   318,    43,    44,    45,    46,    47,    48,    49,
      50,     4,   328,     6,     7,     8,    57,    10,    11,    43,
       4,   331,   332,    15,   340,    15,    15,    20,    15,    15,
       4,    60,   348,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    57,     4,    17,    18,    58,
      20,    15,    22,    16,    24,    23,    24,    25,    26,    29,
      28,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     4,    16,    43,    44,    45,    46,    47,
      48,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    19,    18,    17,    18,    58,    20,
      18,    22,    58,    24,    23,    24,    25,    26,    29,    28,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    30,    18,    18,    57,    19,    18,    16,    18,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    19,    58,    17,    18,    18,    20,    11,
      22,    29,    24,   299,   299,   143,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    -1,    20,    -1,    22,
      -1,    24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    -1,    20,    -1,    22,    -1,    24,    -1,
      -1,    -1,    -1,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      17,    18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      -1,    -1,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    51,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    -1,    -1,    22,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    34,    35,    36,    37,    38,
      39,    12,    13,    14,    15,    -1,    -1,    18,    -1,    -1,
      -1,    22,    51,    24,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    34,    35,    36,    37,    38,    39,    12,
      13,    14,     6,     7,     8,    18,    10,    11,    -1,    22,
      51,    24,    -1,    -1,    -1,    -1,    20,    -1,    -1,    15,
      -1,    34,    35,    36,    37,    38,    39,    23,    24,    25,
      26,    15,    28,    -1,    -1,    -1,    -1,    -1,    51,    23,
      24,    25,    26,    -1,    28,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    48,    49,    50,    15,     6,     7,
       8,    -1,    10,    11,    -1,    23,    24,    25,    26,    15,
      28,    -1,    20,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    -1,    28,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    15,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      28,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    15,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    -1,    28,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    16,
      -1,    -1,    -1,    -1,    -1,    57,    23,    24,    25,    26,
      19,    28,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      19,    28,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      19,    28,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      19,    28,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,    19,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    28,    -1,    -1,    23,    24,    25,    26,    -1,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    43,    44,    45,    46,    47,    48,
      49,    50,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    20
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,     7,     8,     9,    10,    11,    20,    62,
      63,    64,    65,    67,    83,    95,     4,     4,     0,    65,
      67,    63,    83,    95,     4,    21,    14,    16,    67,    14,
      14,    10,    66,    95,     4,    84,    95,    15,    66,    15,
      44,    15,    59,     4,     4,     4,    17,    95,     4,    16,
      15,    16,    95,    16,    10,    95,    18,    57,     4,     4,
      57,     3,     4,     5,     9,    10,    12,    13,    14,    18,
      22,    24,    29,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    51,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    80,    81,    82,    83,    85,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,    16,    68,    43,    68,    44,     4,     4,    96,    57,
      57,    14,    18,    58,    60,     4,    44,    96,    86,    96,
      96,    96,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    96,    96,    17,    69,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,     4,    23,    24,    25,    26,
      28,    43,    44,    45,    46,    47,    48,    49,    50,    27,
      18,    57,    57,    68,    17,     4,    17,    95,    18,    14,
      60,    19,    15,    86,     4,   101,    96,     4,    52,    53,
      54,    55,    56,     4,    95,    15,    19,    59,    16,    96,
      87,    95,    86,     4,     4,     4,   101,   101,    96,    18,
      58,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    17,    43,    96,    15,    86,
       4,    18,    57,    15,    19,    58,    60,    14,    14,    14,
      14,    14,    58,    43,    96,    68,    15,    57,     4,    15,
      15,    15,    15,    15,    15,    15,   101,    96,    19,     4,
      19,    15,    96,    57,    58,    96,     4,    96,    96,    96,
      15,    96,    16,     4,    17,    16,    96,    19,    18,    18,
      19,   101,    15,    15,    15,    15,    86,    58,    30,    77,
      78,    79,    68,    57,    18,    58,    96,    96,    18,    17,
      96,    16,    29,    78,    79,    17,    96,   101,    18,    19,
      19,    96,    57,    68,    96,    15,    19,    86,    18,    19,
      17,    16,    16,    18,    58,    19,    96,    68,    68,   101,
      18,    19,    17,    17,    19,    86,    58,    19,    18,    86,
      19
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    61,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    66,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    71,    72,    73,    74,    75,    76,    76,    76,
      76,    77,    77,    78,    79,    80,    81,    82,    83,    84,
      84,    84,    84,    85,    86,    86,    87,    87,    88,    88,
      88,    89,    90,    91,    91,    92,    93,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    98,    99,   100,   101,   101,   101,
     101,   101,   101,   102,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   106,   106,   107,   107
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     2,     1,     2,     1,     8,
       7,     8,     4,     7,     7,    13,     2,     5,     5,    11,
       7,     2,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     1,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     4,     6,     6,     6,     5,     6,     7,     5,     6,
       6,     2,     1,     6,     4,     7,    11,     1,     5,     4,
       4,     3,     3,     8,     3,     1,     4,     2,     3,     6,
       5,     1,     1,     2,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     2,     1,     1,     1,
       1,     1,     1,     7,     4,     1,     3,     5,     7,     5,
       9,    12,    15,     4,     3,     5,     4
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
  "ATOF", "IOTA", "INCREMENT", "PRIMITIVE", "LIST_ARR", "STRUCT_ACCESS",
  "DECLARE_VECTOR", "DECLARE_MATRIX", "CALL_EXP", "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   209,   209,   215,   222,   232,   237,   244,   249,   256,
     260,   264,   270,   275,   280,   285,   290,   295,   300,   305,
     312,   318,   323,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,   350,   353,   356,   359,   362,   365,   368,   372,   376,
     380,   386,   391,   398,   404,   408,   411,   414,   417,   420,
     425,   430,   435,   442,   445,   450,   457,   458,   460,   461,
     462,   465,   468,   471,   472,   475,   478,   481,   484,   485,
     486,   487,   488,   489,   493,   494,   495,   496,   497,   499,
     501,   502,   503,   504,   505,   506,   508,   509,   510,   515,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   531,   532,   536,   539,   542,   546,   550,   562,   568,
     569,   570,   571,   574,   575,   576,   579,   584,   587,   588,
     591,   592,   593,   597,   598,   601,   602
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
#line 3410 "parser.cpp"

#line 605 "parser.y"


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

