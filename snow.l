%{

#include "snow.yy.h"

#define lex_set_line(n)            yyset_lineno(n, yyscanner)

#define lex_set_token(n)           yyset_column(n, yyscanner)

#define lex_next_line()            yyset_lineno(yyget_lineno(yyscanner) + 1, yyscanner)

#define lex_next_token()           yyset_column(yyget_column(yyscanner) + 1, yyscanner)

#define lex_return(t)              return t

%}

%option reentrant noyywrap bison-bridge

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

[0-9]+                       { lex_next_token(); lex_return(TOKEN_DEC); }

0x[0-9a-fA-F]+               { lex_next_token(); lex_return(TOKEN_HEX); }

[0-9]+\.[0-9]+               { lex_next_token(); lex_return(TOKEN_FLOAT); }

[_a-zA-Z0-9]+                { lex_next_token(); lex_return(TOKEN_WORD); }

\"([^\\\"]|\\.)*\"           { lex_next_token(); lex_return(TOKEN_STRING); }

\'([^\\\']|\\.)*\'           { lex_next_token(); lex_return(TOKEN_STRING); }

(\r\n|\n)                    { lex_next_line(); lex_set_token(0); }

(\ |\t)                      {}

\=                           { lex_next_token(); lex_return(TOKEN_EQUAL); }

\+                           { lex_next_token(); lex_return(TOKEN_PLUS); }

\-                           { lex_next_token(); lex_return(TOKEN_SUB); }

\*                           { lex_next_token(); lex_return(TOKEN_TIMES); }

\/                           { lex_next_token(); lex_return(TOKEN_DIVIDE); }

\(                           { lex_next_token(); lex_return(TOKEN_LP); }

\)                           { lex_next_token(); lex_return(TOKEN_RP); }

\[                           { lex_next_token(); lex_return(TOKEN_LS); }

\]                           { lex_next_token(); lex_return(TOKEN_RS); }

\{                           { lex_next_token(); lex_return(TOKEN_LC); }

\}                           { lex_next_token(); lex_return(TOKEN_RC); }

\<                           { lex_next_token(); lex_return(TOKEN_LA); }

\>                           { lex_next_token(); lex_return(TOKEN_RA); }

\.                           { lex_next_token(); lex_return(TOKEN_POINT); }

\&                           { lex_next_token(); lex_return(TOKEN_AND); }

\|                           { lex_next_token(); lex_return(TOKEN_OR); }

\?                           { lex_next_token(); lex_return(TOKEN_QUESTION); }

\~                           { lex_next_token(); lex_return(TOKEN_BROKEN_ISSUE); }

\!                           { lex_next_token(); lex_return(TOKEN_EXCLAMATION); }

\@                           { lex_next_token(); lex_return(TOKEN_AT); }

\#                           { lex_next_token(); lex_return(TOKEN_HASHTAG); }

\$                           { lex_next_token(); lex_return(TOKEN_DOLLAR); }

\%                           { lex_next_token(); lex_return(TOKEN_PERCENT); }

\^                           { lex_next_token(); lex_return(TOKEN_START); }

\:                           { lex_next_token(); lex_return(TOKEN_COLON); }

\;                           { lex_next_token(); lex_return(TOKEN_SEMICOLON); }

\\                           { lex_next_token(); lex_return(TOKEN_BACKSLASH); }

\=\=                         { lex_next_token(); lex_return(TOKEN_DOUBLE_EQUAL); }

\&\&                         { lex_next_token(); lex_return(TOKEN_DOUBLE_AND); }

\|\|                         { lex_next_token(); lex_return(TOKEN_DOUBLE_OR); }

\<\<                         { lex_next_token(); lex_return(TOKEN_DOUBLE_LA); }

\>\>                         { lex_next_token(); lex_return(TOKEN_DOUBLE_RA); }

\<\=                         { lex_next_token(); lex_return(TOKEN_LA_EQUAL); }

\>\=                         { lex_next_token(); lex_return(TOKEN_RA_EQUAL); }

.                            { lex_return(TOKEN_UNKNOW); }

%%