#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdint.h>
#include "stack.h"

typedef uint64_t (*EXECUTOR)(STACK*, uint64_t);

uint64_t nop_executor(STACK *, uint64_t);

uint64_t push_executor(STACK *, uint64_t);

#endif /* EXECUTOR_H */
