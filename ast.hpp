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

        public:
            atom(atom_type ap, yytoken_kind_t tp) : type(ap), token_type(tp) {}

            virtual ~atom() {}
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
    };

    class atom_string : public atom {
        public:
            std::string v_string;

        public:
            atom_string(const char *s) : atom(ATOM_TYPE_STRING, TOKEN_FLOAT), v_string(s) {}

            atom_string(const std::string &s): atom_string(s.c_str()) {}

            virtual ~atom_string() {}
    };
}


#endif
