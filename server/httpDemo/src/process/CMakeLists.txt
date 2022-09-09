
cmake_minimum_required(VERSION 3.10)

find_src(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR})

make_project_name(PROJECT_NAME)

add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

