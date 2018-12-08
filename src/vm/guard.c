#include "guard.h"
#include <malloc.h>

GUARD_STACK guard_stack_init(uint16_t max_guards)
{
    GUARD_STACK stack;
    stack.guards   = (GUARD*)malloc(sizeof(GUARD) * max_guards);
    stack.size     = 0;
    stack.max_size = max_guards;

    return stack;
}

void guard_stack_free(GUARD_STACK stack)
{
    free(stack.guards);
}

GUARD guard_create(UINTEGER ex_code, POINTER jmp_addr)
{
    GUARD guard;
    guard.null     = false;
    guard.ex_code  = ex_code;
    guard.jmp_addr = jmp_addr;
}

void guard_push(GUARD_STACK* stack, GUARD guard)
{
    stack->guards[stack->size++] = guard;
}

GUARD guard_pop(GUARD_STACK* stack)
{
    return stack->guards[--stack->size];
}

GUARD guard_find_matching(GUARD_STACK* stack, EX_CODE ex_code)
{
    while (stack->size > 0) {
        GUARD current = guard_pop(stack);

        if (current.ex_code == ex_code) {
            return current;
        }
    }

    GUARD guard;
    guard.null     = true;
    guard.ex_code  = 0;
    guard.jmp_addr = 0;

    return guard;
}

bool guard_is_null(GUARD guard)
{
    return guard.null;
}