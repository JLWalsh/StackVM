#ifndef LONG_H
#define LONG_H

#include "executor.h"

void op_lpush(VM* vm);
void op_ladd(VM* vm);
void op_lsub(VM* vm);
void op_ldiv(VM* vm);
void op_lmul(VM* vm);
void op_land(VM* vm);
void op_lor(VM* vm);
void op_lxor(VM* vm);
void op_lnot(VM* vm);
void op_llshift(VM* vm);
void op_lrshift(VM* vm);

void op_ulpush(VM* vm);
void op_uladd(VM* vm);
void op_ulsub(VM* vm);
void op_uldiv(VM* vm);
void op_ulmul(VM* vm);
void op_uland(VM* vm);
void op_ulor(VM* vm);
void op_ulxor(VM* vm);
void op_ulnot(VM* vm);
void op_ullshift(VM* vm);
void op_ulrshift(VM* vm);

#endif /* LONG_H */
