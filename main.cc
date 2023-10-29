/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 14:59:36
 */
#include "defs.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

std::string text = "I am storm";

void test_lex() {
    yyscan_t scan;

    yylex_init(&scan);
    yy_scan_bytes(text.data(), text.size(), scan);
    yyset_lineno(1, scan);

    int token;

    do {
        token = yylex(nullptr, scan);

        switch (token) {
            default: {
                printf("----------- %d %s\n", token, yyget_text(scan));
                break;
            }
        }
    }  while (!token);

    yylex_destroy(scan);
}

int main(int argc, const char **argv) {
    // test_lex();
    
    auto parser = yy_init();
    
    yy_scan(parser, text.data(), text.size());

    yy_destroy(parser);
    return 0;
}