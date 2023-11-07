/*
 * @Author: Jack
 * @Date: 2023-11-07 14:31:31
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 15:07:44
 */
#ifndef _SNOW_SYMBOL_H_
#define _SNOW_SYMBOL_H_

#include "ast.hpp"

namespace snow {

    class symbol {
        public:
            snow::atom_type atom_type;

        public:
            symbol(snow::atom_type at) : atom_type(at) {}

            virtual ~symbol() {}
    };

    class symbols {
        public:
            std::stack<std::shared_ptr<std::map<std::string, snow::symbol>>> system;

        public:
            symbols() {
                push();
            }

            virtual ~symbols() {}

        public:
            void push() {
                system.push(std::make_shared<std::map<std::string, snow::symbol>>());
            }

            void pop() {
                system.pop();
            }

            void put(const std::string &name) {
                // system.top()->insert_or_assign("fsdfdsdf", snow::symbol());
            }
    };
}


#endif
