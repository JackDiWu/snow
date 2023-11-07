/*
 * @Author: Jack
 * @Date: 2023-11-07 09:54:12
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 10:05:23
 */
#include "defs.h"
#include "parser.hpp"

snow::atom::atom() {

}

snow::atom::~atom() {
    
}

void yyerror (void *parser, char const *s) {
    printf ("%s:%d:%d %s '%s'\n", yyname.c_str(), yyget_lineno(yylexer), yyget_column(yylexer), s, yyget_text(yylexer));
}
