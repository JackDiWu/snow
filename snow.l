%{

#include "snow.yy.h"

#define lex_set_lineno(n)          yyset_lineno(n, yyscanner)

#define lex_set_column(n)          yyset_column(n, yyscanner)

#define lex_next_lineno()          yyset_lineno(yyget_lineno(yyscanner) + 1, yyscanner)

#define lex_next_column()          yyset_column(yyget_column(yyscanner) + 1, yyscanner)

#define lex_return(t)              return t

%}

%option reentrant noyywrap bison-bridge

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

[_a-zA-Z0-9]+                { lex_next_column(); lex_return(TOKEN_WORD); }

[0-9]+                       { lex_next_column(); lex_return(TOKEN_DEC); }

0x[0-9a-fA-F]+               { lex_next_column(); lex_return(TOKEN_HEX); }

[0-9]+\.[0-9]+               { lex_next_column(); lex_return(TOKEN_FLOAT); }

\"([^\\\"]|\\.)*\"           { lex_next_column(); lex_return(TOKEN_STRING); }

(\ |\t)                      {}

(\r\n|\n)                    { lex_next_lineno(); lex_set_column(0); }

.                            { lex_return(TOKEN_UNKNOW); }

%%