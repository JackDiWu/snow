/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 19:02:59
 */
#ifndef _SNOW_NATIVE_H_
#define _SNOW_NATIVE_H_

#include <stdio.h>

#include "snow.yy.h"
#include "lex.yy.h"

typedef struct _yyparse_t {
    void *self;
    
    void *scanner;

    const char *name;
} *yyparse_t;

#define yyself()              ((yyparse_t)parser)->self

#define yyname()              ((yyparse_t)parser)->name

#define yylexer()             ((yyparse_t)parser)->scanner

#define yyprint()             printf("[lex] %s\n", yyget_text(yylexer()))

#endif
