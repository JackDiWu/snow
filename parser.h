/*
 * @Author: Jack
 * @Date: 2023-10-29 14:22:23
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 14:58:45
 */
#ifndef _SNOW_PARSER_H_
#define _SNOW_PARSER_H_

typedef struct _yyparse_t {
    void *scanner;
    
} *yyparse_t;

yyparse_t yy_init(void) ;

void yy_destroy(yyparse_t parser);

int yy_scan(yyparse_t parser, const char *data, int size);

#endif
