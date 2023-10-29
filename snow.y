%{

#include "snow.yy.h"

#include "lex.yy.h"

void yyerror (void *scanner, char const *s);

%}

%defines

%output "snow.yy.c"

%define api.pure

%lex-param {yyscan_t scanner}

%parse-param {void *scanner}

%token TOKEN_UNKNOW TOKEN_EOF TOKEN_WORD

%%

primary:
TOKEN_UNKNOW | TOKEN_EOF | TOKEN_WORD                       {$$ = $1;}

%%

void yyerror (void *scanner, char const *s) {
    printf ("[%s] %s\n", s, yyget_text(scanner));
}
