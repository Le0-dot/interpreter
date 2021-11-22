cmake_minimum_required(VERSION 3.21.4)

project(parser)

set(PARSER ./parser.hpp ./parser.cpp)

add_library(${PROJECT_NAME} STATIC ${PARSER})

target_include_directories(${PROJECT_NAME} PRIVATE ../token ../tables
    ../tables/parse_table ../tables/todo_table)
target_link_libraries(${PROJECT_NAME} token)
