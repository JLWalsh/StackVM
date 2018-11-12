#ifndef STATE_H
#define STATE_H

#include "executable.h"
#include "type.h"
#include <stdbool.h>

typedef struct STATE_T {
    POINTER instruction_ptr;
    POINTER program_start_ptr;
    INTEGER frame_offset;
    bool    running;
    INTEGER exit_code;
    void*   constants;
} STATE;

STATE state_create(POINTER instruction_ptr, EXECUTABLE executable);

#endif /* STATE_H */
