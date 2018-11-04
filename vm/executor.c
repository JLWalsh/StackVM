#include "executor.h"
#include "opcode.h"
#include "stdio.h"

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

    printf("Pushing type %u\n", obj.type);

    return stream_peek(program) + sizeof(char); // Includes \0
}

char* pop_executor(STACK* stack, char* instruction_ptr, STREAM* program)
{
    OBJECT popped = stack_pop(stack);

    switch (popped.type) {
    case INT: {
        printf("Popped INT: %i\n", popped.val.int_val);
        break;
    }
    case UINT: {
        printf("Popped UINT: %u\n", popped.val.uint_val);
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
