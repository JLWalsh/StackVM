#ifndef FLOAT_H
#define FLOAT_H

#include "executor.h"

STATE op_fpush(VM* vm);
STATE op_fadd(VM* vm);
STATE op_fsub(VM* vm);
STATE op_fdiv(VM* vm);
STATE op_fmul(VM* vm);
STATE op_fprint(VM* vm);

#endif /* FLOAT_H */
