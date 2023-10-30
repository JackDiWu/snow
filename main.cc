/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 10:42:01
 */
#include "defs.h"

extern "C" {
    #include "snow.yy.h"
    #include "lex.yy.h"
}

// std::string text = "I am storm + - * / () [] {} <>  .~!@#$%^&*;:?\\ &&  || << >> \"say\\\"something+-*/\" 123 0x232 0.15234 \"Hello\\\'\\\"world\" ";

std::string text = "I am '12132\"fds\"df' \"99\'dddd\'ccc\" '233' storm";

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
    auto parser = yy_init();
    
    yy_scan(parser, text.data(), text.size());

    yy_destroy(parser);
}

int main(int argc, const char **argv) {
    test_lexer();
    // test_parser();
    return 0;
}