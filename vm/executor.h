#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdint.h>
#include "stack.h"
#include "stream.h"

typedef char* (*EXECUTOR)(STACK* stack, char* instruction_ptr, STREAM* program);

char* halt_executor(STACK *stack, char *instruction_ptr, STREAM *program);

char* nop_executor(STACK *stack, char *instruction_ptr, STREAM *program);

char* push_executor(STACK *stack, char *instruction_ptr, STREAM *program);

char* pop_executor(STACK *stack, char *instruction_ptr, STREAM *program);

#endif /* EXECUTOR_H */
