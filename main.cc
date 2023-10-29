/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 12:29:24
 */
#include "defs.h"

std::string text = "int i = 1;";

int main(int argc, const char **argv) {
    yyscan_t scan;

    yylex_init(&scan);

    yy_scan_bytes(text.data(), text.size(), scan);

    int token;

    do {
        token = yylex(scan);

        printf("----------- %d %s\n", token, yyget_text(scan));
        
    } while(token != 0 && token != 1);

    yylex_destroy(scan);
    return 0;
}