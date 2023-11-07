/*
 * @Author: Jack
 * @Date: 2023-10-29 11:52:56
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-08 00:29:33
 */
#include "defs.h"
#include "parser.hpp"
#include "symbol.hpp"

// std::string text = "I am storm + - * / () [] {} <>  .~!@#$%^&*;:?\\ &&  || << >> \"say\\\"something+-*/\" 123 0x232 0.15234 \"Hello\\\'\\\"world\" ";

std::string text = "  print(1 + 2, 3 * 5, 7 + 21)  ";

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
    scanner->parse();
    scanner->resolve();
    
    if (scanner->top.get()) {
        if (scanner->top->is_value_type(snow::EXPR_TYPE_INT)) {
            printf("[result] signed %lld\n", scanner->top->value.v_int64);
            return;
        }

        if (scanner->top->is_value_type(snow::EXPR_TYPE_UINT)) {
            printf("[result] unsigned %lld\n", scanner->top->value.v_uint64);
            return;
        }
    }
}

class A {
    public:
        virtual const char * T() {
            return "A";
        }
};

class B : public A {
    public:
        virtual const char * T() {
            return "X";
        }
};

int main(int argc, const char **argv) {
    // test_lexer();
    test_parser();

    // auto p = std::make_shared<B>();

    // printf("---- %s\n", p->T());

    // auto a = std::shared_ptr<A>(p);

    // printf("---- %s\n", a->T());

    // std::shared_ptr<B> b = std::dynamic_pointer_cast<B>(a);

    // printf("---- %s\n", b->T());

    return 0;
}