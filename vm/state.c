#include "state.h"

STATE state_create(POINTER instruction_ptr, STACK* stack)
{
    STATE state;
    state.instruction_ptr   = instruction_ptr;
    state.program_start_ptr = instruction_ptr;
    state.frame_offset      = stack_position(stack);
    state.running           = true;

    return state;
}