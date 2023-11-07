/*
 * @Author: Jack
 * @Date: 2023-11-07 09:54:12
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 09:54:22
 */
#include "defs.h"
#include "parser.hpp"

void yyerror (void *parser, char const *s) {
    auto scanner = static_cast<snow::scanner*>(parser);
    printf ("%s:%d:%d %s '%s'\n", scanner->name.c_str(), yyget_lineno(scanner->lexer), yyget_column(scanner->lexer), s, yyget_text(scanner->lexer));
}
