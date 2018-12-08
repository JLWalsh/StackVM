#ifndef FLOAT_H
#define FLOAT_H

#include "executor.h"

STATE op_fpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fdiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_fprint(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* FLOAT_H */
