enable_testing()

macro(vm_add_test name)
    add_executable(${name} ${name}.c ${ARGN})
    target_link_libraries(${name} vm-lib unity)
    add_test(${name} ${name})
endmacro()

vm_add_test(test_heap)
vm_add_test(test_math)
vm_add_test(test_bytecode)
vm_add_test(test_executor)