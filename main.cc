/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 13:21:31
 */
#include "defs.h"

std::string text = "int i = 1;";

int main(int argc, const char **argv) {
    yyscan_t scan;

    yylex_init(&scan);

    yy_scan_bytes(text.data(), text.size(), scan);

    bool stop = false;

    while (!stop) {
        int token = yylex(nullptr, scan);

        switch (token) {
            case TOKEN_EOF: {
                stop = true;
                printf("EOF\n");
                break;
            }
            
            default: {
                printf("----------- %d %s\n", token, yyget_text(scan));
                break;
            }
        }
    }

    yylex_destroy(scan);
    return 0;
}