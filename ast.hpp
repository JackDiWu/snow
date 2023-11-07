#ifndef _SNOW_AST_H_
#define _SNOW_AST_H_

#include "defs.h"

namespace snow {

    typedef enum {
        ATOM_TYPE_UNKNOW,

        ATOM_TYPE_INT,
        ATOM_TYPE_UINT,
        ATOM_TYPE_FLOAT,

        ATOM_TYPE_STRING
    } atom_type;

    class atom {
        public:
            atom_type type;

            std::shared_ptr<atom> L, R, T;

        public:
            atom(atom_type tp) : type(tp) {}

            virtual ~atom() {}
    };

    class atom_number : public atom {
        public:
            int64_t v_int64;

            uint64_t v_uint64;

            double v_float64;

        public:
            atom_number(int v) : atom(ATOM_TYPE_INT), v_int64(v) {}

            atom_number(unsigned int v) : atom(ATOM_TYPE_UINT), v_uint64(v) {}

            atom_number(int64_t v) : atom(ATOM_TYPE_INT), v_int64(v) {}

            atom_number(uint64_t v) : atom(ATOM_TYPE_UINT), v_uint64(v) {}

            atom_number(double v) : atom(ATOM_TYPE_FLOAT), v_float64(v) {}

            virtual ~atom_number() {}
    };

    class atom_string : public atom {
        public:
            std::string v_string;

        public:
            atom_string(const char *s) : atom(ATOM_TYPE_STRING), v_string(s) {}

            atom_string(const std::string &s): atom(ATOM_TYPE_STRING), v_string(s) {}

            virtual ~atom_string() {}
    };
}


#endif
