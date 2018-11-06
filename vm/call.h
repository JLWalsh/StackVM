#ifndef CALL_H
#define CALL_H

#include "type.h"

typedef struct CALL_T {
    POINTER return_address;
    POINTER frame_pointer;
    INTEGER num_args;
} CALL;

#endif /* CALL_H */
