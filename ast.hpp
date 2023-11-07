#ifndef _SNOW_AST_H_
#define _SNOW_AST_H_

#include "defs.h"
#include "snow.yy.hh"

namespace snow {

    typedef enum {
        ATOM_TYPE_SIGN,
        ATOM_TYPE_INT,
        ATOM_TYPE_UINT,
        ATOM_TYPE_FLOAT,
        ATOM_TYPE_STRING,
        ATOM_TYPE_WORD,
    } atom_type;

    class atom {
        public:
            snow::atom_type atom_type;

            yytoken_kind_t token_type;

            std::shared_ptr<atom> L, R, T;

        public:
            atom(snow::atom_type ap, yytoken_kind_t tp) : atom_type(ap), token_type(tp) {}

            virtual ~atom() {}

        public:
            virtual const char * text() = 0;
    };

    class expr_string : public atom {
        public:
            std::string v_string;

        public:
            expr_string(snow::atom_type ap, yytoken_kind_t tp) : atom(ap, tp) {}

            expr_string(const char *s) : atom(ATOM_TYPE_STRING, TOKEN_FLOAT) { v_string.assign(s); }

            expr_string(const std::string &s): expr_string(s.c_str()) {}

            virtual ~expr_string() {}

        public:
            virtual const char * text() {
                return v_string.c_str();
            }
    };

    class expr_number : public expr_string {
        public:
            int64_t v_int64;

            uint64_t v_uint64;

            double v_float64;

        public:
            expr_number(snow::atom_type ap, yytoken_kind_t tp) : expr_string(ap, tp) {}

            expr_number(int64_t v) : expr_string(ATOM_TYPE_INT, TOKEN_DEC), v_int64(v) {}

            expr_number(uint64_t v) : expr_string(ATOM_TYPE_UINT, TOKEN_HEX), v_uint64(v) {}

            expr_number(double v) : expr_string(ATOM_TYPE_FLOAT, TOKEN_FLOAT), v_float64(v) {}

            expr_number(int v) : expr_number((int64_t)v) {}

            expr_number(unsigned int v) : expr_number((uint64_t)v) {}

            virtual ~expr_number() {}

        public:
            virtual const char * text() {
                char buffer[MAX_BUFFER_SIZE] = {};
                switch (atom_type) {
                case ATOM_TYPE_INT: {
                    snprintf(buffer, MAX_BUFFER_SIZE, "%lld", v_int64); v_string.assign(buffer);
                    return v_string.c_str();
                }
                case ATOM_TYPE_UINT: {
                    snprintf(buffer, MAX_BUFFER_SIZE, "%llx", v_uint64); v_string.assign(buffer);
                    return v_string.c_str();
                }
                case ATOM_TYPE_FLOAT: {
                    snprintf(buffer, MAX_BUFFER_SIZE, "%lf", v_float64); v_string.assign(buffer);
                    return v_string.c_str();
                }
                default:
                    return "unknow number";
                }
            }
    };

    class expr_binary : public expr_number {
        public:
            expr_binary(yytoken_kind_t tp) : expr_number(ATOM_TYPE_SIGN, tp) {

            }

            virtual ~expr_binary() {}

        public:
            virtual const char * text() {
                switch (token_type) {
                case TOKEN_PLUS:
                    return "+";
                case TOKEN_SUB:
                    return "-";
                case TOKEN_TIMES:
                    return "*";
                case TOKEN_DIVIDE:
                    return "/";
                case TOKEN_LA:
                    return "<";
                case TOKEN_RA:
                    return ">";
                case TOKEN_AND:
                    return "&";
                case TOKEN_OR:
                    return "|";
                case TOKEN_PERCENT:
                    return "%";
                case TOKEN_LA_EQUAL:
                    return "<=";
                case TOKEN_RA_EQUAL:
                    return ">=";
                case TOKEN_DOUBLE_EQUAL:
                    return "==";
                case TOKEN_NOT_EQUAL:
                    return "!=";
                
                default:
                    return "unknow sign";
                }
            }
    };

    class expr_variable : public atom {
        public:
            std::string name;

        public:
            expr_variable(const char *s) : atom(ATOM_TYPE_WORD, TOKEN_WORD), name(s) { }
    };

    class expr_call : public expr_variable {
        public:
            expr_call(const char *s) : expr_variable(s) { }
    };
}


#endif
