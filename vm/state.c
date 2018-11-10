#include "state.h"

STATE state_create(char* instruction_ptr, char* frame_ptr)
{
    STATE state;
    state.instruction_ptr   = instruction_ptr;
    state.frame_ptr         = 0;
    state.program_start_ptr = instruction_ptr;

    return state;
}