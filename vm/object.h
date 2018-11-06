#ifndef INCLUDE_OBJECT
#define INCLUDE_OBJECT

#include "stream.h"
#include "type.h"
#include <stdint.h>

typedef struct OBJECT_T {
    OBJECT_TYPE type;

    union val {
        INTEGER int_val;
        char*   str_val;
        void*   ptr_val;
        DOUBLE  dbl_val;
        FLOAT   flt_val;
    } val;

} OBJECT;

void object_free(OBJECT);

OBJECT object_of_int(INTEGER int_val);

OBJECT object_of_str(char* str_val);

OBJECT object_of_ptr(void* ptr_val);

OBJECT object_of_dbl(DOUBLE dbl_val);

OBJECT object_of_flt(FLOAT flt_val);

OBJECT object_parse(STREAM* stream);

#endif