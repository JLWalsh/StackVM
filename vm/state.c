#include "state.h"

STATE state_create(POINTER instruction_ptr, EXECUTABLE executable)
{
    STATE state;
    state.instruction_ptr   = instruction_ptr;
    state.program_start_ptr = instruction_ptr;
    state.frame_offset      = 0;
    state.running           = true;
    state.exit_code         = 0;
    state.constants         = executable.constants;

    return state;
}