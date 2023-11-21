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

        EXPR_PREFIX_PLUS,
        EXPR_PREFIX_SUB,
        EXPR_PREFIX_EXCLAM,
        EXPR_PREFIX_BROKEN_ISSUE,

        EXPR_CALL_PARAMETER,
        EXPR_CALL_FUNCTION,
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
            data_number(int64_t v) : data_string(EXPR_TYPE_INT), v_int64(v) {}

            data_number(uint64_t v) : data_string(EXPR_TYPE_UINT), v_uint64(v) {}

            data_number(double v) : data_string(EXPR_BINARY_DOUBLE_AND), v_float64(v) {}

            data_number(expr_type tk) : data_string(tk) {}

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

        public:
            virtual const char * text() {
                switch (type) {
                    case EXPR_TYPE_INT: {
                        v_string = std::to_string(v_int64);
                        break;
                    }
                    case EXPR_TYPE_UINT: {
                        v_string = std::to_string(v_uint64);
                        break;
                    }
                    case EXPR_TYPE_FLOAT: {
                        v_string = std::to_string(v_float64);
                        break;
                    }
                    default: {
                        break;
                    }
                }
                return v_string.c_str();
            }
    };

    class value : public data_number {
        public:
            value(bool v) : data_number((int64_t)v) {}

            value(int64_t v) : data_number(v) {}

            value(uint64_t v) : data_number(v) {}

            value(double v) : data_number(v) {}

            value(expr_type tk, const char *s) : data_number(tk, s) {}

            virtual ~value() {}

        public:
            template <typename T>
            static value times(T l, T r) {
                auto v = l * r;
                dbg_printf("[expr] %lld * %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value div(T l, T r) {
                auto v = l / r;
                dbg_printf("[expr] %lld / %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value mod(T l, T r) {
                auto v = l % r;
                dbg_printf("[expr] %lld %% %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value plus(T l, T r) {
                auto v = l + r;
                dbg_printf("[expr] %lld + %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value sub(T l, T r) {
                auto v = l - r;
                dbg_printf("[expr] %lld - %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value move_l(T l, T r) {
                auto v = l << r;
                dbg_printf("[expr] %lld << %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value move_r(T l, T r) {
                auto v = l >> r;
                dbg_printf("[expr] %lld >> %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value less(T l, T r) {
                auto v = l < r;
                dbg_printf("[expr] %lld < %lld -> %d\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value more(T l, T r) {
                auto v = l > r;
                dbg_printf("[expr] %lld > %lld -> %d\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value less_equal(T l, T r) {
                auto v = l <= r;
                dbg_printf("[expr] %lld <= %lld -> %d\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value more_equal(T l, T r) {
                auto v = l >= r;
                dbg_printf("[expr] %lld >= %lld -> %d\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value equal(T l, T r) {
                auto v = l == r;
                dbg_printf("[expr] %lld == %lld -> %d\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value not_equal(T l, T r) {
                auto v = l != r;
                dbg_printf("[expr] %lld != %lld -> %d\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value logic_and(T l, T r) {
                auto v = l & r;
                dbg_printf("[expr] %lld & %lld -> %lld\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value logic_xor(T l, T r) {
                auto v = l ^ r;
                dbg_printf("[expr] %lld ^ %lld -> %lld\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value logic_or(T l, T r) {
                auto v = l | r;
                dbg_printf("[expr] %lld | %lld -> %lld\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value logic_and_and(T l, T r) {
                auto v = l && r;
                dbg_printf("[expr] %lld && %lld -> %d\n", l, r, v);
                return value(v);
            }
            
            template <typename T>
            static value logic_or_or(T l, T r) {
                auto v = l || r;
                dbg_printf("[expr] %lld || %lld -> %d\n", l, r, v);
                return value(v);
            }

            template <typename T>
            static value exclam(T t) {
                auto v = !t;
                dbg_printf("[expr] !%lld -> %d\n", t, v);
                return value(v);
            }

            template <typename T>
            static value broken(T t) {
                auto v = ~t;
                dbg_printf("[expr] ~%lld -> %d\n", t, v);
                return value(v);
            }
    };

    class expr {
        public:
            int status;

            snow::value value;

            expr_type token;

        public:
            expr(expr_type tk) : status(UNI_STATUS_OK), value(tk, ""), token(tk) {
                // dbg_printf("[expr] %s\n", get_type_string(token));
            }

            expr(expr_type tk, const char *str) : status(UNI_STATUS_OK), value(tk, str), token(tk) {
                // dbg_printf("[expr] %s %s\n", get_type_string(token), str);
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

    class expr_prefix : public expr {
        public:
            std::shared_ptr<expr> T;

        public:
            expr_prefix(expr_type tk, const std::shared_ptr<expr> &t) : expr(tk), T(t) {}

            virtual ~expr_prefix() {}
        
        public:
            virtual int resolve() {
                if (is_status_fail(T->resolve())) {
                    return status;
                }

                switch (token) {
                    case EXPR_PREFIX_PLUS: 
                        return plus();
                    case EXPR_PREFIX_SUB: 
                        return sub();
                    case EXPR_PREFIX_EXCLAM: 
                        return exclam();
                    case EXPR_PREFIX_BROKEN_ISSUE: 
                        return broken();
                    default: {
                        return UNI_STATUS_INVALID_PREFIX;
                    }
                }
            }

            virtual int plus() {
                if (T->value.is_type(EXPR_TYPE_INT)) {
                    expr::value = value::plus<int64_t>(0, T->value.v_int64);
                }
                if (T->value.is_type(EXPR_TYPE_UINT)) {
                    expr::value = value::plus<uint64_t>(0, T->value.v_uint64);
                }
                return UNI_STATUS_INVALID_PREFIX;
            }

            virtual int sub() {
                if (T->value.is_type(EXPR_TYPE_INT)) {
                    expr::value = value::sub<int64_t>(0, T->value.v_int64);
                }
                if (T->value.is_type(EXPR_TYPE_UINT)) {
                    expr::value = value::sub<uint64_t>(0, T->value.v_uint64);
                }
                return UNI_STATUS_INVALID_PREFIX;
            }

            virtual int exclam() {
                if (T->value.is_type(EXPR_TYPE_INT)) {
                    expr::value = value::exclam<int64_t>(T->value.v_int64);
                }
                if (T->value.is_type(EXPR_TYPE_UINT)) {
                    expr::value = value::exclam<uint64_t>(T->value.v_uint64);
                }
                return UNI_STATUS_INVALID_PREFIX;
            }

            virtual int broken() {
                if (T->value.is_type(EXPR_TYPE_INT)) {
                    expr::value = value::broken<int64_t>(T->value.v_int64);
                }
                if (T->value.is_type(EXPR_TYPE_UINT)) {
                    expr::value = value::broken<uint64_t>(T->value.v_uint64);
                }
                return UNI_STATUS_INVALID_PREFIX;
            }
    };

    #define expr_binary_format(op) \
                if (L->is_value_type(EXPR_TYPE_INT) && R->is_value_type(EXPR_TYPE_INT)) {\
                    expr::value = value::op<int64_t>(L->value.v_int64, R->value.v_int64);\
                    return UNI_STATUS_OK;\
                }\
                if (L->is_value_type(EXPR_TYPE_INT) || R->is_value_type(EXPR_TYPE_UINT)) {\
                    expr::value = value::op<uint64_t>((uint64_t)L->value.v_int64, R->value.v_uint64);\
                    return UNI_STATUS_OK;\
                }\
                if (L->is_value_type(EXPR_TYPE_UINT) || R->is_value_type(EXPR_TYPE_INT)) {\
                    expr::value = value::op<uint64_t>(L->value.v_uint64, (uint64_t)R->value.v_int64);\
                    return UNI_STATUS_OK;\
                }\
                if (L->is_value_type(EXPR_TYPE_UINT) || R->is_value_type(EXPR_TYPE_UINT)) {\
                    expr::value = value::op<uint64_t>(L->value.v_uint64, R->value.v_uint64);\
                    return UNI_STATUS_OK;\
                }\
                return UNI_STATUS_INVALID_BINARY;

    class expr_binary : public expr {
        public:
            std::shared_ptr<expr> L, R;

        public:
            expr_binary(expr_type tk, const std::shared_ptr<expr> &l, const std::shared_ptr<expr> &r) : expr(tk), L(l), R(r) {
                // dbg_printf("[expr] %s %s %s\n", l->text(), get_type_string(token), r->text());
            }

            virtual ~expr_binary() {}

        public:
            virtual int resolve() {
                if (is_status_fail(L->resolve())) {
                    return status;
                }

                if (is_status_fail(R->resolve())) {
                    return status;
                }

                switch (token) {
                case EXPR_BINARY_TIMES:
                    return times();
                case EXPR_BINARY_DIVIDE:
                    return div();
                case EXPR_BINARY_PERCENT:
                    return mod();
                case EXPR_BINARY_PLUS:
                    return plus();
                case EXPR_BINARY_SUB:
                    return sub();
                case EXPR_BINARY_DOUBLE_LA:
                    return move_l();
                case EXPR_BINARY_DOUBLE_RA:
                    return move_r();

                case EXPR_BINARY_LA:
                    return less();
                case EXPR_BINARY_RA:
                    return more();
                case EXPR_BINARY_LA_EQUAL:
                    return less_equal();
                case EXPR_BINARY_RA_EQUAL:
                    return more_equal();

                case EXPR_BINARY_DOUBLE_EQUAL:
                    return equal();
                case EXPR_BINARY_NOT_EQUAL:
                    return not_equal();

                case EXPR_BINARY_AND:
                    return logic_and();
                case EXPR_BINARY_XOR:
                    return logic_xor();
                case EXPR_BINARY_OR:
                    return logic_or();

                case EXPR_BINARY_DOUBLE_AND:
                    return logic_and_and();
                case EXPR_BINARY_DOUBLE_OR:
                    return logic_or_or();

                default:
                    return UNI_STATUS_INVALID_BINARY;
                }
            }

            virtual int times() {
                expr_binary_format(times)
            }

            virtual int div() {
                expr_binary_format(div)
            }

            virtual int mod() {
                expr_binary_format(mod)
            }

            virtual int plus() {
                expr_binary_format(plus)
            }

            virtual int sub() {
                expr_binary_format(sub)
            }

            virtual int move_l() {
                expr_binary_format(move_l)
            }

            virtual int move_r() {
                expr_binary_format(move_r)
            }

            virtual int less() {
                expr_binary_format(less)
            }
            
            virtual int more() {
                expr_binary_format(more)
            }
            
            virtual int less_equal() {
                expr_binary_format(less_equal)
            }
            
            virtual int more_equal() {
                expr_binary_format(more_equal)
            }

            virtual int equal() {
                expr_binary_format(equal)
            }
            
            virtual int not_equal() {
                expr_binary_format(not_equal)
            }

            virtual int logic_and() {
                expr_binary_format(logic_and)
            }
            
            virtual int logic_xor() {
                expr_binary_format(logic_xor)
            }
            
            virtual int logic_or() {
                expr_binary_format(logic_or)
            }

            virtual int logic_and_and() {
                expr_binary_format(logic_and_and)
            }
            
            virtual int logic_or_or() {
                expr_binary_format(logic_or_or)
            }
    };

    class expr_variable : public expr {
        public:
            std::string name;

        public:
            expr_variable(expr_type tk, const char *str) : expr(tk, str), name(str) {}

            virtual ~expr_variable() {}
    };

    class expr_parameters : public expr {
        public:
            std::vector<std::shared_ptr<expr>> list;

            std::string buffer;

        public:
            expr_parameters(expr_type tk, const std::shared_ptr<expr> &one) : expr(tk, "call paramter") {
                push(one);
            }

            virtual ~expr_parameters() {}

        public:
            void push(const std::shared_ptr<expr> &one) {
                list.push_back(one);
            }

            virtual const char * text() {
                buffer = " ";
                for (auto it = list.end() - 1; it >= list.begin(); it--) {
                    buffer += (std::string(it->get()->value.text()) + " ");
                }
                return buffer.c_str();
            }

            virtual int resolve() {
                for (auto it = list.begin(); it < list.end(); it++) {
                    it->get()->resolve();
                }
                return 0;
            }
    };

    class expr_call : public expr {
        public:
            std::string name;

            std::shared_ptr<expr_parameters> parameters;

        public:
            expr_call(expr_type tk, const std::shared_ptr<expr> &v, const std::shared_ptr<expr> &p) : expr(tk) {
                name = std::dynamic_pointer_cast<expr_variable>(v)->name;
                parameters = std::dynamic_pointer_cast<expr_parameters>(p);
            }

            virtual ~expr_call() {}

        public:
            virtual int resolve() {
                parameters->resolve();
                dbg_printf("[call] %s (%s)\n", name.c_str(), parameters->text());
                return 0;
            }
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
