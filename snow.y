%{

#include "parser.h"

#include "snow.yy.h"

#include "lex.yy.h"

#define LEX_PARAM    ((yyparse_t)parser)->scanner

#define LEX_PRINT()  printf("[lex] %s\n", yyget_text(LEX_PARAM))

void yyerror (void *parser, char const *s);
%}

%defines

%output "snow.yy.c"

%define api.pure

%lex-param {LEX_PARAM}

%parse-param {void *parser}

%token TOKEN_UNKNOW TOKEN_WORD TOKEN_STRING

%token TOKEN_DEC TOKEN_HEX TOKEN_FLOAT

%token TOKEN_PLUS TOKEN_SUB TOKEN_TIMES TOKEN_DIVIDE

%%

word_list:
word {}
| word_list word {}
;

word:
TOKEN_WORD { LEX_PRINT(); }
;

%%

void yyerror (void *parser, char const *s) {
    printf ("[%d:%d] %s '%s'\n", yyget_lineno(LEX_PARAM), yyget_column(LEX_PARAM), s, yyget_text(LEX_PARAM));
}
