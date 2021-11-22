cmake_minimum_required(VERSION 3.21.4)

project(token)

set(TOKEN ./token.hpp ./token.cpp ./types.hpp ./types.cpp)

add_library(${PROJECT_NAME} STATIC ${TOKEN})
