/*
 * @Author: Jack
 * @Date: 2023-10-29 15:06:43
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:54:50
 */
#include "parser.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

snow::parser::parser(const char *data, int size) {
    yylex_init(&_yyparse.scanner);
    
    yy_scan_bytes(data, size, _yyparse.scanner);

    yyset_lineno(1, _yyparse.scanner);
    yyset_column(0, _yyparse.scanner);
}

snow::parser::parser(const std::string &text) {
    parser(text.data(), text.size());
}

snow::parser::~parser() {
    yylex_destroy(_yyparse.scanner);
}

int snow::parser::scan() {
    return yyparse(&_yyparse);
}
