#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "stack.h"
#include "state.h"
#include "stream.h"
#include <stdint.h>

typedef STATE (*EXECUTOR)(STACK* stack, STREAM* program, STATE state);

STATE op_loadarg(STACK* stack, STREAM* program, STATE state);
STATE op_call(STACK* stack, STREAM* program, STATE state);
STATE op_return(STACK* stack, STREAM* program, STATE state);
STATE op_halt(STACK* stack, STREAM* program, STATE state);
STATE op_print(STACK* stack, STREAM* program, STATE state);

// Pointer operations
STATE op_ppush(STACK* stack, STREAM* program, STATE vm);

// String opertions
STATE op_scat(STACK* stack, STREAM* program, STATE VM);
STATE op_sprint(STACK* stack, STREAM* program, STATE VM);

// Integer operations
STATE op_iload(STACK* stack, STREAM* program, STATE VM);
STATE op_ipush(STACK* stack, STREAM* program, STATE vm);
STATE op_iadd(STACK* stack, STREAM* program, STATE vm);
STATE op_isub(STACK* stack, STREAM* program, STATE vm);
STATE op_imul(STACK* stack, STREAM* program, STATE vm);
STATE op_idiv(STACK* stack, STREAM* program, STATE vm);
STATE op_iand(STACK* stack, STREAM* program, STATE vm);
STATE op_inot(STACK* stack, STREAM* program, STATE vm);
STATE op_ixor(STACK* stack, STREAM* program, STATE vm);
STATE op_ior(STACK* stack, STREAM* program, STATE vm);

#endif /* EXECUTOR_H */