# media detect library
cmake_minimum_required(VERSION 3.16)

# -- set project name -- #
set (PROJECT_NAME "TestMediaDetect")

# -- project name -- #
project(${PROJECT_NAME})

# -- Basic Setting Begin -- #
message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Compiler version: ")
set(CMAKE_CXX_STANDARD 11)

# -- -- #

# -- GUN standard -- #
add_definitions("-D_GUN_SOURCE")

# -- Basic Setting End -- #

# 设置库名前缀
set(BINARY_PREFIX "CXE")

add_subdirectory("./MediaDetect")
add_subdirectory("./app")



