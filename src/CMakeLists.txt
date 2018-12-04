add_library(vm-lib STATIC
    vm/constants.c
    vm/constants.h
    vm/executable.c
    vm/executable.h
    vm/executor.c
    vm/executor.h
    vm/heap.c
    vm/heap.h
    vm/object.c
    vm/object.h
    vm/opcode.h
    vm/stack.c
    vm/stack.h
    vm/state.c
    vm/state.h
    vm/stream.c
    vm/stream.h
    vm/type.h
    vm/vm.c
    vm/vm.h
    vm/vmstring.c
    vm/vmstring.h
)

target_include_directories(vm-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(vm main.c)
target_link_libraries(vm vm-lib)