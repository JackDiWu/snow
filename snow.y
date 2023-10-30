%{

#include "native.h"

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

%token TOKEN_UNKNOW TOKEN_WORD TOKEN_STRING

%token TOKEN_DEC TOKEN_HEX TOKEN_FLOAT

%token TOKEN_EQUAL TOKEN_PLUS TOKEN_SUB TOKEN_TIMES TOKEN_DIVIDE

%token TOKEN_LP TOKEN_RP TOKEN_LS TOKEN_RS TOKEN_LC TOKEN_RC TOKEN_LA TOKEN_RA

%token TOKEN_DOUBLE_AND TOKEN_DOUBLE_OR TOKEN_DOUBLE_LA TOKEN_DOUBLE_RA

%token TOKEN_AND TOKEN_OR TOKEN_QUESTION TOKEN_POINT TOKEN_BROKEN_ISSUE TOKEN_EXCLAMATION TOKEN_AT TOKEN_HASHTAG TOKEN_DOLLAR TOKEN_PERCENT TOKEN_START TOKEN_COLON TOKEN_SEMICOLON TOKEN_BACKSLASH

%%

word_list:
word {}
| word_list word {}
;

word:
TOKEN_WORD { yyprint(); }
;

%%
