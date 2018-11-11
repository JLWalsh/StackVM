#include "state.h"

STATE state_create(VM vm, EXECUTABLE executable)
{
    STATE state;
    state.instruction_ptr   = stream_position(&vm.program);
    state.program_start_ptr = stream_start_of(&vm.program);
    state.frame_offset      = stack_position(&vm.stack);
    state.running           = true;
    state.exit_code         = 0;
    state.constants         = executable.constants;

    return state;
}