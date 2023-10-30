/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:51:54
 */
#ifndef _SNOW_NATIVE_H_
#define _SNOW_NATIVE_H_

#include <stdio.h>

#include "snow.yy.h"
#include "lex.yy.h"

typedef struct _yyparse_t {
    void *scanner;
} *yyparse_t;

#define yylexer()             ((yyparse_t)parser)->scanner

#define yyprint()             printf("[lex] %s\n", yyget_text(LEX_PARAM))

#endif
