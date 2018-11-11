#ifndef STATE_H
#define STATE_H

#include "executable.h"
#include "type.h"
#include "vm.h"
#include <stdbool.h>

typedef struct STATE_T {
    POINTER instruction_ptr;
    POINTER program_start_ptr;
    INTEGER frame_offset;
    bool    running;
    INTEGER exit_code;
    void*   constants;
} STATE;

STATE state_create(VM vm, EXECUTABLE executable);

#endif /* STATE_H */
