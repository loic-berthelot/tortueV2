%skeleton "lalr1.cc"
%require "3.0"

%defines
%define parser_class_name { Parser }
%define api.value.type variant
%define parse.assert

%locations

%code requires{
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
    bool finpgrm = false;
}

%token                  AVANCE
%token                  RECULE
%token                  SAUTE
%token                  TOURNE
%token <int>            SENS
%token <int>            IdTortue
%token <std::string>    PARAM
%token <int>            DIRECTION
%token                  NL
%token                  END
%token                  SI
%token                  SINON
%token                  DOUBLEPOINT
%token                  FONCTION
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
%token                  END_OF_FILE
%token                  PAS_DE

%type <std::vector<double>> parametres
%type                   comment
%type                   fois
%type <ExpressionPtr>   expression
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
    FONCTION ID DOUBLEPOINT comment NL instruction END FONCTION comment NL {
        fonctions[$2]= $6;
    } programme
    | comment NL {
    } programme
    | END_OF_FILE {
        if (! finpgrm && fonctions["main"]) fonctions["main"]->parcourir(driver);
        finpgrm = true;
        YYACCEPT;
    }

instruction :
    instruction comment NL
    | comment NL instruction {
        $$ = $3;
    }
    | comment NL {
        $$ = nullptr;
    }
    | SI verification comment NL instruction SINON DOUBLEPOINT comment NL instruction END SI {
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($5);
        res->ajouterFils($10);
        $$ = res;
    }
    | SI verification comment NL instruction END SI{
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($5);
        $$ = res;
    }
    | TANTQUE verification comment NL instruction END TANTQUE{
        auto res = std::make_shared<TantQue>($2);
        res->ajouterFils($5);
        $$ = res;
    }
    | REPETE expression DOUBLEPOINT comment NL instruction END REPETE{
        auto res = std::make_shared<Repete>($2);
        res->ajouterFils($6);
        $$ = res;
    }
    | SI verification comment NL instruction END SI{
        auto res = std::make_shared<Si>($2);
        res->ajouterFils($5);
        $$ = res;
    }
    | instruction NL instruction {
        $$ = std::make_shared<Bloc>($1, $3);
    }
    | ID parametres {
        $$ = std::make_shared<Fonction> ($1, $2);
    }
    | action

parametres :
    parametres expression  {
        $1.push_back($2->calculer(driver.getContexte()));
        $$ = $1;
    }
    | {
        std::vector<double> v;
        $$ = v;
    }

action :
    AVANCE expression selection {
        $$ = std::make_shared<Action>("avance", $2, $3);
    }
    | RECULE expression selection {
        ExpressionPtr inverse = std::make_shared<ExpressionBinaire>(std::make_shared<Constante>(0), $2, OperateurBinaire::moins);
        $$ = std::make_shared<Action>("avance", inverse, $3);
    }
    | SAUTE expression selection {        
        $$ = std::make_shared<Action>("saute", $2, $3);
    }
    | TOURNE SENS expression selection {
        $$ = std::make_shared<Action>("tourne", $2, $4, $3);
    }
    | MODIF_COULEUR mode COULEUR selection {
        $$ = std::make_shared<Action>("couleur", $4, $2, $3);
    }
    | TORTUES operation NL{
        $$ = std::make_shared<Action>("tortues", $2);
    }
    | JARDIN CHEMIN_JARDIN{
        $$ = std::make_shared<Action>("jardin", $2);
    }

verification:
    CONDITION SENS selection DOUBLEPOINT{
        $$ = std::make_shared<Verification>($1, $2, $3);
    }
    | PAS_DE CONDITION SENS selection DOUBLEPOINT{
        $$ = std::make_shared<Verification>(($2+1)%2, $3, $4);
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
        $$ = $1;
    }
    | {
        $$ = std::make_shared<Constante>(1);
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
    | PARAM {
        $$ = std::make_shared<Variable>($1);
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