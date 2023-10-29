%{

#include "token.h"

%}

%option reentrant noyywrap bison-bridge

%option header-file="lex.yy.h" outfile="lex.yy.c"

%%

(\+|\-|\*|\/|\(|\)|\[|\]|\{|\}|\||\.|\?|\\|\!|\^|\$)    { return (*yytext); }

(@|#|%|&|~|`|,|=|;|:|<|>)    { return (*yytext); }

\<\<                         { return TSHL; }

\>\>                         { return TSHR; }

\<=                          { return TCLE; }

\>=                          { return TCME; }

==                           { return TCEQ; }

\!=                          { return TCNE; }

&&                           { return TLAD; }

\|\|                         { return TLOR; }

\"(\\.|[^\\"])*\"            { yylval->node = make_node_string(yytext, yyleng); return TSTRING; }

[0-9]+                       { yylval->node = make_node_dec(yytext, yyleng); return TDEC; }

0x[0-9a-fA-F]+               { yylval->node = make_node_hex(yytext, yyleng); return THEX; }

[0-9]+\.[0-9]+               { yylval->node = make_node_float(yytext, yyleng); return TFLOAT; }

int                          { return TKINT; }

float                        { return TKFLOAT; }

string                       { return TKSTRING; }

if                           { return TKIF; }

else                         { return TKELSE; }

[_a-zA-Z][_a-zA-Z0-9]*       { yylval->node = make_node_identify(yytext, yyleng); return TIDENTITY; }

(\ |\t)                      {}

(\r\n|\n)                    { yyset_lineno(yyget_lineno(yyscanner) + 1, yyscanner); }

.                            { return TUNKNOW; }

%%