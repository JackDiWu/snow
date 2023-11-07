/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 09:23:26
 */
#ifndef _SNOW_NATIVE_H_
#define _SNOW_NATIVE_H_

/**************** includes ****************/
#include <stdio.h>

#include "types.h"
#include "snow.yy.hh"

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lex.yy.h"

#ifdef __cplusplus
}
#endif



/**************** defines ****************/
#define yyprint()             printf("[lex] %s\n", yyget_text(yylexer))



/**************** functions ****************/
void yyerror (void *parser, char const *s);

#endif
