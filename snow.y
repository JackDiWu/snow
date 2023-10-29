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

%token TOKEN_UNKNOW TOKEN_WORD

%%

word_list:
word {}
| word_list word {}
;

word:
TOKEN_WORD { printf("- %s\n", yyget_text(scanner)); }
;

%%

void yyerror (void *scanner, char const *s) {
    printf ("[%s %d:%d] %s\n", s, yyget_lineno(scanner), yyget_column(scanner), yyget_text(scanner));
}
