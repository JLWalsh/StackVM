enable_testing()

add_executable(vm-test main.c)
target_link_libraries(vm-test vm-lib)