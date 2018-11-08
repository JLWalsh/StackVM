#ifndef STATE_H
#define STATE_H

#include "type.h"

typedef struct STATE_T {
    char* instruction_ptr;
    char* frame_ptr;
} STATE;

STATE state_create(char* instruction_ptr, char* frame_ptr);

#endif /* STATE_H */
