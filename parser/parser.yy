%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
    #include "contexte.hh"
    #include "expressionBinaire.hh"
    #include "expressionUnaire.hh"
    #include "constante.hh"
    #include "variable.hh"
    
    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    
    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex
}

%token                  AVANCE
%token                  RECULE
%token                  SAUTE
%token                  TOURNE
%token <int>            SENS
%token <int>            IdTortue
%token <int>            DIRECTION

%token                  NL
%token                  END
%token                  SI
%token                  ALORS
%token                  SINON
%token                  EGAL
%token                  DIFFERENT
%token <float>          NUMBER
%token <std::string>    IDENT
%token                  FOIS
%token                  COMMENT
%token <int>            CONDITION

%type                   comment
%type                   fois
%type <int>             expression
%type <int>             selection
%type <ExpressionPtr>   operation
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

// on devrait mettre toutes les instructions dans un arbre et les exécuter seulement lorsque l'utilisateur met fin
programme:
    instruction comment NL programme
    | END {
        YYACCEPT;
    }

instruction :
    | SI CONDITION SENS {
        
    }
    | AVANCE expression selection {
        driver.avancerTortue($3, $2);
    }
    | RECULE expression selection {
        driver.avancerTortue($3, - $2);
    }
    | SAUTE expression selection {
        driver.sauter($3);
    }
    | TOURNE SENS selection {
        driver.tourner($3, $2);
    }

expression:
    operation fois {
        $$ = (int)$1->calculer(driver.getContexte());
    }
    | {
        $$ = 1;
    }

comment:
    COMMENT
    | {}

fois:
    FOIS {}
    | {}

selection:
    IdTortue {
        $$ = $1;
    }
    | {
        $$ = -1;
    }

operation:
    NUMBER{
        $$ = std::make_shared<Constante>($1);
    }
    | '(' operation ')' {
        $$ = $2;
    }
    | operation '+' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::plus);
    }
    | operation '-' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::moins);
    }
    | operation '*' operation {
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::multiplie);
    }
    | operation '/' operation {
        if ($3 == 0) {
            std::cerr << "division par 0\n";
            YYACCEPT;
        }
        $$ = std::make_shared<ExpressionBinaire>($1, $3, OperateurBinaire::divise);
    }
    | '-' operation %prec NEG {
        $$ = std::make_shared<ExpressionUnaire>($2, OperateurUnaire::neg);
    }
%%

void yy::Parser::error(const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}