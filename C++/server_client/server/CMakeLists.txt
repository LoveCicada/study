cmake_minimum_required(VERSION 3.1)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" PROJECT_NAME ${PROJECT_NAME})
project(${PROJECT_NAME} VERSION 1.0.0)

message(STATUS "Project Source Directory: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS CMAKE_PROJECT=${PROJECT_NAME}/${CMAKE_PROJECT_VERSION})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

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
add_executable(${PROJECT_NAME} ${SRC_FILES})

# target_link_libraries(${PROJECT_NAME} PRIVATE
#     utils
# )

target_compile_definitions(${PROJECT_NAME} PRIVATE
    NOMINMAX
)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MP /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

