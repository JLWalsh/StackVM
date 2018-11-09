#include "state.h"

STATE state_create(char* instruction_ptr, char* frame_ptr)
{
    STATE state;
    state.instruction_ptr   = instruction_ptr;
    state.frame_ptr         = frame_ptr;
    state.program_start_ptr = instruction_ptr;

    return state;
}