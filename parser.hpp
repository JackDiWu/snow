/*
 * @Author: Jack
 * @Date: 2023-10-30 11:12:37
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 09:53:43
 */
#ifndef _SNOW_PARSER_HPP_
#define _SNOW_PARSER_HPP_

#include "defs.h"
#include "native.h"
#include "snow.yy.hh"

#ifdef __cplusplus
extern "C" {
#endif
    
#include "lex.yy.h"

#ifdef __cplusplus
}
#endif


namespace snow {
    class scanner {
        public:
            std::string name;

            void *lexer;

        public:
            scanner(const char *nm, const char *data, int size) : name(nm), lexer(nullptr) {
                yylex_init(&lexer);
                
                yy_scan_bytes(data, size, lexer);

                yyset_lineno(1, lexer);
                yyset_column(0, lexer);
            }
            
            virtual ~scanner() {
                yylex_destroy(lexer);
            }

        public:
            virtual int resolve() {
                return yyparse(this);
            }
    };

}

#endif
