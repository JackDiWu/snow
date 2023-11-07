%{

#include "parser.hpp"

%}

%defines

%output "snow.yy.cc"

%define api.pure

%lex-param {yylexer}

%parse-param {void *parser}

%token TOKEN_UNKNOW TOKEN_WORD TOKEN_STRING

%token TOKEN_DEC TOKEN_HEX TOKEN_FLOAT

%token TOKEN_EQUAL TOKEN_PLUS TOKEN_SUB TOKEN_TIMES TOKEN_DIVIDE

%token TOKEN_LP TOKEN_RP TOKEN_LS TOKEN_RS TOKEN_LC TOKEN_RC TOKEN_LA TOKEN_RA

%token TOKEN_DOUBLE_AND TOKEN_DOUBLE_OR TOKEN_DOUBLE_LA TOKEN_DOUBLE_RA TOKEN_DOUBLE_EQUAL

%token TOKEN_LA_EQUAL TOKEN_RA_EQUAL TOKEN_NOT_EQUAL

%token TOKEN_AND TOKEN_OR TOKEN_QUESTION TOKEN_POINT TOKEN_BROKEN_ISSUE TOKEN_EXCLAMATION TOKEN_AT TOKEN_HASHTAG TOKEN_DOLLAR TOKEN_PERCENT TOKEN_XOR TOKEN_COLON TOKEN_SEMICOLON TOKEN_BACKSLASH TOKEN_COMMA

%%

/**************** call param ****************/
call_param:
expression { printf("[call param one] %ld\n", $1); }
|
expression TOKEN_COMMA call_param { printf("[call param some] %ld\n", $1); }
;



/**************** call name ****************/
call_name:
TOKEN_WORD { printf("[call name] %s\n", yyget_text(yylexer)); }
;



/**************** call ****************/
call:
call_name TOKEN_LP call_param TOKEN_RP { printf("[call]\n"); }
;



/**************** expression ****************/
expression:
op_logic_or { $$ = $1; }
;



/**************** logic or ****************/
op_logic_or:
op_logic_and { $$ = $1; }
|
op_logic_and TOKEN_DOUBLE_OR op_logic_or { $$ = $1 || $3; printf("result: %ld = %ld || %ld\n", $$, $1, $3); }
;



/**************** logic and ****************/
op_logic_and:
op_or { $$ = $1; }
|
op_or TOKEN_DOUBLE_AND op_logic_and { $$ = $1 && $3; printf("result: %ld = %ld && %ld\n", $$, $1, $3); }
;



/**************** or ****************/
op_or:
op_xor { $$ = $1; }
|
op_xor TOKEN_OR op_or { $$ = $1 | $3; printf("result: %ld = %ld | %ld\n", $$, $1, $3); }
;



/**************** xor ****************/
op_xor:
op_and { $$ = $1; }
|
op_and TOKEN_XOR op_xor { $$ = $1 ^ $3; printf("result: %ld = %ld ^ %ld\n", $$, $1, $3); }
;



/**************** and ****************/
op_and:
op_equal { $$ = $1; }
|
op_equal TOKEN_AND op_and { $$ = $1 & $3; printf("result: %ld = %ld & %ld\n", $$, $1, $3); }
;



/**************** equal ****************/
op_equal:
op_relation { $$ = $1; }
|
op_relation TOKEN_DOUBLE_EQUAL op_equal { $$ = $1 == $3; printf("result: %ld = %ld == %ld\n", $$, $1, $3); }
|
op_relation TOKEN_NOT_EQUAL op_equal { $$ = $1 != $3; printf("result: %ld = %ld != %ld\n", $$, $1, $3); }
;



/**************** relation ****************/
op_relation:
op_bit { $$ = $1; }
|
op_bit TOKEN_LA op_relation { $$ = $1 < $3; printf("result: %ld = %ld < %ld\n", $$, $1, $3); }
|
op_bit TOKEN_RA op_relation { $$ = $1 > $3; printf("result: %ld = %ld > %ld\n", $$, $1, $3); }
|
op_bit TOKEN_LA_EQUAL op_relation { $$ = $1 <= $3; printf("result: %ld = %ld <= %ld\n", $$, $1, $3); }
|
op_bit TOKEN_RA_EQUAL op_relation { $$ = $1 >= $3; printf("result: %ld = %ld >= %ld\n", $$, $1, $3); }
;



/**************** bit ****************/
op_bit:
op_plus_sub { $$ = $1; }
|
op_plus_sub TOKEN_DOUBLE_LA op_bit { $$ = $1 << $3; printf("result: %ld = %ld << %ld\n", $$, $1, $3); }
|
op_plus_sub TOKEN_DOUBLE_RA op_bit { $$ = $1 >> $3; printf("result: %ld = %ld >> %ld\n", $$, $1, $3); }
;



/**************** plus sub ****************/
op_plus_sub:
op_times_divide_mod { $$ = $1; }
|
op_times_divide_mod TOKEN_PLUS op_plus_sub { $$ = $1 + $3; printf("result: %ld = %ld + %ld\n", $$, $1, $3); }
|
op_times_divide_mod TOKEN_SUB op_plus_sub { $$ = $1 - $3; printf("result: %ld = %ld - %ld\n", $$, $1, $3); }
;



/**************** times divide mod ****************/
op_times_divide_mod:
op_prefix { $$ = $1; }
|
op_prefix TOKEN_TIMES op_times_divide_mod { $$ = $1 * $3; printf("result: %ld = %ld * %ld\n", $$, $1, $3); }
|
op_prefix TOKEN_DIVIDE op_times_divide_mod { $$ = $1 / $3; printf("result: %ld = %ld / %ld\n", $$, $1, $3); }
|
op_prefix TOKEN_PERCENT op_times_divide_mod { $$ = $1 % $3; printf("result: %ld = %ld mod %ld\n", $$, $1, $3); }
;



/**************** prefix ****************/
op_prefix:
op_suffix { $$ = $1; }
|
TOKEN_PLUS op_suffix { $$ = +($2); printf("result: %ld = + %ld\n", $$, $2); }
|
TOKEN_SUB op_suffix { $$ = -($2); printf("result: %ld = - %ld\n", $$, $2); }
|
TOKEN_EXCLAMATION op_suffix { $$ = !($2); printf("result: %ld = ! %ld\n", $$, $2); }
|
TOKEN_BROKEN_ISSUE op_suffix { $$ = ~($2); printf("result: %ld = ~ %ld\n", $$, $2); }
;



/**************** suffix ****************/
op_suffix:
atom { $$ = $1; }
;



/**************** atom ****************/
atom:
TOKEN_DEC { $$ = strtol(yyget_text(yylexer), NULL, 10); }
|
TOKEN_HEX { $$ = strtol(yyget_text(yylexer), NULL, 16); }
|
TOKEN_LP expression TOKEN_RP { $$ = $2; }
|
call { $$ = $1; }
;

%%
