%{

#include "snow.yy.h"

%}

%option reentrant noyywrap bison-bridge

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

[_a-zA-Z][_a-zA-Z0-9]*       { return TOKEN_WORD; }

(\ |\t)                      {}

(\r\n|\n)                    { yyset_column(0, yyscanner); yyset_lineno(yyget_lineno(yyscanner) + 1, yyscanner); }

.                            { return TOKEN_UNKNOW; }

%%