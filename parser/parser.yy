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
    #include "structure.hh"

    class Scanner;
    class Driver;
}

%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%code{
    #include <iostream>
    #include <string>
    #include <map>

    #include "scanner.hh"
    #include "driver.hh"

    #undef  yylex
    #define yylex scanner.yylex

    std::map<std::string, InstPtr> fonctions;
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
%token                  SINON
%token                  DOUBLEPOINT
%token                  FONCTION
%token                  MAIN
%token                  EGAL
%token                  DIFFERENT
%token <float>          NUMBER
%token <std::string>    ID
%token                  FOIS
%token                  COMMENT
%token <int>            CONDITION
%token                  TANTQUE
%token                  REPETE
%token                  MODIF_COULEUR
%token <std::string>    COULEUR
%token <int>            MODE_COULEUR
%token                  TORTUES
%token                  JARDIN
%token <std::string>    CHEMIN_JARDIN

%type                   comment
%type                   fois
%type <int>             expression
%type <VerifPtr>        verification
%type <int>             selection
%type <int>             mode
%type <ExpressionPtr>   operation
%type <InstPtr>         action
%type <InstPtr>         instruction
%left '-' '+'
%left '*' '/'
%precedence  NEG

%%

programme:
    FONCTION MAIN DOUBLEPOINT NL instruction END FONCTION NL{
        $5->parcourir(driver);
        YYACCEPT;
    }
    | FONCTION ID DOUBLEPOINT NL instruction END FONCTION NL {
        fonctions[$2]= $5;
    } programme

instruction :
    instruction comment NL
    | SI verification NL instruction SINON NL instruction END SI {
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($4);
        res->ajouterFils($7);
        $$ = res;
    }
    | SI verification NL instruction END SI{
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($4);
        $$ = res;
    }
    | TANTQUE verification NL instruction END TANTQUE{
        auto res = std::make_shared<TantQue>($2);
        res->ajouterFils($4);
        $$ = res;
    }
    | REPETE expression DOUBLEPOINT NL instruction END REPETE{
        auto res = std::make_shared<Repete>($2);
        res->ajouterFils($5);
        $$ = res;
    }
    | SI verification NL instruction END SI{
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($4);
        $$ = res;
    }
    | action
    | instruction instruction {
        $$ = std::make_shared<Bloc>($1, $2);
    }
    | ID {
        $$ = fonctions[$1];
    }


action :
    AVANCE expression selection {
        $$ = std::make_shared<Action>("avance", $3, $2);
    }
    | RECULE expression selection {
        $$ = std::make_shared<Action>("avance", $3, -$2);
    }
    | SAUTE expression selection {        
        $$ = std::make_shared<Action>("saute", $3, 0);
    }
    | TOURNE SENS selection {
        $$ = std::make_shared<Action>("tourne", $3, $2);
    }
    | MODIF_COULEUR mode COULEUR selection {
        $$ = std::make_shared<Action>("couleur", $4, $2, $3);
    }
    | TORTUES expression NL{
        $$ = std::make_shared<Action>("tortues", $2);
    }
    | JARDIN CHEMIN_JARDIN{
        $$ = std::make_shared<Action>("jardin", 0, 0, $2);
    }

verification:
    CONDITION SENS selection DOUBLEPOINT{
        $$ = std::make_shared<Verification>($1, $2, $3);
    }

mode:
    MODE_COULEUR {
        $$ = $1;
    }
    | {
        $$ = 0;
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