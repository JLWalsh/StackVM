#ifndef INCLUDE_STACK
#define INCLUDE_STACK

#include "object.h"
#include <stdint.h>

typedef struct STACK_T {
    uint16_t max_size;
    uint16_t size;
    OBJECT*  objects;
} STACK;

STACK stack_create(uint16_t num_objects);

void stack_free(STACK stack);

void stack_reset(STACK* stack);

OBJECT stack_pop(STACK* stack);

OBJECT stack_at(STACK* stack, INTEGER position);

void stack_push(STACK* stack, OBJECT object);

OBJECT stack_top(STACK* stack);

INTEGER stack_size(STACK* stack);

#endif