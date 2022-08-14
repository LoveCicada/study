cmake_minimum_required(VERSION 3.10)

include(tools/cmake/find_src.cmake)
include(tools/cmake/project_helper.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS On)
option(BUILD_TESTING "" ON)

project(gui)

if(MSVC)
    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} /MP")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif(MSVC)

set(CMAKE_CXX_STANDARD 17) #-stdc++11
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) #-fPIC
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/)

if(NOT CMAKE_CONFIGURATION_TYPES)
    set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
else()
    set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$<CONFIG>/)
endif()


# set(DEPENDS_DIR ${CMAKE_SOURCE_DIR}/depends)

include_directories(
    
    )
link_directories(
    
    )

if (${BUILD_TESTING})
    enable_testing()
endif()

add_subdirectory(src)
