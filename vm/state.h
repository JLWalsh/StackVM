#ifndef STATE_H
#define STATE_H

#include "stack.h"
#include "type.h"
#include <stdbool.h>

typedef struct STATE_T {
    POINTER instruction_ptr;
    POINTER program_start_ptr;
    INTEGER frame_ptr;
    bool    running;
} STATE;

STATE state_create(POINTER instruction_ptr, STACK* stack);

#endif /* STATE_H */
