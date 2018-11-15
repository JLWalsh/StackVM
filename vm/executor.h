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

// String operations
STATE op_spush(STACK* stack, STREAM* program, STATE vm);

// Integer operations
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