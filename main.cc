/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 14:35:45
 */
#include "defs.h"
#include "parser.hpp"
#include "symbol.hpp"

// std::string text = "I am storm + - * / () [] {} <>  .~!@#$%^&*;:?\\ &&  || << >> \"say\\\"something+-*/\" 123 0x232 0.15234 \"Hello\\\'\\\"world\" ";

std::string text = "print(1, 7 + t, 3 + 1) + ac ";

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
    printf("--- %p\n", snow::symbols::shared().get());
    auto scanner = std::make_shared<snow::scanner>("main.cc", text.data(), text.size());
    scanner->resolve();
}

int main(int argc, const char **argv) {
    // test_lexer();
    test_parser();
    return 0;
}