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
    vm/math.h
    vm/math.c
    vm/bytecode.h
    vm/bytecode.c
    vm/integer.h
    vm/integer.c
    vm/long.h
    vm/long.c
    vm/libstring.c
    vm/libstring.h
    vm/float.h
    vm/float.c
)

target_include_directories(vm-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(vm main.c)
target_link_libraries(vm vm-lib)

TEST_BIG_ENDIAN(IS_BIG_ENDIAN)

IF(NOT ${IS_BIG_ENDIAN})
    add_definitions( -DVM_IS_LITTLE_ENDIAN )
ENDIF()