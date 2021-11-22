cmake_minimum_required(VERSION 3.21.4)

project(parse_table)

set(PARSE_TABLE ./parse_table.hpp ./parse_table.cpp)

add_library(${PROJECT_NAME} STATIC ${PARSE_TABLE})

target_include_directories(${PROJECT_NAME} PRIVATE ../ ../../token)
target_link_libraries(${PROJECT_NAME} symbols token)
