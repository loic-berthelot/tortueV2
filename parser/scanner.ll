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


fin return token::END;

"avance" {
    return token::AVANCE;
}

"recule" {
    return token::RECULE;
}

"sauter" {
    return token::SAUTER;
}
"tourner" {
    return token::TOURNER;
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
    
    yylval->build<int>(std::atoi(yytext));
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

%%
