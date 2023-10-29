%{

#include "parse.yy.h"

%}

%option reentrant noyywrap bison-bridge

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

[_a-zA-Z][_a-zA-Z0-9]*       { return TOKEN_WORD; }

(\ |\t)                      {}

<<EOF>>		                 { return TOKEN_EOF; }

.                            { return TOKEN_UNKNOW; }

%%