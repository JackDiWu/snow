%{

#include "parser.h"

#include "snow.yy.h"

#include "lex.yy.h"

void yyerror (void *parser, char const *s);

%}

%defines

%output "snow.yy.c"

%define api.pure

%lex-param {LEX_PARAM}

%parse-param {void *parser}

%token TOKEN_UNKNOW TOKEN_WORD

%%

word_list:
word {}
| word_list word {}
;

word:
TOKEN_WORD { printf("- %s\n", yyget_text(LEX_PARAM)); }
;

%%
