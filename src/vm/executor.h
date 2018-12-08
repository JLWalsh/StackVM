#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "vm.h"

void op_loadarg(VM* vm);
void op_call(VM* vm);

void op_return(VM* vm);

void op_halt(VM* vm);
void op_print(VM* vm);

// Pointer & memory operations
void op_ppush(VM* vm);
void op_alloc(VM* vm);
void op_dealloc(VM* vm);

void op_exguard(VM* vm);
void op_exunguard(VM* vm);

#endif /* EXECUTOR_H */