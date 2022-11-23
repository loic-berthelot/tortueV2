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

%token                  NL
%token                  END
%token <int>            NUMBER
%token                  AVANCE
%token                  RECULE
%token                  SAUTER
%token                  TOURNER
%token <int>            SENS
%token <int>            IdTortue

%%

programme:
    NUMBER NL {
        std::cout << "nombre : " << $1 << std::endl;
        driver.setVariable("a",$1);
        std::cout <<driver.getVariable("a") << std::endl;
    } programme
    | AVANCE NL IdTortue{
        driver.avancerTortue($3, 1);
    }
    | AVANCE NUMBER IdTortue{
        driver.avancerTortue($3, $2);
    } programme
    | RECULE NUMBER IdTortue{
        driver.avancerTortue($3, - $2);
    }
    | SAUTER NUMBER IdTortue{
        driver.sauter($3);
    }
    | TOURNER SENS IdTortue{
        driver.tourner($3, $2);
    }
    | END NL {
        YYACCEPT;
    }
    
%%

void yy::Parser::error( const location_type &l, const std::string & err_msg) {
    std::cerr << "Erreur : " << l << ", " << err_msg << std::endl;
}