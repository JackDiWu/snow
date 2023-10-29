/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 14:23:46
 */
#ifndef _SNOW_PARSER_H_
#define _SNOW_PARSER_H_

#include "snow.yy.h"
#include "lex.yy.h"

typedef struct _yyparse_t {
    yyscan_t scanner;
} *yyparse_t;

#endif
