#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "stack.h"
#include "state.h"
#include "stream.h"
#include <stdint.h>

typedef STATE (*EXECUTOR)(STACK* stack, STREAM* program, STATE vm);

#endif /* EXECUTOR_H */
