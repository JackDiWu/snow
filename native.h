/*
 * @Author: Jack
 * @Date: 2023-11-07 09:52:17
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 10:17:36
 */
#ifndef _SNOW_TYPES_H_
#define _SNOW_TYPES_H_

#include "ast.hpp"

/***************** defs ******************/
#define YYSTYPE        long



/***************** functions ******************/
void yyerror (void *parser, char const *s);

#endif
