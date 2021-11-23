cmake_minimum_required(VERSION 3.21.4)

project(interpreter)

set(EXECUTABLE_OUTPUT_PATH ../../bin/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

add_subdirectory(src)
