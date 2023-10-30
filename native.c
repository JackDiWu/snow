/*
 * @Author: Jack
 * @Date: 2023-10-30 11:35:46
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:36:01
 */
#include "native.h"

void yyerror (void *parser, char const *s) {
    printf ("[%d:%d] %s '%s'\n", yyget_lineno(LEX_PARAM), yyget_column(LEX_PARAM), s, yyget_text(LEX_PARAM));
}