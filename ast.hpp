#ifndef _SNOW_AST_H_
#define _SNOW_AST_H_

#include "defs.h"

namespace snow {

    typedef enum {
        EXPR_TYPE_NONE,

        EXPR_TYPE_INT,
        EXPR_TYPE_UINT,
        EXPR_TYPE_FLOAT,
        EXPR_TYPE_STRING,

        EXPR_BINARY_TIMES,
        EXPR_BINARY_DIVIDE,
        EXPR_BINARY_PERCENT,

        EXPR_BINARY_PLUS,
        EXPR_BINARY_SUB,

        EXPR_BINARY_DOUBLE_LA,
        EXPR_BINARY_DOUBLE_RA,

        EXPR_BINARY_LA,
        EXPR_BINARY_RA,
        EXPR_BINARY_LA_EQUAL,
        EXPR_BINARY_RA_EQUAL,

        EXPR_BINARY_DOUBLE_EQUAL,
        EXPR_BINARY_NOT_EQUAL,

        EXPR_BINARY_AND,
        EXPR_BINARY_XOR,
        EXPR_BINARY_OR,

        EXPR_BINARY_DOUBLE_AND,
        EXPR_BINARY_DOUBLE_OR,

        EXPR_CALL_PARAMETER,
    } expr_type;

    class data {
        public:
            expr_type token;

        public:
            data(expr_type tk) : token(tk) {}

            virtual ~data() {}
    };

    class data_string : public data {
        public:
            std::string v_string;

        public:
            data_string(expr_type tk, const char *str) : data(tk), v_string(str) {}

            virtual ~data_string() {}

        public:
            virtual const char * text() {
                return v_string.c_str();
            }
    };

    class data_number : public data_string {
        public:
            int64_t v_int64;

            uint64_t v_uint64;

            double v_float64;

        public:
            data_number(expr_type tk, const char *str) : data_string(tk, str) {
                switch (token) {
                    case EXPR_TYPE_INT: {
                        v_int64 = strtol(str, NULL, 10);
                        v_string = str;
                        break;
                    }
                    case EXPR_TYPE_UINT: {
                        v_uint64 = strtol(str, NULL, 16);
                        v_string = str;
                        break;
                    }
                    case EXPR_TYPE_FLOAT: {
                        v_float64 = strtod(str, NULL);
                        v_string = str;
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }

            virtual ~data_number() {}
    };

    class value : public data_number {
        public:
            value(expr_type tk, const char *str) : data_number(tk, str) {}

            virtual ~value() {}
    };

    class expr {
        public:
            snow::value value;

            expr_type token;

        public:
            expr(expr_type tk) : value(tk, ""), token(tk) {
                printf("[expr] %s\n", get_type_string(token));
            }

            expr(expr_type tk, const char *str) : value(tk, str), token(tk) {
                printf("[expr] %s %s\n", get_type_string(token), str);
            }

            virtual ~expr() {}

        public:
            virtual const char * text() {
                return value.text();
            }

        public:
            static const char * get_type_string(expr_type type) {
                switch (type) {
                    case EXPR_TYPE_NONE:
                        return "none";
        
                    case EXPR_TYPE_INT:
                        return "int";
                    case EXPR_TYPE_UINT:
                        return "uint";
                    case EXPR_TYPE_FLOAT:
                        return "float";
                    case EXPR_TYPE_STRING:
                        return "string";
                    
                    case EXPR_BINARY_TIMES:
                        return "*";
                    case EXPR_BINARY_DIVIDE:
                        return "/";
                    case EXPR_BINARY_PERCENT:
                        return "%";

                    case EXPR_BINARY_PLUS:
                        return "+";
                    case EXPR_BINARY_SUB:
                        return "-";

                    case EXPR_BINARY_DOUBLE_LA:
                        return "<<";
                    case EXPR_BINARY_DOUBLE_RA:
                        return ">>";

                    case EXPR_BINARY_LA:
                        return "<";
                    case EXPR_BINARY_RA:
                        return ">";
                    case EXPR_BINARY_LA_EQUAL:
                        return "<=";
                    case EXPR_BINARY_RA_EQUAL:
                        return ">=";

                    case EXPR_BINARY_DOUBLE_EQUAL:
                        return "==";
                    case EXPR_BINARY_NOT_EQUAL:
                        return "!=";

                    case EXPR_BINARY_AND:
                        return "&";
                    case EXPR_BINARY_XOR:
                        return "^";
                    case EXPR_BINARY_OR:
                        return "|";

                    case EXPR_BINARY_DOUBLE_AND:
                        return "&&";
                    case EXPR_BINARY_DOUBLE_OR:
                        return "||";

                    default: {
                        return "unknow";
                    }
                }
            }
    };

    class expr_unary : public expr {
        public:
            std::shared_ptr<expr> T;

        public:
            expr_unary(expr_type tk, const std::shared_ptr<expr> &t) : expr(tk), T(t) {}

            virtual ~expr_unary() {}
    };

    class expr_binary : public expr {
        public:
            std::shared_ptr<expr> L, R;

        public:
            expr_binary(expr_type tk, const std::shared_ptr<expr> &l, const std::shared_ptr<expr> &r) : expr(tk), L(l), R(r) {
                printf("[expr] %s %s %s\n", l->text(), get_type_string(token), r->text());
            }

            virtual ~expr_binary() {}
    };

    class expr_parameters : public expr {
        public:
            std::vector<std::shared_ptr<expr>> list;

        public:
            expr_parameters(const std::shared_ptr<expr> &one) : expr(EXPR_CALL_PARAMETER, "call paramter") {
                push(one);
            }

            virtual ~expr_parameters() {}

        public:
            void push(const std::shared_ptr<expr> &one) {
                list.push_back(std::shared_ptr<expr>(one));
            }
    };

    class expr_call : public expr {
        public:
            std::string name;

            std::shared_ptr<expr_parameters> parameters;

        public:
            expr_call(expr_type tk, const char *str, const std::shared_ptr<expr_parameters> &p) : expr(tk, str), name(str), parameters(p) {

            }

            virtual ~expr_call() {}
    };

    template<typename T>
    std::shared_ptr<T> make_expr(expr_type tk, const char *str) {
        return std::make_shared<T>(tk, str);
    }

    template<typename T>
    std::shared_ptr<T> make_expr(expr_type tk, const std::shared_ptr<expr> &t) {
        return std::make_shared<T>(tk, t);
    }

    template<typename T>
    std::shared_ptr<T> make_expr(expr_type tk, const std::shared_ptr<expr> &l, const std::shared_ptr<expr> &r) {
        return std::make_shared<T>(tk, l, r);
    }
}



#endif
