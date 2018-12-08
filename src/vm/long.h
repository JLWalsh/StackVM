#ifndef LONG_H
#define LONG_H

#include "executor.h"

STATE op_lpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ladd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_land(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lxor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lnot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_llshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_lrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_ulpush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uladd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulsub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulmul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uland(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulxor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulnot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ullshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ulrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* LONG_H */
