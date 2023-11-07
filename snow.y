%{

#include "parser.hpp"

%}

%defines

%output "snow.yy.cc"

%define api.pure

%lex-param {yy_lexer}

%parse-param {void *parser}

%token TOKEN_UNKNOW TOKEN_WORD TOKEN_STRING TOKEN_ENTER

%token TOKEN_DEC TOKEN_HEX TOKEN_FLOAT

%token TOKEN_EQUAL TOKEN_PLUS TOKEN_SUB TOKEN_TIMES TOKEN_DIVIDE

%token TOKEN_LP TOKEN_RP TOKEN_LS TOKEN_RS TOKEN_LC TOKEN_RC TOKEN_LA TOKEN_RA

%token TOKEN_DOUBLE_AND TOKEN_DOUBLE_OR TOKEN_DOUBLE_LA TOKEN_DOUBLE_RA TOKEN_DOUBLE_EQUAL

%token TOKEN_LA_EQUAL TOKEN_RA_EQUAL TOKEN_NOT_EQUAL

%token TOKEN_AND TOKEN_OR TOKEN_QUESTION TOKEN_POINT TOKEN_BROKEN_ISSUE TOKEN_EXCLAMATION TOKEN_AT TOKEN_HASHTAG TOKEN_DOLLAR TOKEN_PERCENT TOKEN_XOR TOKEN_COLON TOKEN_SEMICOLON TOKEN_BACKSLASH TOKEN_COMMA

%%

/**************** statement ****************/
statement:
expression { $$ = $1; }
;



/**************** call param ****************/
variable:
TOKEN_WORD { $$ = snow::make_expr<snow::expr_variable>(snow::EXPR_TYPE_INT, yyget_text(yy_lexer)); }



/**************** call param ****************/
call_param:
expression { $$ = snow::make_expr<snow::expr_parameters>(snow::EXPR_CALL_PARAMETER, $1); }
|
expression TOKEN_COMMA call_param { $$ = $3; std::dynamic_pointer_cast<snow::expr_parameters>($$)->push($1);  }
;



/**************** call ****************/
call:
variable TOKEN_LP call_param TOKEN_RP { $$ = snow::make_expr<snow::expr_call>(snow::EXPR_CALL_FUNCTION, $1, $3); }
;



/**************** expression ****************/
expression:
op_logic_or { $$ = $1; yy_top = $$; }
;



/**************** logic or ****************/
op_logic_or:
op_logic_and { $$ = $1; }
|
op_logic_or TOKEN_DOUBLE_OR op_logic_and { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DOUBLE_OR, $1, $3); }
;



/**************** logic and ****************/
op_logic_and:
op_or { $$ = $1; }
|
op_logic_and TOKEN_DOUBLE_AND op_or { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DOUBLE_AND, $1, $3); }
;



/**************** or ****************/
op_or:
op_xor { $$ = $1; }
|
op_or TOKEN_OR op_xor { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_OR, $1, $3); }
;



/**************** xor ****************/
op_xor:
op_and { $$ = $1; }
|
op_xor TOKEN_XOR op_and { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_XOR, $1, $3); }
;



/**************** and ****************/
op_and:
op_equal { $$ = $1; }
|
op_and TOKEN_AND op_equal { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_AND, $1, $3); }
;



/**************** equal ****************/
op_equal:
op_relation { $$ = $1; }
|
op_equal TOKEN_DOUBLE_EQUAL op_relation { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DOUBLE_EQUAL, $1, $3); }
|
op_equal TOKEN_NOT_EQUAL op_relation { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_NOT_EQUAL, $1, $3); }
;



/**************** relation ****************/
op_relation:
op_bit { $$ = $1; }
|
op_relation TOKEN_LA op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_LA, $1, $3); }
|
op_relation TOKEN_RA op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_RA, $1, $3); }
|
op_relation TOKEN_LA_EQUAL op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_LA_EQUAL, $1, $3); }
|
op_relation TOKEN_RA_EQUAL op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_RA_EQUAL, $1, $3); }
;



/**************** bit ****************/
op_bit:
op_plus_sub { $$ = $1; }
|
op_plus_sub TOKEN_DOUBLE_LA op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DOUBLE_LA, $1, $3); }
|
op_plus_sub TOKEN_DOUBLE_RA op_bit { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DOUBLE_RA, $1, $3); }
;



/**************** plus sub ****************/
op_plus_sub:
op_times_divide_mod { $$ = $1; }
|
op_plus_sub TOKEN_PLUS op_times_divide_mod { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_PLUS, $1, $3); }
|
op_plus_sub TOKEN_SUB op_times_divide_mod { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_SUB, $1, $3); }
;



/**************** times divide mod ****************/
op_times_divide_mod:
op_prefix { $$ = $1; }
|
op_times_divide_mod TOKEN_TIMES op_prefix { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_TIMES, $1, $3); }
|
op_times_divide_mod TOKEN_DIVIDE op_prefix { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_DIVIDE, $1, $3); }
|
op_times_divide_mod TOKEN_PERCENT op_prefix { $$ = snow::make_expr<snow::expr_binary>(snow::EXPR_BINARY_PERCENT, $1, $3); }
;



/**************** prefix ****************/
op_prefix:
op_suffix { $$ = $1; }
|
TOKEN_PLUS op_suffix {  }
|
TOKEN_SUB op_suffix { }
|
TOKEN_EXCLAMATION op_suffix {  }
|
TOKEN_BROKEN_ISSUE op_suffix { }
;



/**************** suffix ****************/
op_suffix:
atom { $$ = $1; }
;



/**************** atom ****************/
atom:
TOKEN_DEC { $$ = snow::make_expr<snow::expr>(snow::EXPR_TYPE_INT, yyget_text(yy_lexer)); }
|
TOKEN_HEX { $$ = snow::make_expr<snow::expr>(snow::EXPR_TYPE_UINT, yyget_text(yy_lexer)); }
|
TOKEN_STRING { $$ = snow::make_expr<snow::expr>(snow::EXPR_TYPE_STRING, yyget_text(yy_lexer)); }
|
TOKEN_LP expression TOKEN_RP { $$ = $2; }
|
variable { }
|
call { }
;

%%
