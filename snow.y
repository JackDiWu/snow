%{

#include "native.h"

#include "snow.yy.h"

#include "lex.yy.h"

#define lex_param ((yyparse_t)parser)->scanner

%}

%defines

%output "snow.yy.c"

%define api.pure

%lex-param {lex_param}

%parse-param {void *parser}

%token TOKEN_UNKNOW TOKEN_WORD TOKEN_STRING

%token TOKEN_DEC TOKEN_HEX TOKEN_FLOAT

%token TOKEN_EQUAL TOKEN_PLUS TOKEN_SUB TOKEN_TIMES TOKEN_DIVIDE

%token TOKEN_LP TOKEN_RP TOKEN_LS TOKEN_RS TOKEN_LC TOKEN_RC TOKEN_LA TOKEN_RA

%token TOKEN_DOUBLE_AND TOKEN_DOUBLE_OR TOKEN_DOUBLE_LA TOKEN_DOUBLE_RA TOKEN_DOUBLE_EQUAL

%token TOKEN_LA_EQUAL TOKEN_RA_EQUAL TOKEN_NOT_EQUAL

%token TOKEN_AND TOKEN_OR TOKEN_QUESTION TOKEN_POINT TOKEN_BROKEN_ISSUE TOKEN_EXCLAMATION TOKEN_AT TOKEN_HASHTAG TOKEN_DOLLAR TOKEN_PERCENT TOKEN_START TOKEN_COLON TOKEN_SEMICOLON TOKEN_BACKSLASH

%%

/**************** plus sub ****************/
op_equal:
op_relation { $$ = $1; }
|
op_equal TOKEN_DOUBLE_EQUAL op_relation { $$ = $1 == $3; printf("result: %d = %d == %d\n", $$, $1, $3); }
|
op_equal TOKEN_NOT_EQUAL op_relation { $$ = $1 != $3; printf("result: %d = %d != %d\n", $$, $1, $3); }
;



/**************** plus sub ****************/
op_relation:
op_plus_sub { $$ = $1; }
|
op_relation TOKEN_LA op_plus_sub { $$ = $1 < $3; printf("result: %d = %d < %d\n", $$, $1, $3); }
|
op_relation TOKEN_RA op_plus_sub { $$ = $1 > $3; printf("result: %d = %d > %d\n", $$, $1, $3); }
|
op_relation TOKEN_LA_EQUAL op_plus_sub { $$ = $1 <= $3; printf("result: %d = %d <= %d\n", $$, $1, $3); }
|
op_relation TOKEN_RA_EQUAL op_plus_sub { $$ = $1 >= $3; printf("result: %d = %d >= %d\n", $$, $1, $3); }
;



/**************** plus sub ****************/
op_plus_sub:
op_times_divide_mod { $$ = $1; }
|
op_plus_sub TOKEN_PLUS op_times_divide_mod { $$ = $1 + $3; }
|
op_plus_sub TOKEN_SUB op_times_divide_mod { $$ = $1 - $3; }
;



/**************** times divide mod ****************/
op_times_divide_mod:
number { $$ = $1; }
|
op_times_divide_mod TOKEN_TIMES number { $$ = $1 * $3; }
|
op_times_divide_mod TOKEN_DIVIDE number { $$ = $1 / $3; }
|
op_times_divide_mod TOKEN_PERCENT number { $$ = $1 % $3; }
;



/**************** number ****************/
number:
TOKEN_DEC { $$ = atoi(yyget_text(yylexer)); }
;

%%
