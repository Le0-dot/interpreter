cmake_minimum_required(VERSION 3.21.4)

project(lexical_analyzer)

set(LEX_ANALYZER ./lexical_analyzer.hpp ./lexical_analyzer.cpp)

add_library(${PROJECT_NAME} STATIC ${LEX_ANALYZER})

target_include_directories(${PROJECT_NAME} PRIVATE ../token)

add_library(${PROJECT_NAME}_normal STATIC ${LEX_ANALYZER})

target_compile_definitions(${PROJECT_NAME}_normal PUBLIC NORMAL_ORDER)
target_include_directories(${PROJECT_NAME}_normal PRIVATE ../token)
