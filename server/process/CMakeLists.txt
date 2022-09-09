cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME "process")
project(${PROJECT_NAME} VERSION 1.0.0)

# remove last end of "/"
string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})

# get current relative dir name and set target name
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
set (TARGET_NAME ${CURRENT_FOLDER})

message("STATUS" ${TARGET_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

macro(find_src SRC_FILES DIR)
    set (FILTER *.cpp *.h *.c *.cc *.hpp *.qrc)
    foreach(EXTR ${FILTER})
        file(GLOB_RECURSE FILES ${DIR}/${EXTR})
        list(APPEND ${SRC_FILES} ${FILES})
    endforeach() 
endmacro()

find_src(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src)
foreach(FILE ${SRC_FILES})
    message("${FILE}")
endforeach() 

source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SRC_FILES})
add_executable(${TARGET_NAME} ${SRC_FILES})

target_compile_definitions(${TARGET_NAME} PRIVATE
    NOMINMAX
)
if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /MP /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
