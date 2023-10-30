/*
 * @Author: Jack
 * @Date: 2023-10-30 11:12:37
 * @LastEditors: Jack
 * @LastEditTime: 2023-10-30 11:33:39
 */
#ifndef _SNOW_PARSER_HPP_
#define _SNOW_PARSER_HPP_

#include "defs.h"
namespace snow {
    class parser {
        protected:
            _yyparse_t _yyparse;

        public:
            parser(const char *data, int size);

            parser(const std::string &text);
            
            virtual ~parser();

        public:
            virtual int scan();
    };

}



#endif
