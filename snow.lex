%{

#define TOKEN_UNKNOW             0
#define TOKEN_WORD               1

%}

%option reentrant noyywrap

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

[_a-zA-Z][_a-zA-Z0-9]*       { return TOKEN_WORD; }

(\ |\t)                      {}

.                            { return TOKEN_UNKNOW; }

%%