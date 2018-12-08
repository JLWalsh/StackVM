#include "state.h"
#include "guard.h"

STATE state_create(EXECUTABLE executable)
{
    STATE state;
    state.instruction_ptr = 0;
    state.frame_position  = 0;
    state.running         = true;
    state.exit_code       = 0;
    state.guards          = guard_init(100); // TODO find clean way to specify this value

    return state;
}