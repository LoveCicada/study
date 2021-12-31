# media detect library
cmake_minimum_required(VERSION 3.16)

# -- set project name -- #
set (PROJECT_NAME "CEXMediaDetect")

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

set(BINARY_PREFIX "CXE")
set(NAME_BINARY ${BINARY_PREFIX}${CURRENT_DIR}) 
# libCXEMediaDetect.so

aux_source_directory("./src" SOURCE_FILES)

set(LINK_LIB_SOBEY_SDK
    "VXCutlistV2Plus"
    )

set(LINK_LIBS
    "${LINK_LIB_SOBEY_SDK}"
    )

link_directories(
    lib
    )


set(LINK_LIBRARIES)
LINK_LIBRARIES

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

target_link_libraries()