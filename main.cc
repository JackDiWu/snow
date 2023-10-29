/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 13:34:11
 */
#include "defs.h"

std::string text = "int i = 1;";

void test_lex() {
    yyscan_t scan;

    yylex_init(&scan);

    yy_scan_bytes(text.data(), text.size(), scan);

    int token;

    do {
        token = yylex(nullptr, scan);

        switch (token) {
            case TOKEN_EOF: {
                printf("EOF\n");
                break;
            }
            
            default: {
                printf("----------- %d %s\n", token, yyget_text(scan));
                break;
            }
        }
    }  while (token != TOKEN_EOF);

    yylex_destroy(scan);
}

int main(int argc, const char **argv) {
    test_lex();
    
    yyscan_t scan;

    yylex_init(&scan);
    yy_scan_bytes(text.data(), text.size(), scan);

    yyparse(scan);

    yylex_destroy(scan);
    return 0;
}