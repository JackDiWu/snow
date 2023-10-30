/*
 * @Author: Jack
 * @Date: 2023-10-29 15:06:43
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 19:03:37
 */
#include "parser.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

snow::scanner::scanner(const char *nm, const char *data, int size) : name(nm), parser(&_parser) {
    yylex_init(&yylexer());
    
    yy_scan_bytes(data, size, yylexer());

    yyset_lineno(1, yylexer());
    yyset_column(0, yylexer());

    parser->self = this;
    parser->name = name.c_str();
}

snow::scanner::~scanner() {
    yylex_destroy(yylexer());
}

int snow::scanner::resolve() {
    return yyparse(parser);
}
