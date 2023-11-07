/*
 * @Author: Jack
 * @Date: 2023-11-07 14:31:31
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 14:43:29
 */
#ifndef _SNOW_SYMBOL_H_
#define _SNOW_SYMBOL_H_

#include "ast.hpp"

namespace snow {

    class symbol {
        public:
            symbol() {}

            virtual ~symbol() {}
    };

    class symbols {
        public:
            std::stack<std::map<std::string, std::shared_ptr<symbol>>> symbol_stack;

        public:
            symbols() {}

            virtual ~symbols() {}
    };
}


#endif
