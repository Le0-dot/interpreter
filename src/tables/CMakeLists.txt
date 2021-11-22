cmake_minimum_required(VERSION 3.21.4)

project(tables)

add_subdirectory(parse_table)
add_subdirectory(todo_table)

set(SYMBOLS ./symbols.hpp ./symbols.cpp)

add_library(symbols STATIC ${SYMBOLS})

target_include_directories(symbols PRIVATE ../token)
