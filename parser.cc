/*
 * @Author: Jack
 * @Date: 2023-10-29 15:06:43
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:31:16
 */
#include "parser.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

snow::parser::parser() {
    yylex_init(&_yyparse.scanner);
}

snow::parser::~parser() {
    yylex_destroy(_yyparse.scanner);
}

int snow::parser::scan(const char *data, int size) {
    yy_scan_bytes(data, size, _yyparse.scanner);

    yyset_lineno(1, _yyparse.scanner);
    yyset_column(1, _yyparse.scanner);

    return yyparse(&_yyparse);
}
