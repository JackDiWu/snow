/*
 * @Author: Jack
 * @Date: 2023-11-07 09:54:12
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 20:18:01
 */
#include "defs.h"
#include "parser.hpp"
#include "symbol.hpp"

void yyerror (void *parser, char const *s) {
    printf ("%s:%d:%d %s '%s'\n", yy_name.c_str(), yyget_lineno(yy_lexer), yyget_column(yy_lexer), s, yyget_text(yy_lexer));
}
