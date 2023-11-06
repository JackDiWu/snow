/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-06 20:07:16
 */
#include "defs.h"
#include "parser.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

// std::string text = "I am storm + - * / () [] {} <>  .~!@#$%^&*;:?\\ &&  || << >> \"say\\\"something+-*/\" 123 0x232 0.15234 \"Hello\\\'\\\"world\" ";

std::string text = "-(8 - 3) * + 5 + 0x26 ";

void test_lexer() {
    yyscan_t scan;

    yylex_init(&scan);
    yy_scan_bytes(text.data(), text.size(), scan);
    yyset_lineno(1, scan);

    int token;

    do {
        token = yylex(nullptr, scan);

        printf("[lex] %d %s\n", token, yyget_text(scan));
    }  while (token >= TOKEN_UNKNOW);

    yylex_destroy(scan);
}

void test_parser() {
    auto scanner = std::make_shared<snow::scanner>("main.cc", text.data(), text.size());
    scanner->resolve();
}

int main(int argc, const char **argv) {
    // test_lexer();
    test_parser();
    return 0;
}