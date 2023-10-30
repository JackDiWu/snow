/*
 * @Author: Jack
 * @Date: 2023-10-30 11:12:37
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:23:25
 */
#ifndef _SNOW_PARSER_HPP_
#define _SNOW_PARSER_HPP_

#include "defs.h"
namespace snow {
    class parser {
        protected:
            _yyparse_t _yyparse;

        public:
            parser();
            
            virtual ~parser();

        public:
            virtual int scan(const char *data, int size);
    };

}



#endif
