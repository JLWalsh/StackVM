#ifndef INCLUDE_STACK
#define INCLUDE_STACK

#include <malloc.h>
#include <stdint.h>

#include "object.h"

typedef struct
{
  uint16_t max_size;
  uint16_t size;
  OBJECT *objects;
} STACK;

STACK stack_create(uint16_t num_objects);

void stack_free(STACK stack);

OBJECT stack_pop(STACK *stack);

void stack_push(STACK *stack, OBJECT object);

OBJECT stack_top(STACK *stack);

#endif