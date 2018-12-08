#ifndef INTEGER_H
#define INTEGER_H

#include "executor.h"

STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_isub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_idiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_imul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_iand(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ior(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ixor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_inot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_ilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_irshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

STATE op_uipush(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uiadd(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uisub(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uidiv(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uimul(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uiand(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uior(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uixor(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uinot(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_uirshift(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* INTEGER_H */
