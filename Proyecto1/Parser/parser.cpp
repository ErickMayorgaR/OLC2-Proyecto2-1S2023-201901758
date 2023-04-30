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
#line 93 "parser.y"
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
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_GET: // GET
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
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
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
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

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.YY_MOVE_OR_COPY< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_GET: // GET
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
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
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
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

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.move< map_struct_dec* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_GET: // GET
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
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
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
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

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.copy< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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

      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_GET: // GET
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
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
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
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

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        value.move< map_struct_dec* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 762 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 768 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 774 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 780 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 786 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 792 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 798 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 804 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 810 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 816 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 822 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 828 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 834 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 840 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 846 "parser.cpp"
        break;

      case symbol_kind::S_RTRUE: // RTRUE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 852 "parser.cpp"
        break;

      case symbol_kind::S_RFALSE: // RFALSE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 858 "parser.cpp"
        break;

      case symbol_kind::S_NLL: // NLL
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 864 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 870 "parser.cpp"
        break;

      case symbol_kind::S_RIOTA: // RIOTA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 876 "parser.cpp"
        break;

      case symbol_kind::S_RATOI: // RATOI
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 882 "parser.cpp"
        break;

      case symbol_kind::S_RATOF: // RATOF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 888 "parser.cpp"
        break;

      case symbol_kind::S_RMEAN: // RMEAN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 894 "parser.cpp"
        break;

      case symbol_kind::S_RMEDIAN: // RMEDIAN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 900 "parser.cpp"
        break;

      case symbol_kind::S_RMODE: // RMODE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 906 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 912 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 918 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 924 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 930 "parser.cpp"
        break;

      case symbol_kind::S_INC: // INC
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 936 "parser.cpp"
        break;

      case symbol_kind::S_MOD: // MOD
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 942 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 948 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 954 "parser.cpp"
        break;

      case symbol_kind::S_RWHILE: // RWHILE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 960 "parser.cpp"
        break;

      case symbol_kind::S_RFOR: // RFOR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 966 "parser.cpp"
        break;

      case symbol_kind::S_RBREAK: // RBREAK
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 972 "parser.cpp"
        break;

      case symbol_kind::S_RCONTINUE: // RCONTINUE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 978 "parser.cpp"
        break;

      case symbol_kind::S_RRETURN: // RRETURN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 984 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 990 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 996 "parser.cpp"
        break;

      case symbol_kind::S_NOT: // NOT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1002 "parser.cpp"
        break;

      case symbol_kind::S_MAY: // MAY
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1008 "parser.cpp"
        break;

      case symbol_kind::S_MEN: // MEN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1014 "parser.cpp"
        break;

      case symbol_kind::S_MAY_IG: // MAY_IG
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1020 "parser.cpp"
        break;

      case symbol_kind::S_MEN_IG: // MEN_IG
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1026 "parser.cpp"
        break;

      case symbol_kind::S_DIF: // DIF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1032 "parser.cpp"
        break;

      case symbol_kind::S_IG: // IG
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1038 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1044 "parser.cpp"
        break;

      case symbol_kind::S_RVECTOR: // RVECTOR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1050 "parser.cpp"
        break;

      case symbol_kind::S_VPBACK: // VPBACK
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1056 "parser.cpp"
        break;

      case symbol_kind::S_VGET: // VGET
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1062 "parser.cpp"
        break;

      case symbol_kind::S_VREMOVE: // VREMOVE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1068 "parser.cpp"
        break;

      case symbol_kind::S_VSIZE: // VSIZE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1074 "parser.cpp"
        break;

      case symbol_kind::S_VPFRONT: // VPFRONT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 1080 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1086 "parser.cpp"
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1092 "parser.cpp"
        break;

      case symbol_kind::S_FUNCTION: // FUNCTION
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1098 "parser.cpp"
        break;

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1104 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 1110 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1116 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1122 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1128 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1134 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1140 "parser.cpp"
        break;

      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1146 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1152 "parser.cpp"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1158 "parser.cpp"
        break;

      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1164 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1170 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1176 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1182 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1188 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1194 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1200 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1206 "parser.cpp"
        break;

      case symbol_kind::S_DEC_LIST: // DEC_LIST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1212 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1218 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1224 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1230 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1236 "parser.cpp"
        break;

      case symbol_kind::S_IOTA: // IOTA
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1242 "parser.cpp"
        break;

      case symbol_kind::S_ATOI: // ATOI
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1248 "parser.cpp"
        break;

      case symbol_kind::S_ATOF: // ATOF
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1254 "parser.cpp"
        break;

      case symbol_kind::S_MEAN: // MEAN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1260 "parser.cpp"
        break;

      case symbol_kind::S_MEDIAN: // MEDIAN
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1266 "parser.cpp"
        break;

      case symbol_kind::S_MODE: // MODE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1272 "parser.cpp"
        break;

      case symbol_kind::S_SIZE: // SIZE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1278 "parser.cpp"
        break;

      case symbol_kind::S_GET: // GET
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1284 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1290 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1296 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1302 "parser.cpp"
        break;

      case symbol_kind::S_CALL_EXP: // CALL_EXP
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1308 "parser.cpp"
        break;

      case symbol_kind::S_CALL_INST: // CALL_INST
#line 185 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1314 "parser.cpp"
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
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_MEAN: // MEAN
      case symbol_kind::S_MEDIAN: // MEDIAN
      case symbol_kind::S_MODE: // MODE
      case symbol_kind::S_SIZE: // SIZE
      case symbol_kind::S_GET: // GET
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_BOOL: // BOOL
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
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_DECLARATION: // DECLARATION
      case symbol_kind::S_ASSIGNMENT: // ASSIGNMENT
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_INST_VECTOR: // INST_VECTOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_STRUCT_DECLARATION: // STRUCT_DECLARATION
      case symbol_kind::S_STRUCT_CREATION: // STRUCT_CREATION
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

      case symbol_kind::S_FUNC_LIST: // FUNC_LIST
      case symbol_kind::S_DEC_LIST: // DEC_LIST
        yylhs.value.emplace< map_struct_dec* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_RMAIN: // RMAIN
      case symbol_kind::S_PARA: // PARA
      case symbol_kind::S_PARC: // PARC
      case symbol_kind::S_LLAVA: // LLAVA
      case symbol_kind::S_LLAVC: // LLAVC
      case symbol_kind::S_CORA: // CORA
      case symbol_kind::S_CORC: // CORC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_TSTRING: // TSTRING
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_RTRUE: // RTRUE
      case symbol_kind::S_RFALSE: // RFALSE
      case symbol_kind::S_NLL: // NLL
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_RIOTA: // RIOTA
      case symbol_kind::S_RATOI: // RATOI
      case symbol_kind::S_RATOF: // RATOF
      case symbol_kind::S_RMEAN: // RMEAN
      case symbol_kind::S_RMEDIAN: // RMEDIAN
      case symbol_kind::S_RMODE: // RMODE
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
      case symbol_kind::S_RBREAK: // RBREAK
      case symbol_kind::S_RCONTINUE: // RCONTINUE
      case symbol_kind::S_RRETURN: // RRETURN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_MAY: // MAY
      case symbol_kind::S_MEN: // MEN
      case symbol_kind::S_MAY_IG: // MAY_IG
      case symbol_kind::S_MEN_IG: // MEN_IG
      case symbol_kind::S_DIF: // DIF
      case symbol_kind::S_IG: // IG
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_RVECTOR: // RVECTOR
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
#line 193 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = nullptr;
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1689 "parser.cpp"
    break;

  case 3: // START: LIST_FUNC MAIN
#line 200 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Functions = yystack_[1].value.as < list_instruction* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1700 "parser.cpp"
    break;

  case 4: // LIST_FUNC: LIST_FUNC FUNCTION
#line 209 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1709 "parser.cpp"
    break;

  case 5: // LIST_FUNC: FUNCTION
#line 214 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1718 "parser.cpp"
    break;

  case 6: // FUNCTION: TYPES ID PARA FUNC_LIST PARC LLAVA LIST_INST LLAVC
#line 221 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(yystack_[7].location.begin.line, yystack_[7].location.begin.column,yystack_[7].value.as < TipoDato > (),yystack_[6].value.as < std::string > (),yystack_[4].value.as < map_struct_dec* > (),yystack_[1].value.as < list_instruction* > ());
        }
#line 1726 "parser.cpp"
    break;

  case 7: // FUNCTION: TYPES ID PARA PARC LLAVA LIST_INST LLAVC
#line 225 "parser.y"
        {
            yylhs.value.as < instruction* > () = new function(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[6].value.as < TipoDato > (),yystack_[5].value.as < std::string > (),nullptr,yystack_[1].value.as < list_instruction* > ());
        }
#line 1734 "parser.cpp"
    break;

  case 8: // FUNC_LIST: FUNC_LIST ',' TYPES ID
#line 231 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (),yystack_[1].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1743 "parser.cpp"
    break;

  case 9: // FUNC_LIST: TYPES ID
#line 236 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[0].value.as < std::string > (), yystack_[1].value.as < TipoDato > ());
        }
#line 1752 "parser.cpp"
    break;

  case 10: // MAIN: VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 243 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(yystack_[6].location.begin.line, yystack_[6].location.begin.column, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1760 "parser.cpp"
    break;

  case 11: // LIST_INST: LIST_INST INSTRUCTION
#line 249 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1769 "parser.cpp"
    break;

  case 12: // LIST_INST: INSTRUCTION
#line 254 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1778 "parser.cpp"
    break;

  case 13: // INSTRUCTION: PRINT ';'
#line 260 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1784 "parser.cpp"
    break;

  case 14: // INSTRUCTION: DECLARATION ';'
#line 261 "parser.y"
                      { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1790 "parser.cpp"
    break;

  case 15: // INSTRUCTION: ASSIGNMENT ';'
#line 262 "parser.y"
                     { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1796 "parser.cpp"
    break;

  case 16: // INSTRUCTION: IF
#line 263 "parser.y"
         { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1802 "parser.cpp"
    break;

  case 17: // INSTRUCTION: WHILE
#line 264 "parser.y"
            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1808 "parser.cpp"
    break;

  case 18: // INSTRUCTION: STRUCT_DECLARATION
#line 265 "parser.y"
                         { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1814 "parser.cpp"
    break;

  case 19: // INSTRUCTION: STRUCT_CREATION
#line 266 "parser.y"
                      { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1820 "parser.cpp"
    break;

  case 20: // INSTRUCTION: CALL_INST
#line 267 "parser.y"
                { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1826 "parser.cpp"
    break;

  case 21: // INSTRUCTION: BREAK ';'
#line 268 "parser.y"
                {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1832 "parser.cpp"
    break;

  case 22: // INSTRUCTION: CONTINUE ';'
#line 269 "parser.y"
                   {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1838 "parser.cpp"
    break;

  case 23: // INSTRUCTION: RETURN ';'
#line 270 "parser.y"
                 { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1844 "parser.cpp"
    break;

  case 24: // INSTRUCTION: INST_VECTOR ';'
#line 271 "parser.y"
                      {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1850 "parser.cpp"
    break;

  case 25: // INSTRUCTION: FOR
#line 272 "parser.y"
          { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1856 "parser.cpp"
    break;

  case 26: // RETURN: RRETURN EXP
#line 275 "parser.y"
                     { yylhs.value.as < instruction* > () = new inst_return(yystack_[1].location.begin.line, yystack_[1].location.begin.column,yystack_[0].value.as < expression* > ()); }
#line 1862 "parser.cpp"
    break;

  case 27: // RETURN: RRETURN
#line 276 "parser.y"
              { yylhs.value.as < instruction* > () = new inst_return(yystack_[0].location.begin.line, yystack_[0].location.begin.column,nullptr); }
#line 1868 "parser.cpp"
    break;

  case 28: // PRINT: PRINTF PARA EXP_LIST PARC
#line 279 "parser.y"
                                  { yylhs.value.as < instruction* > () = new print(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 1874 "parser.cpp"
    break;

  case 29: // DECLARATION: TYPES ID '=' EXP
#line 282 "parser.y"
                               { yylhs.value.as < instruction* > () = new declaration(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ()); }
#line 1880 "parser.cpp"
    break;

  case 30: // DECLARATION: RVECTOR MEN TYPES MAY ID '=' EXP
#line 283 "parser.y"
                                                {yylhs.value.as < instruction* > () = new declare_vector(yystack_[6].location.begin.line, yystack_[6].location.begin.column, yystack_[4].value.as < TipoDato > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > ());}
#line 1886 "parser.cpp"
    break;

  case 31: // ASSIGNMENT: ID '=' EXP
#line 286 "parser.y"
                        { yylhs.value.as < instruction* > () = new assignment(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < std::string > (), yystack_[0].value.as < expression* > ()); }
#line 1892 "parser.cpp"
    break;

  case 32: // ASSIGNMENT: ID CORA PRIMITIVE CORC '=' PRIMITIVE
#line 287 "parser.y"
                                                   {yylhs.value.as < instruction* > () = new assign_vector(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[3].value.as < expression* > (),yystack_[0].value.as < expression* > ());}
#line 1898 "parser.cpp"
    break;

  case 33: // BREAK: RBREAK
#line 290 "parser.y"
               {yylhs.value.as < instruction* > () = new func_break(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 1904 "parser.cpp"
    break;

  case 34: // CONTINUE: RCONTINUE
#line 293 "parser.y"
                     {yylhs.value.as < instruction* > () = new func_continue(yystack_[0].location.begin.line, yystack_[0].location.begin.column);}
#line 1910 "parser.cpp"
    break;

  case 35: // INST_VECTOR: ID '.' VPBACK PARA EXP PARC
#line 296 "parser.y"
                                          {yylhs.value.as < instruction* > () = new func_pushback(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 1916 "parser.cpp"
    break;

  case 36: // INST_VECTOR: ID '.' VPFRONT PARA EXP PARC
#line 297 "parser.y"
                                           {yylhs.value.as < instruction* > () = new func_pushfront(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 1922 "parser.cpp"
    break;

  case 37: // INST_VECTOR: ID '.' VREMOVE PARA EXP PARC
#line 298 "parser.y"
                                           {yylhs.value.as < instruction* > () = new func_remove(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 1928 "parser.cpp"
    break;

  case 38: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 302 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1936 "parser.cpp"
    break;

  case 39: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 306 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(yystack_[5].location.begin.line, yystack_[5].location.begin.column,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1944 "parser.cpp"
    break;

  case 40: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 312 "parser.y"
        {
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1953 "parser.cpp"
    break;

  case 41: // ELSEIF_LIST: ELSEIF
#line 317 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1962 "parser.cpp"
    break;

  case 42: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 324 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1970 "parser.cpp"
    break;

  case 43: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 329 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1976 "parser.cpp"
    break;

  case 44: // ELSE: %empty
#line 330 "parser.y"
             { }
#line 1982 "parser.cpp"
    break;

  case 45: // WHILE: RWHILE EXP LLAVA LIST_INST LLAVC
#line 333 "parser.y"
                                         { yylhs.value.as < instruction* > () = new func_while(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[3].value.as < expression* > (), yystack_[1].value.as < list_instruction* > ()); }
#line 1988 "parser.cpp"
    break;

  case 46: // FOR: RFOR PARA DECLARATION ';' EXP ';' EXP PARC LLAVA LIST_INST LLAVC
#line 336 "parser.y"
                                                                       {yylhs.value.as < instruction* > () = new func_for(yystack_[10].location.begin.line, yystack_[10].location.begin.column,yystack_[8].value.as < instruction* > (),yystack_[6].value.as < expression* > (),yystack_[4].value.as < expression* > (),yystack_[1].value.as < list_instruction* > ());}
#line 1994 "parser.cpp"
    break;

  case 47: // STRUCT_DECLARATION: STRUCT ID LLAVA DEC_LIST LLAVC
#line 339 "parser.y"
                                                    {yylhs.value.as < instruction* > () = new dec_struct(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 2000 "parser.cpp"
    break;

  case 48: // DEC_LIST: DEC_LIST TYPES ID ';'
#line 343 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 2009 "parser.cpp"
    break;

  case 49: // DEC_LIST: TYPES ID ';'
#line 348 "parser.y"
        {
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 2018 "parser.cpp"
    break;

  case 50: // STRUCT_CREATION: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 355 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(yystack_[6].location.begin.line, yystack_[6].location.begin.column,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 2026 "parser.cpp"
    break;

  case 51: // EXP_LIST: EXP_LIST ',' EXP
#line 361 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 2035 "parser.cpp"
    break;

  case 52: // EXP_LIST: EXP
#line 366 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 2044 "parser.cpp"
    break;

  case 53: // TYPES: INT
#line 372 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 2050 "parser.cpp"
    break;

  case 54: // TYPES: TSTRING
#line 373 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 2056 "parser.cpp"
    break;

  case 55: // TYPES: BOOLEAN
#line 374 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 2062 "parser.cpp"
    break;

  case 56: // TYPES: FLOAT
#line 375 "parser.y"
            {yylhs.value.as < TipoDato > () = FLOAT;}
#line 2068 "parser.cpp"
    break;

  case 57: // TYPES: VOID
#line 376 "parser.y"
           { yylhs.value.as < TipoDato > () = NULO; }
#line 2074 "parser.cpp"
    break;

  case 58: // TYPES: RVECTOR
#line 377 "parser.y"
              { yylhs.value.as < TipoDato > () = VECTOR; }
#line 2080 "parser.cpp"
    break;

  case 59: // EXP: EXP SUMA EXP
#line 380 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 2086 "parser.cpp"
    break;

  case 60: // EXP: EXP MENOS EXP
#line 381 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 2092 "parser.cpp"
    break;

  case 61: // EXP: EXP POR EXP
#line 382 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 2098 "parser.cpp"
    break;

  case 62: // EXP: EXP DIV EXP
#line 383 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 2104 "parser.cpp"
    break;

  case 63: // EXP: EXP MEN EXP
#line 384 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<"); }
#line 2110 "parser.cpp"
    break;

  case 64: // EXP: EXP MAY EXP
#line 385 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">"); }
#line 2116 "parser.cpp"
    break;

  case 65: // EXP: EXP MEN_IG EXP
#line 386 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<="); }
#line 2122 "parser.cpp"
    break;

  case 66: // EXP: EXP MAY_IG EXP
#line 387 "parser.y"
                     { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">="); }
#line 2128 "parser.cpp"
    break;

  case 67: // EXP: EXP DIF EXP
#line 388 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!="); }
#line 2134 "parser.cpp"
    break;

  case 68: // EXP: EXP IG EXP
#line 389 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "=="); }
#line 2140 "parser.cpp"
    break;

  case 69: // EXP: EXP AND EXP
#line 390 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&"); }
#line 2146 "parser.cpp"
    break;

  case 70: // EXP: EXP OR EXP
#line 391 "parser.y"
                 { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||"); }
#line 2152 "parser.cpp"
    break;

  case 71: // EXP: NOT EXP
#line 392 "parser.y"
              {    yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, yystack_[0].value.as < expression* > (), new primitive(0,0,BOOL, "", 0,0.0,false), "!");}
#line 2158 "parser.cpp"
    break;

  case 72: // EXP: EXP MOD EXP
#line 393 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(yystack_[2].location.begin.line, yystack_[2].location.begin.column, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 2164 "parser.cpp"
    break;

  case 73: // EXP: EXP INC
#line 394 "parser.y"
              { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, yystack_[1].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++"); }
#line 2170 "parser.cpp"
    break;

  case 74: // EXP: IOTA
#line 395 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2176 "parser.cpp"
    break;

  case 75: // EXP: ATOI
#line 396 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2182 "parser.cpp"
    break;

  case 76: // EXP: ATOF
#line 397 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2188 "parser.cpp"
    break;

  case 77: // EXP: MEAN
#line 398 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2194 "parser.cpp"
    break;

  case 78: // EXP: MEDIAN
#line 399 "parser.y"
             {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2200 "parser.cpp"
    break;

  case 79: // EXP: MODE
#line 400 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2206 "parser.cpp"
    break;

  case 80: // EXP: SIZE
#line 401 "parser.y"
           {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2212 "parser.cpp"
    break;

  case 81: // EXP: GET
#line 402 "parser.y"
          {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 2218 "parser.cpp"
    break;

  case 82: // EXP: PARA EXP PARC
#line 403 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 2224 "parser.cpp"
    break;

  case 83: // EXP: CORA EXP_LIST CORC
#line 404 "parser.y"
                         { yylhs.value.as < expression* > () = new vector_exp(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[1].value.as < list_expression* > ()); }
#line 2230 "parser.cpp"
    break;

  case 84: // EXP: MENOS EXP
#line 405 "parser.y"
                { yylhs.value.as < expression* > () = new operation(yystack_[1].location.begin.line, yystack_[1].location.begin.column, new primitive(yystack_[1].location.begin.line, yystack_[1].location.begin.column,INTEGER, "", 0,0.0,false), yystack_[0].value.as < expression* > (), "-"); }
#line 2236 "parser.cpp"
    break;

  case 85: // EXP: PRIMITIVE
#line 406 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2242 "parser.cpp"
    break;

  case 86: // EXP: CALL_EXP
#line 407 "parser.y"
               { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2248 "parser.cpp"
    break;

  case 87: // IOTA: RIOTA PARA EXP PARC
#line 410 "parser.y"
                           {yylhs.value.as < expression* > () = new func_iota(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2254 "parser.cpp"
    break;

  case 88: // ATOI: RATOI PARA PRIMITIVE PARC
#line 413 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atoi(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2260 "parser.cpp"
    break;

  case 89: // ATOF: RATOF PARA PRIMITIVE PARC
#line 416 "parser.y"
                                 {yylhs.value.as < expression* > () = new func_atof(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < expression* > ());}
#line 2266 "parser.cpp"
    break;

  case 90: // MEAN: RMEAN PARA ID PARC
#line 419 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mean(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2272 "parser.cpp"
    break;

  case 91: // MEDIAN: RMEDIAN PARA ID PARC
#line 422 "parser.y"
                              {yylhs.value.as < expression* > () = new func_median(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2278 "parser.cpp"
    break;

  case 92: // MODE: RMODE PARA ID PARC
#line 425 "parser.y"
                          {yylhs.value.as < expression* > () = new func_mode(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[1].value.as < std::string > ());}
#line 2284 "parser.cpp"
    break;

  case 93: // SIZE: ID '.' VSIZE PARA PARC
#line 428 "parser.y"
                              {yylhs.value.as < expression* > () = new func_size(yystack_[4].location.begin.line, yystack_[4].location.begin.column, yystack_[4].value.as < std::string > ());}
#line 2290 "parser.cpp"
    break;

  case 94: // GET: ID '.' VGET PARA EXP PARC
#line 431 "parser.y"
                                {yylhs.value.as < expression* > () = new func_get(yystack_[5].location.begin.line, yystack_[5].location.begin.column, yystack_[5].value.as < std::string > (),yystack_[1].value.as < expression* > ());}
#line 2296 "parser.cpp"
    break;

  case 95: // PRIMITIVE: NUMERO
#line 434 "parser.y"
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
#line 2313 "parser.cpp"
    break;

  case 96: // PRIMITIVE: STRING
#line 447 "parser.y"
            {
                std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
                std::string str2 = str1.erase(str1.length()-1,1);
                yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,STRING,str2,0,0.0,false);
            }
#line 2323 "parser.cpp"
    break;

  case 97: // PRIMITIVE: NLL
#line 452 "parser.y"
                  {yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,NULO,"",0,0.0,false);}
#line 2329 "parser.cpp"
    break;

  case 98: // PRIMITIVE: BOOL
#line 453 "parser.y"
                   { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2335 "parser.cpp"
    break;

  case 99: // PRIMITIVE: LIST_ARR
#line 454 "parser.y"
                       { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 2341 "parser.cpp"
    break;

  case 100: // BOOL: RTRUE
#line 457 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL,"",0,0.0,true); }
#line 2347 "parser.cpp"
    break;

  case 101: // BOOL: RFALSE
#line 458 "parser.y"
             { yylhs.value.as < expression* > () = new primitive(yystack_[0].location.begin.line, yystack_[0].location.begin.column,BOOL,"",0,0.0,false); }
#line 2353 "parser.cpp"
    break;

  case 102: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 461 "parser.y"
                                  { yylhs.value.as < expression* > () = new vector_access(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 2359 "parser.cpp"
    break;

  case 103: // LIST_ARR: LIST_ARR '.' ID
#line 462 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 2365 "parser.cpp"
    break;

  case 104: // LIST_ARR: ID
#line 463 "parser.y"
             {yylhs.value.as < expression* > () = new access(yystack_[0].location.begin.line, yystack_[0].location.begin.column,yystack_[0].value.as < std::string > ()); }
#line 2371 "parser.cpp"
    break;

  case 105: // CALL_EXP: ID PARA EXP_LIST PARC
#line 466 "parser.y"
                                 { yylhs.value.as < expression* > () = new call_exp(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),yystack_[1].value.as < list_expression* > ()); }
#line 2377 "parser.cpp"
    break;

  case 106: // CALL_EXP: ID PARA PARC
#line 467 "parser.y"
                       { yylhs.value.as < expression* > () = new call_exp(yystack_[2].location.begin.line, yystack_[2].location.begin.column,yystack_[2].value.as < std::string > (),nullptr); }
#line 2383 "parser.cpp"
    break;

  case 107: // CALL_INST: ID PARA EXP_LIST PARC ';'
#line 470 "parser.y"
                                      { yylhs.value.as < instruction* > () = new call_inst(yystack_[4].location.begin.line, yystack_[4].location.begin.column,yystack_[4].value.as < std::string > (),yystack_[2].value.as < list_expression* > ());}
#line 2389 "parser.cpp"
    break;

  case 108: // CALL_INST: ID PARA PARC ';'
#line 471 "parser.y"
                           { yylhs.value.as < instruction* > () = new call_inst(yystack_[3].location.begin.line, yystack_[3].location.begin.column,yystack_[3].value.as < std::string > (),nullptr); }
#line 2395 "parser.cpp"
    break;


#line 2399 "parser.cpp"

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





  const signed char Parser::yypact_ninf_ = -61;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     105,    22,   -61,   -61,   -61,   -61,   -61,    15,   105,   -61,
     -61,    42,    23,   -61,   -61,   -61,    45,    46,    26,    50,
      57,   -61,    -5,    64,   398,   398,    62,   115,   -61,    -1,
      65,   658,   658,    66,   -61,   -61,   658,    77,    29,    76,
     -61,    25,    27,    30,    31,    37,    38,    39,   -61,   -61,
     -61,   -61,   -61,    79,   -61,   161,   398,   101,   604,   186,
     658,   -27,   658,   -61,    -3,   -61,   658,   658,   -61,   -61,
     -61,    99,   102,   104,   110,   116,   126,   658,   658,   661,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,
      -6,   -61,   686,   170,   777,    14,   115,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -61,    91,   -61,   215,   -61,
      51,     3,   777,   -61,   138,   777,   145,   146,   150,     4,
     631,   -17,   414,     2,   658,   186,   186,   160,   163,   164,
      -9,   799,   398,   658,   658,   658,   658,   -61,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   165,   398,
     113,   114,   115,   129,   658,   -61,   -61,   122,   658,   123,
     658,   658,   658,   -61,   -61,     5,   173,   181,   -61,   -61,
     442,   184,   185,   188,   194,   200,   246,    -9,    -9,   -61,
     -61,   -61,   799,   799,    70,    70,    70,    70,   805,   805,
     733,   -61,   277,   658,   201,    34,   209,   213,   777,   -61,
     777,   186,   468,   494,   520,   -61,   658,   210,   -61,   -61,
     -61,   -61,   -61,   -61,   187,   -61,   -61,   755,   658,   -61,
     216,   166,   175,   -61,   -61,   -61,   -61,   546,   -61,    11,
     187,   -61,   -61,   658,     9,   167,   -61,   658,   -61,   398,
     658,   -61,   -61,   572,   -61,   -61,   777,   308,   711,   226,
     -61,   398,   398,   339,   370,   -61,   -61
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    57,    53,    54,    56,    55,    58,     0,     0,     5,
       2,     0,     0,     1,     4,     3,     0,     0,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     9,     0,
       0,     0,     0,     0,    33,    34,    27,     0,    58,     0,
      12,     0,     0,     0,     0,     0,     0,     0,    16,    17,
      25,    18,    19,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,    95,   104,    96,     0,     0,   100,   101,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    85,    98,
      99,    86,     0,     0,    26,     0,     0,    10,    11,    23,
      13,    14,    15,    21,    22,    24,     0,     7,     0,     8,
       0,     0,    52,   104,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    71,     0,     0,     0,     0,     0,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,   108,     0,     0,     0,
       0,     0,     0,    28,   106,     0,     0,     0,    82,    83,
       0,     0,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    72,    69,    70,    64,    63,    66,    65,    67,    68,
       0,   103,     0,     0,     0,     0,     0,     0,    29,   107,
      51,     0,     0,     0,     0,   105,     0,     0,    87,    88,
      89,    90,    91,    92,    44,   102,    45,     0,     0,    47,
       0,     0,     0,    32,    35,    37,    36,     0,    93,     0,
      44,    41,    39,     0,     0,     0,    49,     0,    94,     0,
       0,    40,    38,     0,    50,    48,    30,     0,     0,     0,
      43,     0,     0,     0,     0,    42,    46
  };

  const short
  Parser::yypgoto_[] =
  {
     -61,   -61,   -61,   229,   -61,   231,   -25,   -38,   -61,   -61,
     147,   -61,   -61,   -61,   -61,   -61,   -61,    12,    13,   -61,
     -61,   -61,   -61,   -61,   -60,     8,     1,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,   -50,   -61,   -61,   -61,   -61
  };

  const short
  Parser::yydefgoto_[] =
  {
      -1,     7,     8,     9,    22,    10,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   230,   231,   232,    49,
      50,    51,   195,    52,   111,    53,   112,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    54
  };

  const short
  Parser::yytable_[] =
  {
      55,    98,   119,    26,   120,   147,    58,   123,    11,   114,
      59,   157,   163,   205,   169,    13,    11,    98,   151,   244,
     239,   135,   136,   152,   138,   116,    23,   117,    12,   118,
      17,   108,    79,    92,    20,    57,   166,    94,   167,    21,
       2,     3,     4,     5,   219,   240,    16,    21,     2,     3,
       4,     5,    18,   148,    19,    27,   121,    60,    61,    24,
     165,   115,   158,   158,   158,   158,    25,   122,    28,   158,
      98,    56,    62,    93,    96,   171,   172,     6,   130,   131,
      29,    95,    99,   106,   100,     6,    97,   101,   102,    21,
       2,     3,     4,     5,   103,   104,   105,    30,   133,   134,
     135,   136,   137,   138,   153,   109,   124,   176,   156,   125,
      31,   126,    32,    33,    34,    35,    36,   127,     1,     2,
       3,     4,     5,   128,   192,   170,    37,    38,    21,     2,
       3,     4,     5,   129,   177,   178,   179,   180,    98,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   154,
     159,   223,   160,   161,    98,   198,     6,   162,   234,   200,
     196,   202,   203,   204,   173,    29,     6,   174,   175,   191,
     193,   107,   194,   197,    21,     2,     3,     4,     5,   199,
     206,   201,    30,    21,     2,     3,     4,     5,   207,    63,
     113,    65,   209,   210,   217,    31,   211,    32,    33,    34,
      35,    36,   212,   220,    68,    69,    70,   227,   213,    98,
     218,    37,    38,   221,   247,    98,    98,   222,   228,    29,
     235,    38,   229,   236,   245,   155,   253,   254,    21,     2,
       3,     4,     5,   237,   243,   252,    30,    14,   246,    15,
     150,   248,   241,   242,     0,     0,     0,     0,     0,    31,
      29,    32,    33,    34,    35,    36,   214,     0,     0,    21,
       2,     3,     4,     5,     0,    37,    38,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    29,    32,    33,    34,    35,    36,   216,     0,     0,
      21,     2,     3,     4,     5,     0,    37,    38,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    29,    32,    33,    34,    35,    36,   250,     0,
       0,    21,     2,     3,     4,     5,     0,    37,    38,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    29,    32,    33,    34,    35,    36,   255,
       0,     0,    21,     2,     3,     4,     5,     0,    37,    38,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    29,    32,    33,    34,    35,    36,
     256,     0,     0,    21,     2,     3,     4,     5,     0,    37,
      38,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,    31,     0,    32,    33,    34,    35,
      36,    21,     2,     3,     4,     5,     0,     0,     0,    30,
      37,    38,   168,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    32,    33,    34,    35,    36,     0,
       0,     0,   133,   134,   135,   136,   137,   138,    37,    38,
     208,     0,     0,     0,     0,   139,   140,     0,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,   224,     0,     0,     0,
       0,     0,     0,   139,   140,     0,   141,   142,   143,   144,
     145,   146,     0,     0,     0,     0,   133,   134,   135,   136,
     137,   138,   225,     0,     0,     0,     0,     0,     0,   139,
     140,     0,   141,   142,   143,   144,   145,   146,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   226,     0,
       0,     0,     0,     0,     0,   139,   140,     0,   141,   142,
     143,   144,   145,   146,     0,     0,     0,     0,   133,   134,
     135,   136,   137,   138,   238,     0,     0,     0,     0,     0,
       0,   139,   140,     0,   141,   142,   143,   144,   145,   146,
       0,     0,     0,     0,   133,   134,   135,   136,   137,   138,
     249,     0,     0,     0,     0,     0,     0,   139,   140,     0,
     141,   142,   143,   144,   145,   146,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,     0,    63,    64,    65,
       0,    66,   110,   139,   140,    67,   141,   142,   143,   144,
     145,   146,    68,    69,    70,     0,    71,    72,    73,    74,
      75,    76,     0,    77,    63,    64,    65,     0,    66,   164,
       0,     0,    67,     0,     0,     0,     0,    78,     0,    68,
      69,    70,     0,    71,    72,    73,    74,    75,    76,     0,
      77,    63,    64,    65,     0,    66,     0,     0,     0,    67,
     132,     0,     0,     0,    78,     0,    68,    69,    70,     0,
      71,    72,    73,    74,    75,    76,     0,    77,     0,   133,
     134,   135,   136,   137,   138,   149,     0,     0,     0,     0,
       0,    78,   139,   140,     0,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   133,   134,   135,   136,   137,   138,
     251,     0,     0,     0,     0,     0,     0,   139,   140,     0,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   133,
     134,   135,   136,   137,   138,   215,     0,     0,     0,     0,
       0,     0,   139,   140,     0,   141,   142,   143,   144,   145,
     146,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,   139,   140,     0,   141,   142,   143,
     144,   145,   146,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,     0,     0,     0,   139,   140,     0,   141,
     142,   143,   144,   145,   146,   133,   134,   135,   136,   137,
     138,     0,   233,     0,     0,     0,     0,     0,   139,   140,
       0,   141,   142,   143,   144,   145,   146,   133,   134,   135,
     136,   137,   138,   133,   134,   135,   136,   137,   138,     0,
       0,     0,     0,   141,   142,   143,   144,   145,   146,   141,
     142,   143,   144
  };

  const short
  Parser::yycheck_[] =
  {
      25,    39,    62,     8,     7,    11,     7,    67,     0,    59,
      11,     8,     8,     8,    12,     0,     8,    55,     4,    10,
       9,    30,    31,     9,    33,    52,    18,    54,     6,    56,
       7,    56,    31,    32,     8,    27,    53,    36,    55,    13,
      14,    15,    16,    17,    10,    34,     4,    13,    14,    15,
      16,    17,     7,    59,     8,    60,    59,    58,    59,     9,
     120,    60,    60,    60,    60,    60,     9,    66,     4,    60,
     108,     9,     7,     7,    45,   125,   126,    51,    77,    78,
       4,     4,    57,     4,    57,    51,    10,    57,    57,    13,
      14,    15,    16,    17,    57,    57,    57,    21,    28,    29,
      30,    31,    32,    33,    96,     4,     7,   132,    57,     7,
      34,     7,    36,    37,    38,    39,    40,     7,    13,    14,
      15,    16,    17,     7,   149,   124,    50,    51,    13,    14,
      15,    16,    17,     7,   133,   134,   135,   136,   176,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,    58,
      12,   201,     7,     7,   192,   154,    51,     7,   218,   158,
     152,   160,   161,   162,     4,     4,    51,     4,     4,     4,
      57,    10,    58,    44,    13,    14,    15,    16,    17,    57,
       7,    58,    21,    13,    14,    15,    16,    17,     7,     3,
       4,     5,     8,     8,   193,    34,     8,    36,    37,    38,
      39,    40,     8,   195,    18,    19,    20,   206,     8,   247,
       9,    50,    51,     4,   239,   253,   254,     4,     8,     4,
       4,    51,    35,    57,    57,    10,   251,   252,    13,    14,
      15,    16,    17,    58,   233,     9,    21,     8,   237,     8,
      93,   240,   230,   230,    -1,    -1,    -1,    -1,    -1,    34,
       4,    36,    37,    38,    39,    40,    10,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    50,    51,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,     4,    36,    37,    38,    39,    40,    10,    -1,    -1,
      13,    14,    15,    16,    17,    -1,    50,    51,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,     4,    36,    37,    38,    39,    40,    10,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    50,    51,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,     4,    36,    37,    38,    39,    40,    10,
      -1,    -1,    13,    14,    15,    16,    17,    -1,    50,    51,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,     4,    36,    37,    38,    39,    40,
      10,    -1,    -1,    13,    14,    15,    16,    17,    -1,    50,
      51,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    34,    -1,    36,    37,    38,    39,
      40,    13,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      50,    51,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    50,    51,
       8,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,     8,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    -1,     3,     4,     5,
      -1,     7,     8,    41,    42,    11,    44,    45,    46,    47,
      48,    49,    18,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    -1,    29,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    43,    -1,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    -1,
      29,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
       9,    -1,    -1,    -1,    43,    -1,    18,    19,    20,    -1,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    28,
      29,    30,    31,    32,    33,     9,    -1,    -1,    -1,    -1,
      -1,    43,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    28,    29,    30,    31,    32,
      33,    -1,    57,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    28,    29,    30,
      31,    32,    33,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    44,
      45,    46,    47
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    13,    14,    15,    16,    17,    51,    62,    63,    64,
      66,    86,     6,     0,    64,    66,     4,     7,     7,     8,
       8,    13,    65,    86,     9,     9,     8,    60,     4,     4,
      21,    34,    36,    37,    38,    39,    40,    50,    51,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    80,
      81,    82,    84,    86,   100,    67,     9,    86,     7,    11,
      58,    59,     7,     3,     4,     5,     7,    11,    18,    19,
      20,    22,    23,    24,    25,    26,    27,    29,    43,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    87,     7,    87,     4,    45,    10,    68,    57,
      57,    57,    57,    57,    57,    57,     4,    10,    67,     4,
       8,    85,    87,     4,    96,    87,    52,    54,    56,    85,
       7,    59,    87,    85,     7,     7,     7,     7,     7,     7,
      87,    87,     9,    28,    29,    30,    31,    32,    33,    41,
      42,    44,    45,    46,    47,    48,    49,    11,    59,     9,
      71,     4,     9,    86,    58,    10,    57,     8,    60,    12,
       7,     7,     7,     8,     8,    85,    53,    55,     8,    12,
      87,    96,    96,     4,     4,     4,    67,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,     4,    67,    57,    58,    83,    86,    44,    87,    57,
      87,    58,    87,    87,    87,     8,     7,     7,     8,     8,
       8,     8,     8,     8,    10,    12,    10,    87,     9,    10,
      86,     4,     4,    96,     8,     8,     8,    87,     8,    35,
      77,    78,    79,    57,    85,     4,    57,    58,     8,     9,
      34,    78,    79,    87,    10,    57,    87,    67,    87,     8,
      10,     9,     9,    67,    67,    10,    10
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    71,
      71,    72,    72,    73,    74,    75,    75,    75,    76,    76,
      77,    77,    78,    79,    79,    80,    81,    82,    83,    83,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    98,    99,    99,   100,   100
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     2,     1,     8,     7,     4,     2,
       7,     2,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     1,     4,     4,
       7,     3,     6,     1,     1,     6,     6,     6,     7,     6,
       2,     1,     6,     4,     0,     5,    11,     5,     4,     3,
       7,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     1,     1,     4,     4,     4,
       4,     4,     4,     5,     6,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     4,     3,     5,     4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "RMAIN",
  "PARA", "PARC", "LLAVA", "LLAVC", "CORA", "CORC", "VOID", "INT",
  "TSTRING", "FLOAT", "BOOLEAN", "RTRUE", "RFALSE", "NLL", "PRINTF",
  "RIOTA", "RATOI", "RATOF", "RMEAN", "RMEDIAN", "RMODE", "SUMA", "MENOS",
  "POR", "DIV", "INC", "MOD", "RIF", "RELSE", "RWHILE", "RFOR", "RBREAK",
  "RCONTINUE", "RRETURN", "AND", "OR", "NOT", "MAY", "MEN", "MAY_IG",
  "MEN_IG", "DIF", "IG", "STRUCT", "RVECTOR", "VPBACK", "VGET", "VREMOVE",
  "VSIZE", "VPFRONT", "';'", "'='", "'.'", "','", "$accept", "START",
  "LIST_FUNC", "FUNCTION", "FUNC_LIST", "MAIN", "LIST_INST", "INSTRUCTION",
  "RETURN", "PRINT", "DECLARATION", "ASSIGNMENT", "BREAK", "CONTINUE",
  "INST_VECTOR", "IF", "ELSEIF_LIST", "ELSEIF", "ELSE", "WHILE", "FOR",
  "STRUCT_DECLARATION", "DEC_LIST", "STRUCT_CREATION", "EXP_LIST", "TYPES",
  "EXP", "IOTA", "ATOI", "ATOF", "MEAN", "MEDIAN", "MODE", "SIZE", "GET",
  "PRIMITIVE", "BOOL", "LIST_ARR", "CALL_EXP", "CALL_INST", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   192,   192,   199,   208,   213,   220,   224,   230,   235,
     242,   248,   253,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   275,   276,   279,   282,
     283,   286,   287,   290,   293,   296,   297,   298,   301,   305,
     311,   316,   323,   329,   330,   333,   336,   339,   342,   347,
     354,   360,   365,   372,   373,   374,   375,   376,   377,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   410,   413,   416,
     419,   422,   425,   428,   431,   434,   446,   452,   453,   454,
     457,   458,   461,   462,   463,   466,   467,   470,   471
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
#line 2988 "parser.cpp"

#line 474 "parser.y"


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

