#ifndef GUARD_H
#define GUARD_H

#include "exception.h"
#include "type.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct GUARD_T {
    bool    null;
    EX_CODE ex_code;
    POINTER jmp_addr;
} GUARD;

typedef struct GUARD_STACK_T {
    GUARD*   guards;
    uint16_t max_size;
    uint16_t size;
} GUARD_STACK;

GUARD_STACK guard_init(uint16_t max_guards);

GUARD guard_create(UINTEGER ex_code, POINTER jmp_addr);

void guard_push(GUARD_STACK* stack, GUARD guard);

GUARD guard_pop(GUARD_STACK* stack);

GUARD guard_find_matching(GUARD_STACK* stack, EX_CODE ex_code);

bool guard_is_null(GUARD guard);

#endif /* GUARD_H */
