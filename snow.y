%{

#include "parser.h"

#include "snow.yy.h"

#include "lex.yy.h"

#define LEX_PARAM    ((yyparse_t)parser)->scanner

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

void yyerror (void *parser, char const *s) {
    printf ("[%d:%d] %s '%s'\n", yyget_lineno(LEX_PARAM), yyget_column(LEX_PARAM), s, yyget_text(LEX_PARAM));
}
