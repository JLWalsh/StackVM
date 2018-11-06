#include "executor.h"
#include "opcode.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

char* halt_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    printf("Halting");
    return NULL;
}

char* nop_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    printf("Nooooooooooope!");
    return instruction_ptr + sizeof(OPCODE);
}

char* push_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    OBJECT obj = object_parse(program);
    stack_push(stack, obj);

    return stream_peek(program) + 1;
}

char* pop_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    OBJECT popped = stack_pop(stack);

    switch (popped.type) {
    case INT: {
        printf("Popped INT: %i\n", popped.val.int_val);
        break;
    }
    case STR: {
        printf("Popped STR: %s\n", popped.val.str_val);
        break;
    }
    default: {
        printf("Unrecognized type: %u\n", popped.type);
    }
    }

    return instruction_ptr + sizeof(OPCODE);
}

char* dadd_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    OBJECT a = stack_pop(stack);
    OBJECT b = stack_pop(stack);

    if (a.type == b.type) {
        if (a.type == INT) {
            OBJECT c = object_of_int(a.val.int_val + b.val.int_val);

            stack_push(stack, c);
        }

        if (a.type == STR) {
            size_t new_len = strlen(a.val.str_val) + strlen(b.val.str_val) + 1;
            realloc(a.val.str_val, new_len);
            strcat(a.val.str_val, b.val.str_val);

            object_free(b);
            stack_push(stack, a);
        }
    }

    return instruction_ptr + sizeof(OPCODE);
}