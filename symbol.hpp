/*
 * @Author: Jack
 * @Date: 2023-11-07 14:31:31
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 14:34:56
 */
#ifndef _SNOW_SYMBOL_H_
#define _SNOW_SYMBOL_H_

#include "ast.hpp"

namespace snow {

    class symbols {
        public:
            symbols() {}

            virtual ~symbols() {}

        public:
            static std::shared_ptr<symbols> shared() {
                static std::shared_ptr<symbols> system;
                if (!system.get()) {
                    system = std::make_shared<symbols>();
                }
                return system;
            }
    };
}


#endif
