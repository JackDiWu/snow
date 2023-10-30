/*
 * @Author: Jack
 * @Date: 2023-10-30 11:12:37
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 12:02:17
 */
#ifndef _SNOW_PARSER_HPP_
#define _SNOW_PARSER_HPP_

#include "defs.h"
namespace snow {
    class scanner {
        protected:
            _yyparse_t _parser;

            yyparse_t parser;

        public:
            scanner(const char *data, int size);
            
            virtual ~scanner();

        public:
            virtual int resolve();
    };

}



#endif
