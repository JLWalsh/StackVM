enable_testing()

add_executable(vm-test test_heap.c)
 
target_link_libraries(vm-test vm-lib unity)
 
add_test(test_heap vm-test)