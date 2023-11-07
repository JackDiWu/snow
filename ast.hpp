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
    } atom_type;

    class atom {
        public:
            atom_type type;

            yytoken_kind_t token_type;

            std::shared_ptr<atom> L, R, T;

            std::string v_string;

        public:
            atom(atom_type ap, yytoken_kind_t tp) : type(ap), token_type(tp) {}

            virtual ~atom() {}

        public:
            virtual const char * text() = 0;
    };

    class atom_binary : public atom {
        public:
            atom_binary(yytoken_kind_t tp) : atom(ATOM_TYPE_SIGN, tp) {

            }

            virtual ~atom_binary() {}

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

    class atom_number : public atom {
        public:
            int64_t v_int64;

            uint64_t v_uint64;

            double v_float64;

        public:
            atom_number(int64_t v) : atom(ATOM_TYPE_INT, TOKEN_DEC), v_int64(v) {}

            atom_number(uint64_t v) : atom(ATOM_TYPE_UINT, TOKEN_HEX), v_uint64(v) {}

            atom_number(double v) : atom(ATOM_TYPE_FLOAT, TOKEN_FLOAT), v_float64(v) {}

            atom_number(int v) : atom_number((int64_t)v) {}

            atom_number(unsigned int v) : atom_number((uint64_t)v) {}

            virtual ~atom_number() {}

        public:
            virtual const char * text() {
                char buffer[1024] = {};
                switch (type) {
                case ATOM_TYPE_INT: {
                    snprintf(buffer, 1024, "%lld", v_int64); atom::v_string.assign(buffer);
                    return v_string.c_str();
                }
                case ATOM_TYPE_UINT: {
                    snprintf(buffer, 1024, "%llx", v_uint64); atom::v_string.assign(buffer);
                    return v_string.c_str();
                }
                case ATOM_TYPE_FLOAT: {
                    snprintf(buffer, 1024, "%lf", v_float64); atom::v_string.assign(buffer);
                    return v_string.c_str();
                }
                default:
                    return "unknow number";
                }
            }
    };

    class atom_string : public atom {
        public:
            atom_string(const char *s) : atom(ATOM_TYPE_STRING, TOKEN_FLOAT) { v_string.assign(s); }

            atom_string(const std::string &s): atom_string(s.c_str()) {}

            virtual ~atom_string() {}

        public:
            virtual const char * text() {
                return v_string.c_str();
            }
    };
}


#endif
