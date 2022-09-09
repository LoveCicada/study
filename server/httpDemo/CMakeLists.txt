cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "build type")
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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

if (NOT "$ENV{LIBRARY_PATH}" STREQUAL "")
	string(REPLACE ":" ";" LIBRARY_PATH $ENV{LIBRARY_PATH})
	set(CMAKE_SYSTEM_LIBRARY_PATH ${LIBRARY_PATH};${CMAKE_SYSTEM_LIBRARY_PATH})
endif ()

if (NOT "$ENV{CPLUS_INCLUDE_PATH}" STREQUAL "")
	string(REPLACE ":" ";" INCLUDE_PATH $ENV{CPLUS_INCLUDE_PATH})
	set(CMAKE_SYSTEM_INCLUDE_PATH ${INCLUDE_PATH};${CMAKE_SYSTEM_INCLUDE_PATH})
endif ()

find_package(OpenSSL REQUIRED)

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/workflow/workflow-config.cmake.in")
	find_package(Workflow REQUIRED CONFIG HINTS ../workflow)
endif ()

find_package(ZLIB REQUIRED)

find_package(wfrest REQUIRED CONFIG HINTS ..)
include_directories(
	${OPENSSL_INCLUDE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${WORKFLOW_INCLUDE_DIR}
	${WFREST_INCLUDE_DIR}
)

link_directories(${WFREST_LIB_DIR} ${WORKFLOW_LIB_DIR})

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -fPIC -pipe -std=gnu90")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -pipe -std=c++11 -fno-exceptions")

if (APPLE)
	set(WFREST_LIB wfrest workflow pthread OpenSSL::SSL OpenSSL::Crypto protobuf z)
else ()
	set(WFREST_LIB wfrest)
endif ()

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
target_link_libraries(${TARGET_NAME} ${WFREST_LIB})

target_compile_definitions(${TARGET_NAME} PRIVATE
    NOMINMAX
)
if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /MP /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
