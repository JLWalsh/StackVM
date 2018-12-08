#ifndef STATE_H
#define STATE_H

#include "executable.h"
#include "guard.h"
#include "stream.h"
#include "type.h"
#include <stdbool.h>

typedef struct STATE_T {
    POINTER     instruction_ptr;
    INTEGER     frame_position;
    bool        running;
    INTEGER     exit_code;
    GUARD_STACK guards;
} STATE;

STATE state_create(EXECUTABLE executable);

#endif /* STATE_H */
