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
            expr_type type;

        public:
            data(expr_type tk) : type(tk) {}

            virtual ~data() {}

        public:
            virtual bool is_type(expr_type tk) {
                return tk == type;
            }
    };

    class data_string : public data {
        public:
            std::string v_string;

        public:
            data_string(expr_type tk) : data(tk) {}

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
            data_number(expr_type tk) : data_string(tk) {}

            data_number(expr_type tk, int64_t v) : data_string(tk), v_int64(v) {}

            data_number(expr_type tk, uint64_t v) : data_string(tk), v_uint64(v) {}

            data_number(expr_type tk, double v) : data_string(tk), v_float64(v) {}

            data_number(expr_type tk, const char *str) : data_string(tk, str) {
                switch (type) {
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
            value(int64_t v) : data_number(EXPR_TYPE_INT, v) {}

            value(uint64_t v) : data_number(EXPR_TYPE_UINT, v) {}

            value(double v) : data_number(EXPR_TYPE_FLOAT, v) {}

            value(expr_type tk, const char *s) : data_number(tk, s) {}

            virtual ~value() {}

        public:
            static value plus(int64_t l, int64_t r) {
                printf("[expr] %lld + %lld\n", l, r);
                return value(l + r);
            }

            static value plus(uint64_t l, uint64_t r) {
                printf("[expr] %lld + %lld\n", l, r);
                return value(l + r);
            }
    };

    class expr {
        public:
            snow::value value;

            expr_type token;

        public:
            expr(expr_type tk) : value(tk, ""), token(tk) {
                // printf("[expr] %s\n", get_type_string(token));
            }

            expr(expr_type tk, const char *str) : value(tk, str), token(tk) {
                // printf("[expr] %s %s\n", get_type_string(token), str);
            }

            virtual ~expr() {}

        public:
            virtual const char * text() {
                return value.text();
            }

            virtual int resolve() {
                return 0;
            }

            virtual bool is_expr_type(expr_type tk) {
                return token == tk;
            }

            virtual bool is_value_type(expr_type tk) {
                return value.is_type(tk);
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
                // printf("[expr] %s %s %s\n", l->text(), get_type_string(token), r->text());
            }

            virtual ~expr_binary() {}

        public:
            virtual int resolve() {
                L->resolve();

                R->resolve();

                if (L->is_value_type(EXPR_TYPE_INT) && R->is_value_type(EXPR_TYPE_INT)) {
                    value = value::plus(L->value.v_int64, R->value.v_int64);
                    return 0;
                }
                
                if (L->is_value_type(EXPR_TYPE_INT) || R->is_value_type(EXPR_TYPE_UINT)) {
                    value = value::plus((uint64_t)L->value.v_int64, R->value.v_uint64);
                    return 0;
                }
                
                if (L->is_value_type(EXPR_TYPE_UINT) || R->is_value_type(EXPR_TYPE_INT)) {
                    value = value::plus(L->value.v_uint64, (uint64_t)R->value.v_int64);
                    return 0;
                }

                if (L->is_value_type(EXPR_TYPE_UINT) || R->is_value_type(EXPR_TYPE_UINT)) {
                    value = value::plus(L->value.v_uint64, R->value.v_uint64);
                    return 0;
                }

                return 0;
            }
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
