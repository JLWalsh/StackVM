#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "stack.h"
#include "state.h"
#include "stream.h"
#include <stdint.h>

typedef STATE (*EXECUTOR)(STACK* stack, STREAM* program, STATE state);

STATE op_push(STACK* stack, STREAM* program, STATE state);
STATE op_loadarg(STACK* stack, STREAM* program, STATE state);
STATE op_add(STACK* stack, STREAM* program, STATE state);
STATE op_call(STACK* stack, STREAM* program, STATE state);
STATE op_return(STACK* stack, STREAM* program, STATE state);
STATE op_halt(STACK* stack, STREAM* program, STATE state);
STATE op_print(STACK* stack, STREAM* program, STATE state);

#endif /* EXECUTOR_H */