#include "stack.h"
#include <malloc.h>
#include <stdio.h>

STACK stack_create(uint16_t num_objects)
{
    STACK stack;
    stack.objects  = (STACK_OBJECT*)malloc(sizeof(STACK_OBJECT) * num_objects);
    stack.max_size = num_objects;
    stack.size     = 0;

    return stack;
}

void stack_free(STACK stack)
{
    if (stack.objects != NULL) {
        free(stack.objects);
    }
}

void stack_reset(STACK* stack)
{
    stack->size = 0;
}

STACK_OBJECT stack_top(STACK* stack)
{
    return stack->objects[stack->size];
}

STACK_OBJECT stack_pop(STACK* stack)
{
    return stack->objects[--stack->size];
}

STACK_OBJECT stack_at(STACK* stack, INTEGER position)
{
    return stack->objects[position];
}

void stack_push(STACK* stack, STACK_OBJECT object)
{
    stack->objects[stack->size++] = object;
}

INTEGER stack_size(STACK* stack)
{
    return stack->size;
}