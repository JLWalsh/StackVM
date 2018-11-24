#include "state.h"

STATE state_create(EXECUTABLE executable)
{
    STATE state;
    state.instruction_ptr = 0;
    state.frame_offset    = 0;
    state.running         = true;
    state.exit_code       = 0;
    state.heap            = executable.heap;

    return state;
}