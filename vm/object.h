#ifndef INCLUDE_OBJECT
#define INCLUDE_OBJECT

#include "stream.h"
#include <stdint.h>

enum TYPE {
    INT,
    UINT,
    STR,
    PTR
};

typedef struct OBJECT_T {
    uint16_t type;

    union val {
        uint16_t uint_val;
        int16_t int_val;
        char* str_val;
        void* ptr_val;
    } val;

} OBJECT;

OBJECT object_of_int(int16_t int_val);

OBJECT object_of_uint(uint16_t uint_val);

OBJECT object_of_str(char* str_val);

OBJECT object_of_ptr(void* ptr_val);

OBJECT object_parse(STREAM* stream);

#endif