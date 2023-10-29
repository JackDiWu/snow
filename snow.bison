%{

#define YYPARSE_PARAM scan

#define YYLEX_PARAM scan

#include "lex.yy.h"

%}

%defines

%output "parse.yy.c"

%parse-param {void *scan}

%token TOKEN_UNKNOW TOKEN_EOF TOKEN_WORD

%%

primary:
TOKEN_UNKNOW | TOKEN_EOF | TOKEN_WORD                       {$$ = $1}

%%

void yyerror (void *scan, char const *s) {
    printf("%s\n", s);
}
