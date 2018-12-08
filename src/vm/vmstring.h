#ifndef STRING_H
#define STRING_H

#include "executor.h"

STATE op_scat(STACK* stack, STREAM* program, HEAP* heap, STATE state);
STATE op_sprint(STACK* stack, STREAM* program, HEAP* heap, STATE state);

#endif /* STRING_H */
