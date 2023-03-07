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
#line 74 "parser.y"
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.YY_MOVE_OR_COPY< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.YY_MOVE_OR_COPY< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
        value.YY_MOVE_OR_COPY< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.YY_MOVE_OR_COPY< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.YY_MOVE_OR_COPY< list_instruction* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_POT: // POT
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.move< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
        value.move< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_POT: // POT
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.copy< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
        value.copy< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (that.value);
        break;

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
      case symbol_kind::S_POT: // POT
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        value.move< expression* > (that.value);
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (that.value);
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
        value.move< instruction* > (that.value);
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (that.value);
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (that.value);
        break;

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
      case symbol_kind::S_POT: // POT
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
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
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 662 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 668 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 674 "parser.cpp"
        break;

      case symbol_kind::S_TSTRING: // TSTRING
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 680 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 686 "parser.cpp"
        break;

      case symbol_kind::S_BOOLEAN: // BOOLEAN
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 692 "parser.cpp"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 698 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 704 "parser.cpp"
        break;

      case symbol_kind::S_BOOLTRUE: // BOOLTRUE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 710 "parser.cpp"
        break;

      case symbol_kind::S_BOOLFALSE: // BOOLFALSE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 716 "parser.cpp"
        break;

      case symbol_kind::S_PARA: // PARA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 722 "parser.cpp"
        break;

      case symbol_kind::S_PARC: // PARC
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 728 "parser.cpp"
        break;

      case symbol_kind::S_LLAVA: // LLAVA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 734 "parser.cpp"
        break;

      case symbol_kind::S_LLAVC: // LLAVC
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 740 "parser.cpp"
        break;

      case symbol_kind::S_CORA: // CORA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 746 "parser.cpp"
        break;

      case symbol_kind::S_CORC: // CORC
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 752 "parser.cpp"
        break;

      case symbol_kind::S_VOID: // VOID
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 758 "parser.cpp"
        break;

      case symbol_kind::S_RMAIN: // RMAIN
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 764 "parser.cpp"
        break;

      case symbol_kind::S_NLL: // NLL
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 770 "parser.cpp"
        break;

      case symbol_kind::S_SUMA: // SUMA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 776 "parser.cpp"
        break;

      case symbol_kind::S_MENOS: // MENOS
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 782 "parser.cpp"
        break;

      case symbol_kind::S_POR: // POR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 788 "parser.cpp"
        break;

      case symbol_kind::S_DIV: // DIV
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 794 "parser.cpp"
        break;

      case symbol_kind::S_POT: // POT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 800 "parser.cpp"
        break;

      case symbol_kind::S_INC: // INC
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 806 "parser.cpp"
        break;

      case symbol_kind::S_MOD: // MOD
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 812 "parser.cpp"
        break;

      case symbol_kind::S_RIF: // RIF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 818 "parser.cpp"
        break;

      case symbol_kind::S_RELSE: // RELSE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 824 "parser.cpp"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 830 "parser.cpp"
        break;

      case symbol_kind::S_FOR: // FOR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 836 "parser.cpp"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 842 "parser.cpp"
        break;

      case symbol_kind::S_ASIGNAR: // ASIGNAR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 848 "parser.cpp"
        break;

      case symbol_kind::S_MEDIA: // MEDIA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 854 "parser.cpp"
        break;

      case symbol_kind::S_MEDIANA: // MEDIANA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 860 "parser.cpp"
        break;

      case symbol_kind::S_MODA: // MODA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 866 "parser.cpp"
        break;

      case symbol_kind::S_ATOI: // ATOI
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 872 "parser.cpp"
        break;

      case symbol_kind::S_ATOF: // ATOF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 878 "parser.cpp"
        break;

      case symbol_kind::S_IOTA: // IOTA
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 884 "parser.cpp"
        break;

      case symbol_kind::S_BREAK: // BREAK
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 890 "parser.cpp"
        break;

      case symbol_kind::S_CONTINUE: // CONTINUE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 896 "parser.cpp"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 902 "parser.cpp"
        break;

      case symbol_kind::S_MAYOR: // MAYOR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 908 "parser.cpp"
        break;

      case symbol_kind::S_MENOR: // MENOR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 914 "parser.cpp"
        break;

      case symbol_kind::S_MAYEQU: // MAYEQU
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 920 "parser.cpp"
        break;

      case symbol_kind::S_MENEQU: // MENEQU
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 926 "parser.cpp"
        break;

      case symbol_kind::S_EQU: // EQU
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 932 "parser.cpp"
        break;

      case symbol_kind::S_DIFF: // DIFF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 938 "parser.cpp"
        break;

      case symbol_kind::S_AND: // AND
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 944 "parser.cpp"
        break;

      case symbol_kind::S_OR: // OR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 950 "parser.cpp"
        break;

      case symbol_kind::S_NOT: // NOT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 956 "parser.cpp"
        break;

      case symbol_kind::S_START: // START
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 962 "parser.cpp"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < func_main* > (); }
#line 968 "parser.cpp"
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 974 "parser.cpp"
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 980 "parser.cpp"
        break;

      case symbol_kind::S_PRINT: // PRINT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 986 "parser.cpp"
        break;

      case symbol_kind::S_IF: // IF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 992 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 998 "parser.cpp"
        break;

      case symbol_kind::S_ELSEIF: // ELSEIF
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1004 "parser.cpp"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < list_instruction* > (); }
#line 1010 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1016 "parser.cpp"
        break;

      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < map_struct_dec* > (); }
#line 1022 "parser.cpp"
        break;

      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1028 "parser.cpp"
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < list_expression* > (); }
#line 1034 "parser.cpp"
        break;

      case symbol_kind::S_DECLARATION: // DECLARATION
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < instruction* > (); }
#line 1040 "parser.cpp"
        break;

      case symbol_kind::S_TYPES: // TYPES
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < TipoDato > (); }
#line 1046 "parser.cpp"
        break;

      case symbol_kind::S_EXP: // EXP
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1052 "parser.cpp"
        break;

      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1058 "parser.cpp"
        break;

      case symbol_kind::S_LIST_ARR: // LIST_ARR
#line 158 "parser.y"
                 { yyoutput << yysym.value.template as < expression* > (); }
#line 1064 "parser.cpp"
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
      case symbol_kind::S_PRIMITIVE: // PRIMITIVE
      case symbol_kind::S_LIST_ARR: // LIST_ARR
        yylhs.value.emplace< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        yylhs.value.emplace< func_main* > ();
        break;

      case symbol_kind::S_INSTRUCTION: // INSTRUCTION
      case symbol_kind::S_PRINT: // PRINT
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSEIF: // ELSEIF
      case symbol_kind::S_DECLARE_STRUCT: // DECLARE_STRUCT
      case symbol_kind::S_CREATE_STRUCT: // CREATE_STRUCT
      case symbol_kind::S_DECLARATION: // DECLARATION
        yylhs.value.emplace< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        yylhs.value.emplace< list_expression* > ();
        break;

      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        yylhs.value.emplace< list_instruction* > ();
        break;

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
      case symbol_kind::S_POT: // POT
      case symbol_kind::S_INC: // INC
      case symbol_kind::S_MOD: // MOD
      case symbol_kind::S_RIF: // RIF
      case symbol_kind::S_RELSE: // RELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ASIGNAR: // ASIGNAR
      case symbol_kind::S_MEDIA: // MEDIA
      case symbol_kind::S_MEDIANA: // MEDIANA
      case symbol_kind::S_MODA: // MODA
      case symbol_kind::S_ATOI: // ATOI
      case symbol_kind::S_ATOF: // ATOF
      case symbol_kind::S_IOTA: // IOTA
      case symbol_kind::S_BREAK: // BREAK
      case symbol_kind::S_CONTINUE: // CONTINUE
      case symbol_kind::S_RETURN: // RETURN
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
#line 166 "parser.y"
    {
        ctx.Main = yystack_[0].value.as < func_main* > ();
        ctx.Salida = "!Ejecución realizada con éxito!";
        yylhs.value.as < func_main* > () = yystack_[0].value.as < func_main* > ();
    }
#line 1413 "parser.cpp"
    break;

  case 3: // MAIN: VOID RMAIN PARA PARC LLAVA LIST_INST LLAVC
#line 174 "parser.y"
{
    yylhs.value.as < func_main* > () = new func_main(0, 0, yystack_[6].value.as < std::string > (), yystack_[1].value.as < list_instruction* > ());
}
#line 1421 "parser.cpp"
    break;

  case 4: // LIST_INST: LIST_INST INSTRUCTION
#line 186 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1430 "parser.cpp"
    break;

  case 5: // LIST_INST: INSTRUCTION
#line 191 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1439 "parser.cpp"
    break;

  case 6: // INSTRUCTION: PRINT ';'
#line 197 "parser.y"
                        { yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > (); }
#line 1445 "parser.cpp"
    break;

  case 7: // INSTRUCTION: IF
#line 198 "parser.y"
                  { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1451 "parser.cpp"
    break;

  case 8: // INSTRUCTION: DECLARATION ';'
#line 201 "parser.y"
                              {yylhs.value.as < instruction* > () = yystack_[1].value.as < instruction* > ();}
#line 1457 "parser.cpp"
    break;

  case 9: // INSTRUCTION: DECLARE_STRUCT
#line 202 "parser.y"
                             { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1463 "parser.cpp"
    break;

  case 10: // INSTRUCTION: CREATE_STRUCT
#line 203 "parser.y"
                            { yylhs.value.as < instruction* > () = yystack_[0].value.as < instruction* > (); }
#line 1469 "parser.cpp"
    break;

  case 11: // PRINT: PRINTF PARA EXP PARC
#line 219 "parser.y"
                             { yylhs.value.as < instruction* > () = new print(0,0,yystack_[1].value.as < expression* > ()); }
#line 1475 "parser.cpp"
    break;

  case 12: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST ELSE
#line 223 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[5].value.as < expression* > (),yystack_[3].value.as < list_instruction* > (),yystack_[1].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > ());
    }
#line 1483 "parser.cpp"
    break;

  case 13: // IF: RIF EXP LLAVA LIST_INST LLAVC
#line 227 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (),nullptr,nullptr);
    }
#line 1491 "parser.cpp"
    break;

  case 14: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSEIF_LIST
#line 231 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),yystack_[0].value.as < list_instruction* > (),nullptr);
    }
#line 1499 "parser.cpp"
    break;

  case 15: // IF: RIF EXP LLAVA LIST_INST LLAVC ELSE
#line 235 "parser.y"
    {
        yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[4].value.as < expression* > (),yystack_[2].value.as < list_instruction* > (),nullptr,yystack_[0].value.as < list_instruction* > ());
    }
#line 1507 "parser.cpp"
    break;

  case 16: // ELSEIF_LIST: ELSEIF_LIST ELSEIF
#line 241 "parser.y"
        { 
            yystack_[1].value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
            yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > ();
        }
#line 1516 "parser.cpp"
    break;

  case 17: // ELSEIF_LIST: ELSEIF
#line 246 "parser.y"
        {
            yylhs.value.as < list_instruction* > () = new list_instruction();
            yylhs.value.as < list_instruction* > ()->newInst(yystack_[0].value.as < instruction* > ());
        }
#line 1525 "parser.cpp"
    break;

  case 18: // ELSEIF: RELSE RIF EXP LLAVA LIST_INST LLAVC
#line 253 "parser.y"
        {
            yylhs.value.as < instruction* > () = new func_if(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < list_instruction* > (), nullptr, nullptr);
        }
#line 1533 "parser.cpp"
    break;

  case 19: // ELSE: RELSE LLAVA LIST_INST LLAVC
#line 258 "parser.y"
                                   { yylhs.value.as < list_instruction* > () = yystack_[1].value.as < list_instruction* > (); }
#line 1539 "parser.cpp"
    break;

  case 20: // ELSE: %empty
#line 259 "parser.y"
             { }
#line 1545 "parser.cpp"
    break;

  case 21: // DECLARE_STRUCT: STRUCT ID LLAVA DECLARE_LIST LLAVC
#line 269 "parser.y"
                                                   {yylhs.value.as < instruction* > () = new dec_struct(0,0,yystack_[1].value.as < map_struct_dec* > (),yystack_[3].value.as < std::string > ()); }
#line 1551 "parser.cpp"
    break;

  case 22: // DECLARE_LIST: DECLARE_LIST TYPES ID ';'
#line 273 "parser.y"
        {
            yystack_[3].value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (),yystack_[2].value.as < TipoDato > ());
            yylhs.value.as < map_struct_dec* > () = yystack_[3].value.as < map_struct_dec* > ();
        }
#line 1560 "parser.cpp"
    break;

  case 23: // DECLARE_LIST: TYPES ID ';'
#line 278 "parser.y"
        {   
            yylhs.value.as < map_struct_dec* > () = new map_struct_dec();
            yylhs.value.as < map_struct_dec* > ()->newMap(yystack_[1].value.as < std::string > (), yystack_[2].value.as < TipoDato > ());
        }
#line 1569 "parser.cpp"
    break;

  case 24: // CREATE_STRUCT: STRUCT ID ID '=' LLAVA EXP_LIST LLAVC
#line 285 "parser.y"
                {
                    yylhs.value.as < instruction* > () = new create_struct(0,0,yystack_[5].value.as < std::string > (),yystack_[4].value.as < std::string > (),yystack_[1].value.as < list_expression* > ());
                }
#line 1577 "parser.cpp"
    break;

  case 25: // EXP_LIST: EXP_LIST ',' EXP
#line 291 "parser.y"
        {
            yystack_[2].value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
            yylhs.value.as < list_expression* > () = yystack_[2].value.as < list_expression* > ();
        }
#line 1586 "parser.cpp"
    break;

  case 26: // EXP_LIST: EXP
#line 296 "parser.y"
        {
            yylhs.value.as < list_expression* > () = new list_expression();
            yylhs.value.as < list_expression* > ()->newExp(yystack_[0].value.as < expression* > ());
        }
#line 1595 "parser.cpp"
    break;

  case 27: // DECLARATION: TYPES ID '=' EXP
#line 302 "parser.y"
                               {yylhs.value.as < instruction* > () = new declare(0,0,yystack_[3].value.as < TipoDato > (),yystack_[2].value.as < std::string > (),yystack_[0].value.as < expression* > ());}
#line 1601 "parser.cpp"
    break;

  case 28: // DECLARATION: TYPES ID
#line 303 "parser.y"
                       {yylhs.value.as < instruction* > () = new declare(0,0,yystack_[1].value.as < TipoDato > (),yystack_[0].value.as < std::string > (),nullptr);}
#line 1607 "parser.cpp"
    break;

  case 29: // TYPES: INT
#line 341 "parser.y"
            { yylhs.value.as < TipoDato > () = INTEGER; }
#line 1613 "parser.cpp"
    break;

  case 30: // TYPES: TSTRING
#line 342 "parser.y"
              { yylhs.value.as < TipoDato > () = STRING; }
#line 1619 "parser.cpp"
    break;

  case 31: // TYPES: BOOLEAN
#line 343 "parser.y"
              { yylhs.value.as < TipoDato > () = BOOL; }
#line 1625 "parser.cpp"
    break;

  case 32: // TYPES: FLOAT
#line 344 "parser.y"
            { yylhs.value.as < TipoDato > () = FLOAT; }
#line 1631 "parser.cpp"
    break;

  case 33: // EXP: EXP SUMA EXP
#line 348 "parser.y"
                   { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "+"); }
#line 1637 "parser.cpp"
    break;

  case 34: // EXP: EXP MENOS EXP
#line 349 "parser.y"
                    { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "-"); }
#line 1643 "parser.cpp"
    break;

  case 35: // EXP: EXP POR EXP
#line 350 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "*"); }
#line 1649 "parser.cpp"
    break;

  case 36: // EXP: EXP DIV EXP
#line 351 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "/"); }
#line 1655 "parser.cpp"
    break;

  case 37: // EXP: EXP MOD EXP
#line 352 "parser.y"
                  { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "%"); }
#line 1661 "parser.cpp"
    break;

  case 38: // EXP: EXP INC
#line 354 "parser.y"
              { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[1].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++A"); }
#line 1667 "parser.cpp"
    break;

  case 39: // EXP: INC EXP
#line 355 "parser.y"
              { yylhs.value.as < expression* > () = new operation(0, 0, yystack_[0].value.as < expression* > (), new primitive(0,0,INTEGER, "", 0,0.0,false), "++B"); }
#line 1673 "parser.cpp"
    break;

  case 40: // EXP: EXP MAYOR EXP
#line 357 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">");}
#line 1679 "parser.cpp"
    break;

  case 41: // EXP: EXP MAYEQU EXP
#line 358 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), ">=");}
#line 1685 "parser.cpp"
    break;

  case 42: // EXP: EXP MENOR EXP
#line 359 "parser.y"
                    {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<");}
#line 1691 "parser.cpp"
    break;

  case 43: // EXP: EXP MENEQU EXP
#line 360 "parser.y"
                     {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "<=");}
#line 1697 "parser.cpp"
    break;

  case 44: // EXP: EXP EQU EXP
#line 361 "parser.y"
                  {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "==");}
#line 1703 "parser.cpp"
    break;

  case 45: // EXP: EXP DIFF EXP
#line 362 "parser.y"
                   {yylhs.value.as < expression* > () =  new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "!=");}
#line 1709 "parser.cpp"
    break;

  case 46: // EXP: EXP AND EXP
#line 364 "parser.y"
                  {yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "&&");}
#line 1715 "parser.cpp"
    break;

  case 47: // EXP: EXP OR EXP
#line 365 "parser.y"
                 {yylhs.value.as < expression* > () = new operation(0, 0, yystack_[2].value.as < expression* > (), yystack_[0].value.as < expression* > (), "||");}
#line 1721 "parser.cpp"
    break;

  case 48: // EXP: NOT EXP
#line 367 "parser.y"
    {
        yylhs.value.as < expression* > () = new operation(0, 0, yystack_[0].value.as < expression* > (), new primitive(0,0,BOOL, "", 0,0.0,false), "!");
    }
#line 1729 "parser.cpp"
    break;

  case 49: // EXP: MENOS EXP
#line 371 "parser.y"
                {
        yylhs.value.as < expression* > () = new operation(0,0,yystack_[0].value.as < expression* > (),new primitive(0,0,INTEGER, "", 0,0.0,false),"NEG");
        }
#line 1737 "parser.cpp"
    break;

  case 50: // EXP: PARA EXP PARC
#line 375 "parser.y"
                    { yylhs.value.as < expression* > () = yystack_[1].value.as < expression* > (); }
#line 1743 "parser.cpp"
    break;

  case 51: // EXP: PRIMITIVE
#line 377 "parser.y"
                { yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > (); }
#line 1749 "parser.cpp"
    break;

  case 52: // PRIMITIVE: NUMERO
#line 381 "parser.y"
                   { 
            std::string cadena = yystack_[0].value.as < std::string > ();
            if(cadena.find(".") == -1)
            {   
                int num = stoi(yystack_[0].value.as < std::string > ());
                yylhs.value.as < expression* > () = new primitive(0,0,INTEGER, "", num,0.0,false); }
            else
            {
                float num = stof(yystack_[0].value.as < std::string > ());
                yylhs.value.as < expression* > () = new primitive(0,0,FLOAT, "", 0, num,false);}
            
            }
#line 1766 "parser.cpp"
    break;

  case 53: // PRIMITIVE: STRING
#line 394 "parser.y"
        { 
            std::string str1 = yystack_[0].value.as < std::string > ().erase(0,1);
            std::string str2 = str1.erase(str1.length()-1,1);
            yylhs.value.as < expression* > () = new primitive(0,0,STRING,str2,0,0.0,false);
        }
#line 1776 "parser.cpp"
    break;

  case 54: // PRIMITIVE: BOOLTRUE
#line 399 "parser.y"
                  {yylhs.value.as < expression* > () = new primitive(0,0,BOOL, "", 0, 0.0, true);}
#line 1782 "parser.cpp"
    break;

  case 55: // PRIMITIVE: BOOLFALSE
#line 400 "parser.y"
                   {yylhs.value.as < expression* > () = new primitive(0,0,BOOL, "", 0, 0.0, false);}
#line 1788 "parser.cpp"
    break;

  case 56: // PRIMITIVE: LIST_ARR
#line 401 "parser.y"
                  {yylhs.value.as < expression* > () = yystack_[0].value.as < expression* > ();}
#line 1794 "parser.cpp"
    break;

  case 57: // LIST_ARR: LIST_ARR CORA EXP CORC
#line 404 "parser.y"
                                  { yylhs.value.as < expression* > () = new array_access(0,0,yystack_[3].value.as < expression* > (),yystack_[1].value.as < expression* > ()); }
#line 1800 "parser.cpp"
    break;

  case 58: // LIST_ARR: LIST_ARR '.' ID
#line 405 "parser.y"
                          { yylhs.value.as < expression* > () = new struct_access(0,0,yystack_[2].value.as < expression* > (),yystack_[0].value.as < std::string > ()); }
#line 1806 "parser.cpp"
    break;

  case 59: // LIST_ARR: ID
#line 406 "parser.y"
             {yylhs.value.as < expression* > () = new access(0,0,yystack_[0].value.as < std::string > ()); }
#line 1812 "parser.cpp"
    break;


#line 1816 "parser.cpp"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
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

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -45;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      -5,     5,    15,   -45,    34,   -45,    38,    39,    10,   -45,
     -45,   -45,    49,   -45,    37,    44,   213,   -45,     6,   -45,
     -45,   -45,     9,    54,    40,   -45,   -45,   -45,   -45,   -45,
      37,    37,    37,    37,   107,   -45,   -11,    37,   -45,   -45,
     -45,   -45,    14,    16,   117,    58,   -15,    46,   190,    10,
      37,    37,    37,    37,   -45,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    73,    70,    37,    63,    59,
      83,   -45,   241,   -15,   -15,    46,    46,    46,   167,   167,
     167,   167,   260,   260,   190,   190,   152,   -45,   -45,   160,
      37,   -45,    84,    21,    60,   -45,    -9,   160,    48,   -45,
      22,    60,   -45,   -45,   -45,    37,   -45,    10,    37,   -45,
     -45,   160,   246,   118,   -45,    10,   257,   -45
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     1,     0,     0,     0,    30,
      32,    31,     0,    29,     0,     0,     0,     5,     0,     7,
       9,    10,     0,     0,     0,    52,    59,    53,    54,    55,
       0,     0,     0,     0,     0,    51,    56,     0,     3,     4,
       6,     8,    28,     0,     0,     0,    49,    39,    48,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    50,     0,    33,    34,    35,    36,    37,    40,    42,
      41,    43,    44,    45,    46,    47,     0,    58,    11,    27,
       0,    21,     0,     0,    13,    57,     0,    26,     0,    23,
       0,    14,    17,    15,    24,     0,    22,     0,     0,    16,
      12,    25,     0,     0,    19,     0,     0,    18
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -45,   -45,   -45,   -44,   -16,   -45,   -45,   -45,   -10,    -2,
     -45,   -45,   -45,   -45,   -45,   -33,   -29,   -45,   -45
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     3,    16,    17,    18,    19,   101,   102,   103,
      20,    69,    21,    96,    22,    23,    34,    35,    36
  };

  const signed char
  Parser::yytable_[] =
  {
      39,    45,    46,    47,    48,    72,    64,   104,    66,    52,
      53,    70,    54,    55,     1,     5,     9,    10,    11,    12,
      13,    73,    74,    75,    76,     4,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    92,   107,    89,    14,
      25,    26,    27,    15,    43,    65,   105,     6,    28,    29,
      30,   108,     7,    24,     8,    44,    39,    37,    42,    40,
      31,    97,    41,   112,    32,     9,    10,    11,    67,    13,
      68,   116,    71,    54,    99,    91,   111,    87,    90,   113,
      50,    51,    52,    53,    88,    54,    55,    93,    98,    33,
     100,   109,    50,    51,    52,    53,    39,    54,    55,   110,
      39,   106,    56,    57,    58,    59,    60,    61,    62,    63,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    49,     9,    10,    11,     0,    13,     0,    50,
      51,    52,    53,   115,    54,    55,     0,     0,     0,     0,
      50,    51,    52,    53,     0,    54,    55,     0,     0,     0,
       0,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,     0,    56,    57,    58,    59,    60,    61,    62,    63,
      95,     0,     0,     0,    50,    51,    52,    53,     0,    54,
      55,     0,    50,    51,    52,    53,     0,    54,    55,    50,
      51,    52,    53,     0,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    56,    57,    58,    59,    60,    61,
      62,    63,    50,    51,    52,    53,     0,    54,    55,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
       0,     0,    14,     0,     0,     0,    15,     9,    10,    11,
      12,    13,     9,    10,    11,    12,    13,    94,     0,     0,
       0,     0,   114,     9,    10,    11,    12,    13,     0,     0,
      14,     0,     0,   117,    15,    14,     0,     0,     0,    15,
       0,     0,    50,    51,    52,    53,    14,    54,    55,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,    58,    59
  };

  const signed char
  Parser::yycheck_[] =
  {
      16,    30,    31,    32,    33,    49,    17,    16,    37,    24,
      25,    44,    27,    28,    19,     0,     6,     7,     8,     9,
      10,    50,    51,    52,    53,    20,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    69,    15,    67,    29,
       3,     4,     5,    33,     4,    56,    55,    13,    11,    12,
      13,    29,    14,     4,    15,    15,    72,    13,     4,    53,
      23,    90,    53,   107,    27,     6,     7,     8,    54,    10,
      54,   115,    14,    27,    53,    16,   105,     4,    15,   108,
      22,    23,    24,    25,    14,    27,    28,     4,     4,    52,
      30,   101,    22,    23,    24,    25,   112,    27,    28,   101,
     116,    53,    44,    45,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    15,     6,     7,     8,    -1,    10,    -1,    22,
      23,    24,    25,    15,    27,    28,    -1,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    27,
      28,    -1,    22,    23,    24,    25,    -1,    27,    28,    22,
      23,    24,    25,    -1,    27,    28,    44,    45,    46,    47,
      48,    49,    50,    51,    44,    45,    46,    47,    48,    49,
      50,    51,    22,    23,    24,    25,    -1,    27,    28,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    29,    -1,    -1,    -1,    33,     6,     7,     8,
       9,    10,     6,     7,     8,     9,    10,    16,    -1,    -1,
      -1,    -1,    16,     6,     7,     8,     9,    10,    -1,    -1,
      29,    -1,    -1,    16,    33,    29,    -1,    -1,    -1,    33,
      -1,    -1,    22,    23,    24,    25,    29,    27,    28,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    19,    58,    59,    20,     0,    13,    14,    15,     6,
       7,     8,     9,    10,    29,    33,    60,    61,    62,    63,
      67,    69,    71,    72,     4,     3,     4,     5,    11,    12,
      13,    23,    27,    52,    73,    74,    75,    13,    16,    61,
      53,    53,     4,     4,    15,    73,    73,    73,    73,    15,
      22,    23,    24,    25,    27,    28,    44,    45,    46,    47,
      48,    49,    50,    51,    17,    56,    73,    54,    54,    68,
      72,    14,    60,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,     4,    14,    73,
      15,    16,    72,     4,    16,    18,    70,    73,     4,    53,
      30,    64,    65,    66,    16,    55,    53,    15,    29,    65,
      66,    73,    60,    73,    16,    15,    60,    16
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    62,    63,    63,    63,    63,    64,    64,    65,    66,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    75,    75,    75
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     7,     2,     1,     2,     1,     2,     1,
       1,     4,     7,     5,     6,     6,     2,     1,     6,     4,
       0,     5,     4,     3,     7,     3,     1,     4,     2,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     4,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING",
  "TSTRING", "FLOAT", "BOOLEAN", "STRUCT", "INT", "BOOLTRUE", "BOOLFALSE",
  "PARA", "PARC", "LLAVA", "LLAVC", "CORA", "CORC", "VOID", "RMAIN", "NLL",
  "SUMA", "MENOS", "POR", "DIV", "POT", "INC", "MOD", "RIF", "RELSE",
  "WHILE", "FOR", "PRINTF", "ASIGNAR", "MEDIA", "MEDIANA", "MODA", "ATOI",
  "ATOF", "IOTA", "BREAK", "CONTINUE", "RETURN", "MAYOR", "MENOR",
  "MAYEQU", "MENEQU", "EQU", "DIFF", "AND", "OR", "NOT", "';'", "'='",
  "','", "'.'", "$accept", "START", "MAIN", "LIST_INST", "INSTRUCTION",
  "PRINT", "IF", "ELSEIF_LIST", "ELSEIF", "ELSE", "DECLARE_STRUCT",
  "DECLARE_LIST", "CREATE_STRUCT", "EXP_LIST", "DECLARATION", "TYPES",
  "EXP", "PRIMITIVE", "LIST_ARR", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   165,   165,   173,   185,   190,   197,   198,   201,   202,
     203,   219,   222,   226,   230,   234,   240,   245,   252,   258,
     259,   269,   272,   277,   284,   290,   295,   302,   303,   341,
     342,   343,   344,   348,   349,   350,   351,   352,   354,   355,
     357,   358,   359,   360,   361,   362,   364,   365,   366,   371,
     375,   377,   381,   393,   399,   400,   401,   404,   405,   406
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
#line 2391 "parser.cpp"

#line 409 "parser.y"

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
