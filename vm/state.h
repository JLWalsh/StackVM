#ifndef STATE_H
#define STATE_H

#include "type.h"

typedef struct STATE_T {
    POINTER instruction_ptr;
    POINTER frame_ptr;
} STATE;

#endif /* STATE_H */
