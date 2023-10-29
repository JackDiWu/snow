/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 14:15:33
 */
#include "defs.h"

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
    
    yyscan_t scan;

    yylex_init(&scan);
    yy_scan_bytes(text.data(), text.size(), scan);

    yyset_lineno(1, scan);
    yyset_column(1, scan);

    yyparse(scan);

    yylex_destroy(scan);
    return 0;
}