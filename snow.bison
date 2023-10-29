%{

#include "snow.yy.h"

#include "lex.yy.h"

%}

%defines

%define api.pure

%output "snow.yy.c"

%token TOKEN_UNKNOW TOKEN_EOF TOKEN_WORD

%%

primary:
TOKEN_UNKNOW | TOKEN_EOF | TOKEN_WORD                       {$$ = $1}

%%
