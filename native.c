/*
 * @Author: Jack
 * @Date: 2023-10-30 11:35:46
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:53:06
 */
#include "native.h"

void yyerror (void *parser, char const *s) {
    printf ("[%d:%d] %s '%s'\n", yyget_lineno(yylexer()), yyget_column(yylexer()), s, yyget_text(yylexer()));
}