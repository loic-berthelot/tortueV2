// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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





#include "parser.hh"


// Unqualified %code blocks.
#line 21 "../parser/parser.yy"

    #include <iostream>
    #include <string>
    #include <map>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
    bool finpgrm = false;

#line 59 "parser.cc"


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
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
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
#line 151 "parser.cc"

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}

   Parser ::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.copy< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.copy< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parametres: // parametres
        value.copy< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
   Parser ::symbol_kind_type
   Parser ::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
   Parser ::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parametres: // parametres
        value.move< std::vector<double> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
   Parser ::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
   Parser ::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

   Parser ::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

   Parser ::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
   Parser ::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
   Parser ::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

   Parser ::symbol_kind_type
   Parser ::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
   Parser ::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

   Parser ::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
   Parser ::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

   Parser ::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

   Parser ::symbol_kind_type
   Parser ::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

   Parser ::stack_symbol_type::stack_symbol_type ()
  {}

   Parser ::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.YY_MOVE_OR_COPY< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.YY_MOVE_OR_COPY< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.YY_MOVE_OR_COPY< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parametres: // parametres
        value.YY_MOVE_OR_COPY< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

   Parser ::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parametres: // parametres
        value.move< std::vector<double> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.copy< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.copy< InstPtr > (that.value);
        break;

      case symbol_kind::S_verification: // verification
        value.copy< VerifPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_parametres: // parametres
        value.copy< std::vector<double> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        value.move< ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        value.move< InstPtr > (that.value);
        break;

      case symbol_kind::S_verification: // verification
        value.move< VerifPtr > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< float > (that.value);
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        value.move< int > (that.value);
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_parametres: // parametres
        value.move< std::vector<double> > (that.value);
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
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
   Parser ::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
   Parser ::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
   Parser ::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

   Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::operator() ()
  {
    return parse ();
  }

  int
   Parser ::parse ()
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
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
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_operation: // operation
        yylhs.value.emplace< ExpressionPtr > ();
        break;

      case symbol_kind::S_instruction: // instruction
      case symbol_kind::S_action: // action
        yylhs.value.emplace< InstPtr > ();
        break;

      case symbol_kind::S_verification: // verification
        yylhs.value.emplace< VerifPtr > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_SENS: // SENS
      case symbol_kind::S_IdTortue: // IdTortue
      case symbol_kind::S_DIRECTION: // DIRECTION
      case symbol_kind::S_CONDITION: // CONDITION
      case symbol_kind::S_MODE_COULEUR: // MODE_COULEUR
      case symbol_kind::S_mode: // mode
      case symbol_kind::S_selection: // selection
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_COULEUR: // COULEUR
      case symbol_kind::S_CHEMIN_JARDIN: // CHEMIN_JARDIN
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_parametres: // parametres
        yylhs.value.emplace< std::vector<double> > ();
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
  case 2: // $@1: %empty
#line 83 "../parser/parser.yy"
                                                                           {
        fonctions[yystack_[8].value.as < std::string > ()]= yystack_[4].value.as < InstPtr > ();
    }
#line 910 "parser.cc"
    break;

  case 4: // $@2: %empty
#line 86 "../parser/parser.yy"
                 {
    }
#line 917 "parser.cc"
    break;

  case 6: // programme: END_OF_FILE
#line 88 "../parser/parser.yy"
                  {
        if (! finpgrm && fonctions["main"]) fonctions["main"]->parcourir(driver);
        finpgrm = true;
        YYACCEPT;
    }
#line 927 "parser.cc"
    break;

  case 7: // instruction: instruction comment NL
#line 95 "../parser/parser.yy"
    { yylhs.value.as < InstPtr > () = yystack_[2].value.as < InstPtr > (); }
#line 933 "parser.cc"
    break;

  case 8: // instruction: comment NL instruction
#line 96 "../parser/parser.yy"
                             {
        yylhs.value.as < InstPtr > () = yystack_[0].value.as < InstPtr > ();
    }
#line 941 "parser.cc"
    break;

  case 9: // instruction: comment NL
#line 99 "../parser/parser.yy"
                 {
        yylhs.value.as < InstPtr > () = nullptr;
    }
#line 949 "parser.cc"
    break;

  case 10: // instruction: SI verification comment NL instruction SINON DOUBLEPOINT comment NL instruction END SI
#line 102 "../parser/parser.yy"
                                                                                             {
        auto res = std::make_shared<Si>(yystack_[10].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[7].value.as < InstPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 960 "parser.cc"
    break;

  case 11: // instruction: SI verification comment NL instruction END SI
#line 108 "../parser/parser.yy"
                                                   {
        auto res = std::make_shared<Si>(yystack_[5].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 970 "parser.cc"
    break;

  case 12: // instruction: TANTQUE verification comment NL instruction END TANTQUE
#line 113 "../parser/parser.yy"
                                                             {
        auto res = std::make_shared<TantQue>(yystack_[5].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 980 "parser.cc"
    break;

  case 13: // instruction: REPETE expression DOUBLEPOINT comment NL instruction END REPETE
#line 118 "../parser/parser.yy"
                                                                     {
        auto res = std::make_shared<Repete>(yystack_[6].value.as < ExpressionPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 990 "parser.cc"
    break;

  case 14: // instruction: SI verification comment NL instruction END SI
#line 123 "../parser/parser.yy"
                                                   {
        auto res = std::make_shared<Si>(yystack_[5].value.as < VerifPtr > ());
        res->ajouterFils(yystack_[2].value.as < InstPtr > ());
        yylhs.value.as < InstPtr > () = res;
    }
#line 1000 "parser.cc"
    break;

  case 15: // instruction: instruction NL instruction
#line 128 "../parser/parser.yy"
                                 {
        yylhs.value.as < InstPtr > () = std::make_shared<Bloc>(yystack_[2].value.as < InstPtr > (), yystack_[0].value.as < InstPtr > ());
    }
#line 1008 "parser.cc"
    break;

  case 16: // instruction: ID parametres
#line 131 "../parser/parser.yy"
                    {
        yylhs.value.as < InstPtr > () = std::make_shared<Fonction> (yystack_[1].value.as < std::string > (), yystack_[0].value.as < std::vector<double> > ());
    }
#line 1016 "parser.cc"
    break;

  case 17: // instruction: action
#line 134 "../parser/parser.yy"
      { yylhs.value.as < InstPtr > () = yystack_[0].value.as < InstPtr > (); }
#line 1022 "parser.cc"
    break;

  case 18: // parametres: parametres expression
#line 137 "../parser/parser.yy"
                           {
        yystack_[1].value.as < std::vector<double> > ().push_back(yystack_[0].value.as < ExpressionPtr > ()->calculer(driver.getContexte()));
        yylhs.value.as < std::vector<double> > () = yystack_[1].value.as < std::vector<double> > ();
    }
#line 1031 "parser.cc"
    break;

  case 19: // parametres: %empty
#line 141 "../parser/parser.yy"
      {
        std::vector<double> v;
        yylhs.value.as < std::vector<double> > () = v;
    }
#line 1040 "parser.cc"
    break;

  case 20: // action: AVANCE expression selection
#line 147 "../parser/parser.yy"
                                {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("avance", yystack_[1].value.as < ExpressionPtr > (), yystack_[0].value.as < int > ());
    }
#line 1048 "parser.cc"
    break;

  case 21: // action: RECULE expression selection
#line 150 "../parser/parser.yy"
                                  {
        ExpressionPtr inverse = std::make_shared<ExpressionBinaire>(std::make_shared<Constante>(0), yystack_[1].value.as < ExpressionPtr > (), OperateurBinaire::moins);
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("avance", inverse, yystack_[0].value.as < int > ());
    }
#line 1057 "parser.cc"
    break;

  case 22: // action: SAUTE expression selection
#line 154 "../parser/parser.yy"
                                 {        
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("saute", yystack_[1].value.as < ExpressionPtr > (), yystack_[0].value.as < int > ());
    }
#line 1065 "parser.cc"
    break;

  case 23: // action: TOURNE SENS expression selection
#line 157 "../parser/parser.yy"
                                       {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("tourne", yystack_[2].value.as < int > (), yystack_[0].value.as < int > (), yystack_[1].value.as < ExpressionPtr > ());
    }
#line 1073 "parser.cc"
    break;

  case 24: // action: MODIF_COULEUR mode COULEUR selection
#line 160 "../parser/parser.yy"
                                           {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("couleur", yystack_[0].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < std::string > ());
    }
#line 1081 "parser.cc"
    break;

  case 25: // action: TORTUES operation NL
#line 163 "../parser/parser.yy"
                          {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("tortues", yystack_[1].value.as < ExpressionPtr > ());
    }
#line 1089 "parser.cc"
    break;

  case 26: // action: JARDIN CHEMIN_JARDIN
#line 166 "../parser/parser.yy"
                          {
        yylhs.value.as < InstPtr > () = std::make_shared<Action>("jardin", yystack_[0].value.as < std::string > ());
    }
#line 1097 "parser.cc"
    break;

  case 27: // verification: CONDITION SENS selection DOUBLEPOINT
#line 171 "../parser/parser.yy"
                                        {
        yylhs.value.as < VerifPtr > () = std::make_shared<Verification>(yystack_[3].value.as < int > (), yystack_[2].value.as < int > (), yystack_[1].value.as < int > ());
    }
#line 1105 "parser.cc"
    break;

  case 28: // verification: PAS_DE CONDITION SENS selection DOUBLEPOINT
#line 174 "../parser/parser.yy"
                                                 {
        yylhs.value.as < VerifPtr > () = std::make_shared<Verification>((yystack_[3].value.as < int > ()+1)%2, yystack_[2].value.as < int > (), yystack_[1].value.as < int > ());
    }
#line 1113 "parser.cc"
    break;

  case 29: // mode: MODE_COULEUR
#line 180 "../parser/parser.yy"
                 {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1121 "parser.cc"
    break;

  case 30: // mode: %empty
#line 183 "../parser/parser.yy"
      {
        yylhs.value.as < int > () = 0;
    }
#line 1129 "parser.cc"
    break;

  case 31: // expression: operation fois
#line 188 "../parser/parser.yy"
                   {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1137 "parser.cc"
    break;

  case 32: // expression: %empty
#line 191 "../parser/parser.yy"
      {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(1);
    }
#line 1145 "parser.cc"
    break;

  case 34: // comment: %empty
#line 197 "../parser/parser.yy"
      {}
#line 1151 "parser.cc"
    break;

  case 35: // fois: FOIS
#line 200 "../parser/parser.yy"
         {}
#line 1157 "parser.cc"
    break;

  case 36: // fois: %empty
#line 201 "../parser/parser.yy"
      {}
#line 1163 "parser.cc"
    break;

  case 37: // selection: IdTortue
#line 204 "../parser/parser.yy"
             {
        yylhs.value.as < int > () = yystack_[0].value.as < int > ();
    }
#line 1171 "parser.cc"
    break;

  case 38: // selection: %empty
#line 207 "../parser/parser.yy"
      {
        yylhs.value.as < int > () = -1;
    }
#line 1179 "parser.cc"
    break;

  case 39: // operation: NUMBER
#line 212 "../parser/parser.yy"
          {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Constante>(yystack_[0].value.as < float > ());
    }
#line 1187 "parser.cc"
    break;

  case 40: // operation: PARAM
#line 215 "../parser/parser.yy"
            {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<Variable>(yystack_[0].value.as < std::string > ());
    }
#line 1195 "parser.cc"
    break;

  case 41: // operation: '(' operation ')'
#line 218 "../parser/parser.yy"
                        {
        yylhs.value.as < ExpressionPtr > () = yystack_[1].value.as < ExpressionPtr > ();
    }
#line 1203 "parser.cc"
    break;

  case 42: // operation: operation '+' operation
#line 221 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::plus);
    }
#line 1211 "parser.cc"
    break;

  case 43: // operation: operation '-' operation
#line 224 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::moins);
    }
#line 1219 "parser.cc"
    break;

  case 44: // operation: operation '*' operation
#line 227 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::multiplie);
    }
#line 1227 "parser.cc"
    break;

  case 45: // operation: operation '/' operation
#line 230 "../parser/parser.yy"
                              {
        if (yystack_[0].value.as < ExpressionPtr > () == 0) {
            std::cerr << "division par 0\n";
            YYACCEPT;
        }
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionBinaire>(yystack_[2].value.as < ExpressionPtr > (), yystack_[0].value.as < ExpressionPtr > (), OperateurBinaire::divise);
    }
#line 1239 "parser.cc"
    break;

  case 46: // operation: '-' operation
#line 237 "../parser/parser.yy"
                              {
        yylhs.value.as < ExpressionPtr > () = std::make_shared<ExpressionUnaire>(yystack_[0].value.as < ExpressionPtr > (), OperateurUnaire::neg);
    }
#line 1247 "parser.cc"
    break;


#line 1251 "parser.cc"

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
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
   Parser ::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char  Parser ::yypact_ninf_ = -43;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
      33,    -8,   -43,   -43,     6,    21,    25,   -43,   -43,    31,
      33,    43,   -43,    54,    -5,    -5,    -5,    10,    78,   -43,
      78,    -5,    28,    -5,    37,     4,   -43,    66,   -43,   -43,
      -5,    -5,    81,   -14,    81,    81,    -5,    75,    64,    31,
      -5,    31,    88,   -43,    63,    27,   -43,    54,    90,    93,
      54,   -43,    79,   -43,   -43,   -43,    -5,    -5,    -5,    -5,
     -43,   -43,   -43,    81,    81,   100,    99,   -43,   101,    31,
      81,   -43,     2,    31,   -43,     2,   -43,    -1,    -1,   -43,
     -43,   -43,   102,    81,    54,    54,   107,   -43,   109,   -43,
     106,    74,    59,    54,   -43,   -43,   110,   111,    98,    83,
      33,   -43,    31,   -43,   103,   -43,   113,   -43,    54,    86,
     112,   -43
  };

  const signed char
   Parser ::yydefact_[] =
  {
      34,     0,    33,     6,     0,     0,     0,     1,     4,    34,
      34,     0,     5,    34,    32,    32,    32,     0,     0,    19,
       0,    32,    30,     0,     0,     0,    17,     0,    40,    39,
       0,     0,    38,    36,    38,    38,    32,     0,     0,    34,
      16,    34,     0,    29,     0,     0,    26,    34,     0,     0,
       9,    46,     0,    37,    20,    35,     0,     0,     0,     0,
      31,    21,    22,    38,    38,     0,     0,    18,     0,    34,
      38,    25,    15,    34,     7,     8,    41,    43,    42,    44,
      45,    23,     0,    38,    34,    34,     0,    24,     0,    27,
       0,     0,     0,    34,     2,    28,     0,     0,     0,     0,
      34,    11,    34,    12,     0,     3,     0,    13,    34,     0,
       0,    10
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -43,    -7,   -43,   -43,   -42,   -43,   -43,   114,   -43,    12,
       0,   -43,   -33,   -12
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
       0,     4,   100,    10,    25,    40,    26,    39,    44,    32,
      27,    60,    54,    33
  };

  const signed char
   Parser ::yytable_[] =
  {
       5,    61,    62,    12,    28,    72,     7,    55,    75,    11,
       5,    45,     6,    47,    29,    47,    48,    36,    51,    52,
      56,    57,    58,    59,     2,    49,     2,    34,    35,    30,
      81,    82,     8,    42,    31,    58,    59,    87,    71,    66,
       9,    68,    91,    92,    77,    78,    79,    80,    63,     1,
      90,    99,    67,     2,    13,     2,    43,    14,    15,    16,
      17,    56,    57,    58,    59,     3,   109,    18,    46,    86,
      47,    98,    49,    88,    19,    49,     2,    50,    20,    21,
      22,     2,    64,    23,    24,    47,    96,    65,    97,    53,
      70,    49,    49,   105,    47,   104,     2,    47,   110,    49,
       5,    37,   106,    69,    74,     2,    73,    83,     2,    49,
      84,    38,    85,    56,    57,    58,    59,    89,    93,    76,
      94,    95,   103,   101,   108,   111,   102,     0,   107,     0,
       0,     0,     0,     0,    41
  };

  const signed char
   Parser ::yycheck_[] =
  {
       0,    34,    35,    10,     9,    47,     0,    21,    50,     9,
      10,    23,    20,    11,    19,    11,    12,     7,    30,    31,
      34,    35,    36,    37,    22,    25,    22,    15,    16,    34,
      63,    64,    11,    21,    39,    36,    37,    70,    11,    39,
      15,    41,    84,    85,    56,    57,    58,    59,    36,    16,
      83,    93,    40,    22,    11,    22,    28,     3,     4,     5,
       6,    34,    35,    36,    37,    32,   108,    13,    31,    69,
      11,    12,    72,    73,    20,    75,    22,    11,    24,    25,
      26,    22,     7,    29,    30,    11,    12,    23,    14,     8,
      27,    91,    92,   100,    11,    12,    22,    11,    12,    99,
     100,    23,   102,    15,    11,    22,    16,     7,    22,   109,
      11,    33,    11,    34,    35,    36,    37,    15,    11,    40,
      11,    15,    24,    13,    11,    13,    15,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    20
  };

  const signed char
   Parser ::yystos_[] =
  {
       0,    16,    22,    32,    42,    51,    20,     0,    11,    15,
      44,    51,    42,    11,     3,     4,     5,     6,    13,    20,
      24,    25,    26,    29,    30,    45,    47,    51,     9,    19,
      34,    39,    50,    54,    50,    50,     7,    23,    33,    48,
      46,    48,    50,    28,    49,    54,    31,    11,    12,    51,
      11,    54,    54,     8,    53,    21,    34,    35,    36,    37,
      52,    53,    53,    50,     7,    23,    51,    50,    51,    15,
      27,    11,    45,    16,    11,    45,    40,    54,    54,    54,
      54,    53,    53,     7,    11,    11,    51,    53,    51,    15,
      53,    45,    45,    11,    11,    15,    12,    14,    12,    45,
      43,    13,    15,    24,    12,    42,    51,    25,    11,    45,
      12,    13
  };

  const signed char
   Parser ::yyr1_[] =
  {
       0,    41,    43,    42,    44,    42,    42,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    54,    54,    54,    54
  };

  const signed char
   Parser ::yyr2_[] =
  {
       0,     2,     0,    12,     0,     4,     1,     3,     3,     2,
      12,     7,     7,     8,     7,     3,     2,     1,     2,     0,
       3,     3,     3,     4,     4,     3,     2,     4,     5,     1,
       0,     2,     0,     1,     0,     1,     0,     1,     0,     1,
       1,     3,     3,     3,     3,     3,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "AVANCE", "RECULE",
  "SAUTE", "TOURNE", "SENS", "IdTortue", "PARAM", "DIRECTION", "NL", "END",
  "SI", "SINON", "DOUBLEPOINT", "FONCTION", "EGAL", "DIFFERENT", "NUMBER",
  "ID", "FOIS", "COMMENT", "CONDITION", "TANTQUE", "REPETE",
  "MODIF_COULEUR", "COULEUR", "MODE_COULEUR", "TORTUES", "JARDIN",
  "CHEMIN_JARDIN", "END_OF_FILE", "PAS_DE", "'-'", "'+'", "'*'", "'/'",
  "NEG", "'('", "')'", "$accept", "programme", "$@1", "$@2", "instruction",
  "parametres", "action", "verification", "mode", "expression", "comment",
  "fois", "selection", "operation", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
   Parser ::yyrline_[] =
  {
       0,    83,    83,    83,    86,    86,    88,    95,    96,    99,
     102,   108,   113,   118,   123,   128,   131,   134,   137,   141,
     147,   150,   154,   157,   160,   163,   166,   171,   174,   180,
     183,   188,   191,   196,   197,   200,   201,   204,   207,   212,
     215,   218,   221,   224,   227,   230,   237
  };

  void
   Parser ::yy_stack_print_ () const
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
   Parser ::yy_reduce_print_ (int yyrule) const
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

   Parser ::symbol_kind_type
   Parser ::yytranslate_ (int t)
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
      39,    40,    36,    35,     2,    34,     2,    37,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    38
    };
    // Last valid token kind.
    const int code_max = 289;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1676 "parser.cc"

#line 240 "../parser/parser.yy"


void yy::Parser::error(const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}
