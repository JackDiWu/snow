/*
 * @Author: Jack
 * @Date: 2023-11-07 09:52:17
 * @LastEditors: Jack
 * @LastEditTime: 2023-11-07 10:12:37
 */
#ifndef _SNOW_TYPES_H_
#define _SNOW_TYPES_H_

/***************** types ******************/
namespace snow {

    typedef enum {
        ATOM_TYPE_UNKNOW,

        ATOM_TYPE_INT8,
        ATOM_TYPE_INT16,
        ATOM_TYPE_INT32,
        ATOM_TYPE_INT64,

        ATOM_TYPE_UINT8,
        ATOM_TYPE_UINT16,
        ATOM_TYPE_UINT32,
        ATOM_TYPE_UINT64,

        ATOM_TYPE_FLOAT32,
        ATOM_TYPE_FLOAT64,

        ATOM_TYPE_STRING
    } atom_type;
    
    class atom {
        public:
            atom_type type;

            union integer {
                int8_t v_int8;
                int16_t v_int16;
                int32_t v_int32;
                int64_t v_int64;

                uint8_t v_uint8;
                uint16_t v_uint16;
                uint32_t v_uint32;
                uint64_t v_uint64;

                float v_float32;
                double v_float64;
            };

            std::string v_string;
            

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
