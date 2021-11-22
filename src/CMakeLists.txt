cmake_minimum_required(VERSION 3.21.4)

add_subdirectory(token)
add_subdirectory(lexical_analyzer)
add_subdirectory(parser)
add_subdirectory(tables)

set(MAIN ./main.cpp)

add_executable(${PROJECT_NAME} ${MAIN})

target_include_directories(${PROJECT_NAME} PRIVATE token parser lexical_analyzer
    tables tables/parse_table tables/todo_table)
target_link_libraries(${PROJECT_NAME} token lexical_analyzer parser symbols parse_table todo_table)
