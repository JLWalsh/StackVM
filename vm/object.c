#include "object.h"
#include <stdlib.h>

void object_free(OBJECT obj)
{
    if (obj.type == T_PTR) {
        free(obj.val.ptr_val);
    }

    if (obj.type == T_STR) {
        free(obj.val.str_val);
    }
}

OBJECT object_of_int(INTEGER int_val)
{
    OBJECT object;
    object.type        = T_INT;
    object.val.int_val = int_val;

    return object;
}

OBJECT object_of_str(char* str_val)
{
    OBJECT object;
    object.type        = T_STR;
    object.val.str_val = str_val;

    return object;
}

OBJECT object_of_ptr(void* ptr_val)
{
    OBJECT object;
    object.type        = T_PTR;
    object.val.ptr_val = ptr_val;

    return object;
}

OBJECT object_parse(STREAM* stream)
{
    OBJECT_TYPE type = *((OBJECT_TYPE*)stream_advance(stream, sizeof(OBJECT_TYPE)));

    switch (type) {
    case T_INT: {
        INTEGER int_val = *((INTEGER*)stream_advance(stream, sizeof(INTEGER)));

        return object_of_int(int_val);
    }
    case T_STR: {
        stream_select_start(stream);

        while (*stream_peek(stream) != '\0') {
            stream_advance(stream, sizeof(char));
        }

        char* str_val = stream_select_end(stream);

        return object_of_str(str_val);
    }
    case T_PTR: {
        POINTER ptr_addr = *((POINTER*)stream_advance(stream, sizeof(POINTER)));

        return object_of_ptr((void*)ptr_addr);
    }
    }
}