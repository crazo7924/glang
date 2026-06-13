%{
#include "ast.hh"
#include "parser.hh"
#include <string>
#include <iostream>

#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
%}

%option noyywrap
%option yylineno

%%

[ \t\r]                   ; // Ignore whitespace and carriage returns
\n                        return T_DELIMITER;
";"                       return T_DELIMITER;

"//"                      { char c; while((c = yyinput()) != '\n' && c != EOF); if(c == '\n') unput(c); }
"/*"                      { char c, next; while((c = yyinput()) != EOF) { if(c == '*') { next = yyinput(); if(next == '/') break; else unput(next); } } }

"int"                     return T_TYPE_INT;
"float"                   return T_TYPE_FLOAT;
"if"                      return T_IF;
"else"                    return T_ELSE;
"while"                   return T_WHILE;
"return"                  return T_RETURN;

[a-zA-Z_][a-zA-Z0-9_]*    SAVE_TOKEN; return T_IDENTIFIER;
[0-9]+\.[0-9]*            SAVE_TOKEN; return T_FLOAT;
[0-9]+                    SAVE_TOKEN; return T_INTEGER;
\"[^\"\n]*\"              { SAVE_TOKEN; return T_STRING; }
"="                       return T_ASSIGN;
"=="                      return T_EQ;
"!="                      return T_NEQ;
"<"                       return T_LT;
"<="                      return T_LTE;
">"                       return T_GT;
">="                      return T_GTE;
"+"                       return T_PLUS;
"-"                       return T_MINUS;
"*"                       return T_MUL;
"/"                       return T_DIV;
"("                       return T_LPAREN;
")"                       return T_RPAREN;
"{"                       return T_LBRACE;
"}"                       return T_RBRACE;
","                       return T_COMMA;

.                         { std::cerr << "Unknown token: " << yytext << std::endl; yyterminate(); }

%%
