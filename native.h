/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-06 20:17:48
 */
#ifndef _SNOW_NATIVE_H_
#define _SNOW_NATIVE_H_

/**************** includes ****************/
#include <stdio.h>

#include "types.h"
#include "snow.yy.h"
#include "lex.yy.h"



/**************** defines ****************/
#define yyprint()             printf("[lex] %s\n", yyget_text(yylexer))



/**************** functions ****************/
void yyerror (void *parser, char const *s);

#endif
