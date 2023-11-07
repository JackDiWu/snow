/*
 * @Author: Jack
 * @Date: 2023-11-07 09:52:17
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 19:35:34
 */
#ifndef _SNOW_TYPES_H_
#define _SNOW_TYPES_H_

#include "symbol.hpp"

/***************** defs ******************/
#define YYSTYPE_IS_TRIVIAL     1
#define YYSTYPE_IS_DECLARED    1



/***************** functions ******************/
typedef std::shared_ptr<snow::expr> YYSTYPE;



/***************** functions ******************/
void yyerror (void *parser, char const *s);

#endif
