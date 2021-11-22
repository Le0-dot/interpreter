cmake_minimum_required(VERSION 3.21.4)

project(todo_table)

set(TODO_TABLE ./todo_table.hpp ./todo_table.cpp)

add_library(${PROJECT_NAME} STATIC ${TODO_TABLE})

target_include_directories(${PROJECT_NAME} PRIVATE ../ ../../token)
target_link_libraries(${PROJECT_NAME} symbols)
