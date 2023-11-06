/*
 * @Author: Jack
 * @Date: 2023-11-06 20:10:53
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-06 20:17:06
 */
#ifndef _SNOW_TYPES_H_
#define _SNOW_TYPES_H_

typedef struct _yyparse_t {
    void *self;
    
    void *scanner;

    const char *name;
} *yyparse_t;

#define yyself                ((yyparse_t)parser)->self

#define yyname                ((yyparse_t)parser)->name

#define yylexer               ((yyparse_t)parser)->scanner

#define lex_param             ((yyparse_t)parser)->scanner

#define YYSTYPE               long

#endif
