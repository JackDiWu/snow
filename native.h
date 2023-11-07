/*
 * @Author: Jack
 * @Date: 2023-11-07 09:52:17
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 10:15:19
 */
#ifndef _SNOW_TYPES_H_
#define _SNOW_TYPES_H_

/***************** types ******************/
namespace snow {

    typedef enum {
        ATOM_TYPE_UNKNOW,

        ATOM_TYPE_INT,
        ATOM_TYPE_UINT,
        ATOM_TYPE_FLOAT,

        ATOM_TYPE_STRING
    } atom_type;

    typedef union {
        int64_t v_int;
        uint64_t v_uint;
        double v_float;
    } atom_number;
    
    class atom {
        public:
            atom_type type;
            
            std::string v_string;
            
            atom_number v_number;

        public:
            atom();

            virtual ~atom();

        public:
    };

}



/***************** defs ******************/
#define YYSTYPE        long



/***************** functions ******************/
void yyerror (void *parser, char const *s);

#endif
