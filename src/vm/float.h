#ifndef FLOAT_H
#define FLOAT_H

#include "executor.h"

void op_fpush(VM* vm);
void op_fadd(VM* vm);
void op_fsub(VM* vm);
void op_fdiv(VM* vm);
void op_fmul(VM* vm);
void op_fprint(VM* vm);

#endif /* FLOAT_H */
