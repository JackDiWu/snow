#ifndef _SNOW_AST_H_
#define _SNOW_AST_H_

#include "defs.h"
#include "snow.yy.hh"

namespace snow {

    class data {
        public:
            yytoken_kind_t token;

        public:
            data(yytoken_kind_t tk) : token(tk) {}

            virtual ~data() {}
    };

    class data_string : public data {
        public:
            std::string v_string;

        public:
            data_string(yytoken_kind_t tk, const char *str) : data(tk), v_string(str) {}

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
            data_number(yytoken_kind_t tk, const char *str) : data_string(tk, str) {
                switch (token) {
                    case TOKEN_DEC: {
                        v_int64 = strtol(str, NULL, 10);
                        v_string = str;
                        break;
                    }
                    case TOKEN_HEX: {
                        v_uint64 = strtol(str, NULL, 16);
                        v_string = str;
                        break;
                    }
                    case TOKEN_FLOAT: {
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
            value(yytoken_kind_t tk, const char *str) : data_number(tk, str) {}

            virtual ~value() {}
    };

    class expr {
        public:
            snow::value value;

        public:
            expr(yytoken_kind_t tk, const char *str) : value(tk, str) {}

            virtual ~expr() {}

        public:
            virtual const char * text() = 0;
    };

    class expr_binary : public expr {
        public:
            std::shared_ptr<expr> L, R;

        public:
            expr_binary(
                yytoken_kind_t tk, const char *str,
                const std::shared_ptr<expr> &l, const std::shared_ptr<expr> &r
            ) : expr(tk, str), L(l), R(r) {}
    };
}


#endif
