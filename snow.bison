%{

#include "snow.yy.h"

#include "lex.yy.h"

%}

%defines

%output "snow.yy.c"

%token TOKEN_UNKNOW TOKEN_EOF TOKEN_WORD

%%

primary:
TOKEN_UNKNOW | TOKEN_EOF | TOKEN_WORD                       {$$ = $1}

%%

void yyerror (void *scan, char const *s) {
    printf("%s\n", s);
}
