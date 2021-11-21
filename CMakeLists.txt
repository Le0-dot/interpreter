cmake_minimum_required(VERSION 3.21.4)

project(interpreter)

set(EXECUTABLE_OUTPUT_PATH ../bin/)
file(MAKE_DIRECTORY ./cmake/)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(MAIN ./src/main.cpp)
set(TOKEN ./src/token/token.hpp ./src/token/types.hpp ./src/token/types.cpp)
set(SYMBOLS ./src/tables/symbols.hpp ./src/tables/symbols.cpp)
set(TABLES ./src/tables/parse_table/parse_table.hpp ./src/tables/parse_table/parse_table.cpp
	    ./src/tables/todo_table/todo_table.hpp ./src/tables/todo_table/todo_table.cpp)
set(LEX_ANALYZER ./src/lexical_analyzer/lexical_analyzer.hpp ./src/lexical_analyzer/lexical_analyzer.cpp)
set(PARSER ./src/parser/parser.hpp ./src/parser/parser.cpp)

add_executable(${PROJECT_NAME} ${MAIN} ${TOKEN} ${SYMBOLS} ${TABLES} ${LEX_ANALYZER} ${PARSER})
