cmake_minimum_required(VERSION 3.21)

include(tools/cmake/find_src.cmake)
include(tools/cmake/project_helper.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS On)

project(manager)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}/MP")
    set(CMAKE_CXX_FLAGS "${CMA_CXX_FLAGS/MP}")
endif()

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) #-fPIC

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)



add_subdirectory(src)