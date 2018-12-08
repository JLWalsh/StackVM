#ifndef LONG_H
#define LONG_H

#include "executor.h"

STATE op_lpush(VM* vm);
STATE op_ladd(VM* vm);
STATE op_lsub(VM* vm);
STATE op_ldiv(VM* vm);
STATE op_lmul(VM* vm);
STATE op_land(VM* vm);
STATE op_lor(VM* vm);
STATE op_lxor(VM* vm);
STATE op_lnot(VM* vm);
STATE op_llshift(VM* vm);
STATE op_lrshift(VM* vm);

STATE op_ulpush(VM* vm);
STATE op_uladd(VM* vm);
STATE op_ulsub(VM* vm);
STATE op_uldiv(VM* vm);
STATE op_ulmul(VM* vm);
STATE op_uland(VM* vm);
STATE op_ulor(VM* vm);
STATE op_ulxor(VM* vm);
STATE op_ulnot(VM* vm);
STATE op_ullshift(VM* vm);
STATE op_ulrshift(VM* vm);

#endif /* LONG_H */
