cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "build type")

project(wfrest_usage
		LANGUAGES C CXX
)

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

add_executable(HttpServerDemo HttpServerDemo.cpp)
target_link_libraries(HttpServerDemo ${WFREST_LIB})

add_executable(HttpServerDemo2 HttpServerDemo2.cpp)
target_link_libraries(HttpServerDemo2 ${WFREST_LIB})