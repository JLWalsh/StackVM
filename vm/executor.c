#include "executor.h"

uint64_t nop_executor(STACK *stack, uint64_t instruction_ptr) {
  return instruction_ptr + 1;
}

uint64_t push_executor(STACK *stack, uint64_t instruction_ptr) {
  uint16_t type = (uint16_t) (instruction_ptr + 1);
  
}