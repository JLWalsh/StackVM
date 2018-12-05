cmake_minimum_required(VERSION 3.7)
project(svm)
set(CMAKE_C_STANDARD 99)

INCLUDE(TestBigEndian)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib)