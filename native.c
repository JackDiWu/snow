/*
 * @Author: Jack
 * @Date: 2023-10-30 11:35:46
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 19:05:35
 */
#include "native.h"

void yyerror (void *parser, char const *s) {
    printf ("%s:%d:%d %s '%s'\n", yyname, yyget_lineno(yylexer), yyget_column(yylexer), s, yyget_text(yylexer));
}