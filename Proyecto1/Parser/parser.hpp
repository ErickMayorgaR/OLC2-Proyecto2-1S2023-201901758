// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 33 "parser.y"

    /* cabeceras iniciales */
    #include <sstream>
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
    #include "../Proyecto1/Expression/matrix_access.hpp"
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
    #include "../Proyecto1/Instruction/assign_struct.hpp"
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


#line 113 "parser.hpp"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 242 "parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // TYPES
      char dummy1[sizeof (TipoDato)];

      // GET
      // SIZE
      // MEAN
      // MEDIAN
      // MODE
      // EXP
      // ATOI
      // ATOF
      // IOTA
      // INCREMENT
      // PRIMITIVE
      // LIST_ARR
      // STRUCT_ACCESS
      // CALL_EXP
      char dummy2[sizeof (expression*)];

      // START
      // MAIN
      char dummy3[sizeof (func_main*)];

      // FUNCTION
      // INSTRUCTION
      // PRINT
      // PUSHBACK
      // PUSHFRONT
      // REMOVE
      // IF
      // ELSEIF
      // WHILE
      // FOR
      // EXPRESSION
      // DECLARE_STRUCT
      // CREATE_STRUCT
      // DECLARATION
      // ASSIGNATION
      // BREAK
      // CONTINUE
      // RETURN
      // DECLARE_VECTOR
      // DECLARE_MATRIX
      // CALL_INST
      char dummy4[sizeof (instruction*)];

      // EXP_LIST
      char dummy5[sizeof (list_expression*)];

      // LIST_FUNC
      // LIST_STRUCT
      // LIST_INST
      // ELSEIF_LIST
      // ELSE
      char dummy6[sizeof (list_instruction*)];

      // FUNCTION_LIST
      // DECLARE_LIST
      char dummy7[sizeof (map_struct_dec*)];

      // NUMERO
      // ID
      // STRING
      // TSTRING
      // FLOAT
      // BOOLEAN
      // RSTRUCT
      // RVECTOR
      // INT
      // BOOLTRUE
      // BOOLFALSE
      // PARA
      // PARC
      // LLAVA
      // LLAVC
      // CORA
      // CORC
      // VOID
      // RMAIN
      // NLL
      // SUMA
      // MENOS
      // POR
      // DIV
      // INC
      // MOD
      // RIF
      // RELSE
      // RWHILE
      // RFOR
      // PRINTF
      // RMEAN
      // RMEDIAN
      // RMODE
      // RATOI
      // RATOF
      // RIOTA
      // RBREAK
      // RCONTINUE
      // RRETURN
      // MAYOR
      // MENOR
      // MAYEQU
      // MENEQU
      // EQU
      // DIFF
      // AND
      // OR
      // NOT
      // VPBACK
      // VGET
      // VREMOVE
      // VSIZE
      // VPFRONT
      char dummy8[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    NUMERO = 258,                  // NUMERO
    ID = 259,                      // ID
    STRING = 260,                  // STRING
    TSTRING = 261,                 // TSTRING
    FLOAT = 262,                   // FLOAT
    BOOLEAN = 263,                 // BOOLEAN
    RSTRUCT = 264,                 // RSTRUCT
    RVECTOR = 265,                 // RVECTOR
    INT = 266,                     // INT
    BOOLTRUE = 267,                // BOOLTRUE
    BOOLFALSE = 268,               // BOOLFALSE
    PARA = 269,                    // PARA
    PARC = 270,                    // PARC
    LLAVA = 271,                   // LLAVA
    LLAVC = 272,                   // LLAVC
    CORA = 273,                    // CORA
    CORC = 274,                    // CORC
    VOID = 275,                    // VOID
    RMAIN = 276,                   // RMAIN
    NLL = 277,                     // NLL
    SUMA = 278,                    // SUMA
    MENOS = 279,                   // MENOS
    POR = 280,                     // POR
    DIV = 281,                     // DIV
    INC = 282,                     // INC
    MOD = 283,                     // MOD
    RIF = 284,                     // RIF
    RELSE = 285,                   // RELSE
    RWHILE = 286,                  // RWHILE
    RFOR = 287,                    // RFOR
    PRINTF = 288,                  // PRINTF
    RMEAN = 289,                   // RMEAN
    RMEDIAN = 290,                 // RMEDIAN
    RMODE = 291,                   // RMODE
    RATOI = 292,                   // RATOI
    RATOF = 293,                   // RATOF
    RIOTA = 294,                   // RIOTA
    RBREAK = 295,                  // RBREAK
    RCONTINUE = 296,               // RCONTINUE
    RRETURN = 297,                 // RRETURN
    MAYOR = 298,                   // MAYOR
    MENOR = 299,                   // MENOR
    MAYEQU = 300,                  // MAYEQU
    MENEQU = 301,                  // MENEQU
    EQU = 302,                     // EQU
    DIFF = 303,                    // DIFF
    AND = 304,                     // AND
    OR = 305,                      // OR
    NOT = 306,                     // NOT
    VPBACK = 307,                  // VPBACK
    VGET = 308,                    // VGET
    VREMOVE = 309,                 // VREMOVE
    VSIZE = 310,                   // VSIZE
    VPFRONT = 311                  // VPFRONT
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 61, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NUMERO = 3,                            // NUMERO
        S_ID = 4,                                // ID
        S_STRING = 5,                            // STRING
        S_TSTRING = 6,                           // TSTRING
        S_FLOAT = 7,                             // FLOAT
        S_BOOLEAN = 8,                           // BOOLEAN
        S_RSTRUCT = 9,                           // RSTRUCT
        S_RVECTOR = 10,                          // RVECTOR
        S_INT = 11,                              // INT
        S_BOOLTRUE = 12,                         // BOOLTRUE
        S_BOOLFALSE = 13,                        // BOOLFALSE
        S_PARA = 14,                             // PARA
        S_PARC = 15,                             // PARC
        S_LLAVA = 16,                            // LLAVA
        S_LLAVC = 17,                            // LLAVC
        S_CORA = 18,                             // CORA
        S_CORC = 19,                             // CORC
        S_VOID = 20,                             // VOID
        S_RMAIN = 21,                            // RMAIN
        S_NLL = 22,                              // NLL
        S_SUMA = 23,                             // SUMA
        S_MENOS = 24,                            // MENOS
        S_POR = 25,                              // POR
        S_DIV = 26,                              // DIV
        S_INC = 27,                              // INC
        S_MOD = 28,                              // MOD
        S_RIF = 29,                              // RIF
        S_RELSE = 30,                            // RELSE
        S_RWHILE = 31,                           // RWHILE
        S_RFOR = 32,                             // RFOR
        S_PRINTF = 33,                           // PRINTF
        S_RMEAN = 34,                            // RMEAN
        S_RMEDIAN = 35,                          // RMEDIAN
        S_RMODE = 36,                            // RMODE
        S_RATOI = 37,                            // RATOI
        S_RATOF = 38,                            // RATOF
        S_RIOTA = 39,                            // RIOTA
        S_RBREAK = 40,                           // RBREAK
        S_RCONTINUE = 41,                        // RCONTINUE
        S_RRETURN = 42,                          // RRETURN
        S_MAYOR = 43,                            // MAYOR
        S_MENOR = 44,                            // MENOR
        S_MAYEQU = 45,                           // MAYEQU
        S_MENEQU = 46,                           // MENEQU
        S_EQU = 47,                              // EQU
        S_DIFF = 48,                             // DIFF
        S_AND = 49,                              // AND
        S_OR = 50,                               // OR
        S_NOT = 51,                              // NOT
        S_VPBACK = 52,                           // VPBACK
        S_VGET = 53,                             // VGET
        S_VREMOVE = 54,                          // VREMOVE
        S_VSIZE = 55,                            // VSIZE
        S_VPFRONT = 56,                          // VPFRONT
        S_57_ = 57,                              // ';'
        S_58_ = 58,                              // '='
        S_59_ = 59,                              // ','
        S_60_ = 60,                              // '.'
        S_YYACCEPT = 61,                         // $accept
        S_START = 62,                            // START
        S_LIST_FUNC = 63,                        // LIST_FUNC
        S_LIST_STRUCT = 64,                      // LIST_STRUCT
        S_FUNCTION = 65,                         // FUNCTION
        S_FUNCTION_LIST = 66,                    // FUNCTION_LIST
        S_MAIN = 67,                             // MAIN
        S_LIST_INST = 68,                        // LIST_INST
        S_INSTRUCTION = 69,                      // INSTRUCTION
        S_PRINT = 70,                            // PRINT
        S_PUSHBACK = 71,                         // PUSHBACK
        S_PUSHFRONT = 72,                        // PUSHFRONT
        S_GET = 73,                              // GET
        S_SIZE = 74,                             // SIZE
        S_REMOVE = 75,                           // REMOVE
        S_IF = 76,                               // IF
        S_ELSEIF_LIST = 77,                      // ELSEIF_LIST
        S_ELSEIF = 78,                           // ELSEIF
        S_ELSE = 79,                             // ELSE
        S_WHILE = 80,                            // WHILE
        S_FOR = 81,                              // FOR
        S_EXPRESSION = 82,                       // EXPRESSION
        S_DECLARE_STRUCT = 83,                   // DECLARE_STRUCT
        S_DECLARE_LIST = 84,                     // DECLARE_LIST
        S_CREATE_STRUCT = 85,                    // CREATE_STRUCT
        S_EXP_LIST = 86,                         // EXP_LIST
        S_DECLARATION = 87,                      // DECLARATION
        S_ASSIGNATION = 88,                      // ASSIGNATION
        S_BREAK = 89,                            // BREAK
        S_CONTINUE = 90,                         // CONTINUE
        S_RETURN = 91,                           // RETURN
        S_MEAN = 92,                             // MEAN
        S_MEDIAN = 93,                           // MEDIAN
        S_MODE = 94,                             // MODE
        S_TYPES = 95,                            // TYPES
        S_EXP = 96,                              // EXP
        S_ATOI = 97,                             // ATOI
        S_ATOF = 98,                             // ATOF
        S_IOTA = 99,                             // IOTA
        S_INCREMENT = 100,                       // INCREMENT
        S_PRIMITIVE = 101,                       // PRIMITIVE
        S_LIST_ARR = 102,                        // LIST_ARR
        S_STRUCT_ACCESS = 103,                   // STRUCT_ACCESS
        S_DECLARE_VECTOR = 104,                  // DECLARE_VECTOR
        S_DECLARE_MATRIX = 105,                  // DECLARE_MATRIX
        S_CALL_EXP = 106,                        // CALL_EXP
        S_CALL_INST = 107                        // CALL_INST
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (std::move (that.value));
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
        value.move< expression* > (std::move (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (std::move (that.value));
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
        value.move< instruction* > (std::move (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (std::move (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (std::move (that.value));
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.move< map_struct_dec* > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, TipoDato&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const TipoDato& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, func_main*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const func_main*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, instruction*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const instruction*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, list_expression*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const list_expression*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, list_instruction*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const list_instruction*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, map_struct_dec*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const map_struct_dec*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_TYPES: // TYPES
        value.template destroy< TipoDato > ();
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
        value.template destroy< expression* > ();
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.template destroy< func_main* > ();
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
        value.template destroy< instruction* > ();
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.template destroy< list_expression* > ();
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.template destroy< list_instruction* > ();
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.template destroy< map_struct_dec* > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    Parser (void *scanner_yyarg, yy::location& loc_yyarg, class OCL2Calc::ParserCtx & ctx_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERO (std::string v, location_type l)
      {
        return symbol_type (token::NUMERO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMERO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMERO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TSTRING (std::string v, location_type l)
      {
        return symbol_type (token::TSTRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TSTRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TSTRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (std::string v, location_type l)
      {
        return symbol_type (token::BOOLEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOLEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RSTRUCT (std::string v, location_type l)
      {
        return symbol_type (token::RSTRUCT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RSTRUCT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RSTRUCT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RVECTOR (std::string v, location_type l)
      {
        return symbol_type (token::RVECTOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RVECTOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RVECTOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLTRUE (std::string v, location_type l)
      {
        return symbol_type (token::BOOLTRUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLTRUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOLTRUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLFALSE (std::string v, location_type l)
      {
        return symbol_type (token::BOOLFALSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOLFALSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOLFALSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARA (std::string v, location_type l)
      {
        return symbol_type (token::PARA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PARA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PARA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARC (std::string v, location_type l)
      {
        return symbol_type (token::PARC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PARC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PARC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LLAVA (std::string v, location_type l)
      {
        return symbol_type (token::LLAVA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LLAVA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LLAVA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LLAVC (std::string v, location_type l)
      {
        return symbol_type (token::LLAVC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LLAVC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LLAVC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORA (std::string v, location_type l)
      {
        return symbol_type (token::CORA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CORA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CORA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CORC (std::string v, location_type l)
      {
        return symbol_type (token::CORC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CORC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::CORC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v, location_type l)
      {
        return symbol_type (token::VOID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VOID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMAIN (std::string v, location_type l)
      {
        return symbol_type (token::RMAIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMAIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMAIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NLL (std::string v, location_type l)
      {
        return symbol_type (token::NLL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NLL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NLL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUMA (std::string v, location_type l)
      {
        return symbol_type (token::SUMA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SUMA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::SUMA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOS (std::string v, location_type l)
      {
        return symbol_type (token::MENOS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MENOS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MENOS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_POR (std::string v, location_type l)
      {
        return symbol_type (token::POR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_POR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::POR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v, location_type l)
      {
        return symbol_type (token::DIV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DIV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INC (std::string v, location_type l)
      {
        return symbol_type (token::INC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (std::string v, location_type l)
      {
        return symbol_type (token::MOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIF (std::string v, location_type l)
      {
        return symbol_type (token::RIF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RIF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RELSE (std::string v, location_type l)
      {
        return symbol_type (token::RELSE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RELSE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RELSE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RWHILE (std::string v, location_type l)
      {
        return symbol_type (token::RWHILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RWHILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RWHILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RFOR (std::string v, location_type l)
      {
        return symbol_type (token::RFOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RFOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RFOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTF (std::string v, location_type l)
      {
        return symbol_type (token::PRINTF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::PRINTF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMEAN (std::string v, location_type l)
      {
        return symbol_type (token::RMEAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMEAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMEAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMEDIAN (std::string v, location_type l)
      {
        return symbol_type (token::RMEDIAN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMEDIAN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMEDIAN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMODE (std::string v, location_type l)
      {
        return symbol_type (token::RMODE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMODE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RMODE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RATOI (std::string v, location_type l)
      {
        return symbol_type (token::RATOI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RATOI (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RATOI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RATOF (std::string v, location_type l)
      {
        return symbol_type (token::RATOF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RATOF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RATOF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIOTA (std::string v, location_type l)
      {
        return symbol_type (token::RIOTA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RIOTA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RIOTA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBREAK (std::string v, location_type l)
      {
        return symbol_type (token::RBREAK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBREAK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBREAK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCONTINUE (std::string v, location_type l)
      {
        return symbol_type (token::RCONTINUE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCONTINUE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RCONTINUE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RRETURN (std::string v, location_type l)
      {
        return symbol_type (token::RRETURN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RRETURN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RRETURN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAYOR (std::string v, location_type l)
      {
        return symbol_type (token::MAYOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAYOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MAYOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR (std::string v, location_type l)
      {
        return symbol_type (token::MENOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MENOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MENOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAYEQU (std::string v, location_type l)
      {
        return symbol_type (token::MAYEQU, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MAYEQU (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MAYEQU, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENEQU (std::string v, location_type l)
      {
        return symbol_type (token::MENEQU, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MENEQU (const std::string& v, const location_type& l)
      {
        return symbol_type (token::MENEQU, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQU (std::string v, location_type l)
      {
        return symbol_type (token::EQU, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQU (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EQU, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIFF (std::string v, location_type l)
      {
        return symbol_type (token::DIFF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DIFF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DIFF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v, location_type l)
      {
        return symbol_type (token::AND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::AND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v, location_type l)
      {
        return symbol_type (token::OR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::OR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v, location_type l)
      {
        return symbol_type (token::NOT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NOT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VPBACK (std::string v, location_type l)
      {
        return symbol_type (token::VPBACK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VPBACK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VPBACK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VGET (std::string v, location_type l)
      {
        return symbol_type (token::VGET, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VGET (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VGET, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VREMOVE (std::string v, location_type l)
      {
        return symbol_type (token::VREMOVE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VREMOVE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VREMOVE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VSIZE (std::string v, location_type l)
      {
        return symbol_type (token::VSIZE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VSIZE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VSIZE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VPFRONT (std::string v, location_type l)
      {
        return symbol_type (token::VPFRONT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_VPFRONT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::VPFRONT, v, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const unsigned char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 1296,     ///< Last index in yytable_.
      yynnts_ = 47,  ///< Number of nonterminal symbols.
      yyfinal_ = 18 ///< Termination state number.
    };


    // User arguments.
    void *scanner;
    yy::location& loc;
    class OCL2Calc::ParserCtx & ctx;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    59,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,    58,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
    };
    // Last valid token kind.
    const int code_max = 311;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.copy< TipoDato > (YY_MOVE (that.value));
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
        value.copy< expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.copy< func_main* > (YY_MOVE (that.value));
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
        value.copy< instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.copy< list_expression* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.copy< list_instruction* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.copy< map_struct_dec* > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_TYPES: // TYPES
        value.move< TipoDato > (YY_MOVE (s.value));
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
        value.move< expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_START: // START
      case symbol_kind::S_MAIN: // MAIN
        value.move< func_main* > (YY_MOVE (s.value));
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
        value.move< instruction* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_EXP_LIST: // EXP_LIST
        value.move< list_expression* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_LIST_FUNC: // LIST_FUNC
      case symbol_kind::S_LIST_STRUCT: // LIST_STRUCT
      case symbol_kind::S_LIST_INST: // LIST_INST
      case symbol_kind::S_ELSEIF_LIST: // ELSEIF_LIST
      case symbol_kind::S_ELSE: // ELSE
        value.move< list_instruction* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_FUNCTION_LIST: // FUNCTION_LIST
      case symbol_kind::S_DECLARE_LIST: // DECLARE_LIST
        value.move< map_struct_dec* > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2947 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
