/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-29 12:19:41
 */
#include "defs.h"
#include "lex.yy.h"

#include <string>

std::string text = "int i = 12312312;";

int main(int argc, const char **argv) {
    yyscan_t scan;

    yylex_init(&scan);

    yy_scan_bytes(text.data(), text.size(), scan);

    printf("----------- %s\n", yyget_text(scan));

    yylex_destroy(scan);
    return 0;
}