#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "heap.h"
#include "stack.h"
#include "state.h"
#include "stream.h"
#include <stdint.h>

typedef STATE (*EXECUTOR)(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_loadarg(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_call(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_return(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_halt(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_print(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// Pointer & memory operations
STATE op_ppush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_alloc(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_dealloc(STACK* stack, STREAM* program, HEAP* heap, STATE state);

// String operations
STATE op_scat(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_sprint(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_isub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_idiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_imul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iand(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ior(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ixor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_inot(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* EXECUTOR_H */