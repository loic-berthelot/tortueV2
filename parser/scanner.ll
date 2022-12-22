%{

#include "scanner.hh"
#include <cstdlib>

#define YY_NO_UNISTD_H

using token = yy::Parser::token;

#undef  YY_DECL
#define YY_DECL int Scanner::yylex( yy::Parser::semantic_type * const lval, yy::Parser::location_type *loc )

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option c++
%option yyclass="Scanner"
%option noyywrap

%%

%{
    yylval = lval;
%}


"fin" {
    return token::END;
}

--.* {
    return token::COMMENT;
}

"si" {
    return token::SI;
}

"sinon" {
    return token::SINON;
}

"repete" {
    return token::REPETE;
}

"tant que" {
    return token::TANTQUE;
}

":" {
    return token::DOUBLEPOINT;
}

"fonction" {
    return token::FONCTION;
}

"main" {
    return token::MAIN;
}

"mur" {
    yylval->build<int>(1);
    return token::CONDITION;
}

"vide" {
    yylval->build<int>(0);
    return token::CONDITION;
}

"avance" {
    return token::AVANCE;
}

"recule" {
    return token::RECULE;
}

"saute" {
    return token::SAUTE;
}

"tourne" {
    return token::TOURNE;
}

"tortues" {
    return token::TORTUES;
}

"jardin" {
    return token::JARDIN;
}

"couleur" {
    return token::MODIF_COULEUR;
}

"carapace" {
    yylval->build<int>(0);
    return token::MODE_COULEUR;
}

"motif" {
    yylval->build<int>(1);
    return token::MODE_COULEUR;
}

#[AaBbCcDdEeFf0-9]{6} {
    yylval->build<std::string>(yytext);
    return token::COULEUR;
}

[A-Za-z/0-9\.]*\.txt {
    yylval->build<std::string>(yytext);
    return token::CHEMIN_JARDIN;   
}

"devant" {
    yylval->build<int>(0);
    return token::SENS;
}

"derriere" {
    yylval->build<int>(2);
    return token::SENS;
}

"à droite" {
    yylval->build<int>(1);
    return token::SENS;
}

"à gauche" {
    yylval->build<int>(-1);
    return token::SENS;
}

[0-9]+      {    
    yylval->build<float>(std::atof(yytext));
    return token::NUMBER;
}

@[0-9]+   {
    std::string temp = YYText();
    yylval->build<int>(std::stoi(temp.substr(1)));
    return token::IdTortue;
}

"\n"          {
    loc->lines();
    return token::NL;
}


"+" return '+';
"*" return '*';
"-" return '-';
"/" return '/';
"(" return '(';
")" return ')';
"=" return '=';

"fois" return token::FOIS;

[a-z][a-zA-Z0-9]*    {
    yylval->build<std::string>(YYText());
    return token::ID;
}

%%
