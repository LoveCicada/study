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

# ******************************** Platform ********************************
message(STATUS "Detecting platform: ${CMAKE_SYSTEM}")
if(UNIX)
	execute_process(COMMAND cat /etc/os-release COMMAND grep ^ID= OUTPUT_VARIABLE OS_ID)
	string(REGEX REPLACE "ID=['\"]*([^'\"]+)['\"\r\n ]+" "\\1" OS_ID ${OS_ID})
	execute_process(COMMAND cat /etc/os-release COMMAND grep ^VERSION_ID= OUTPUT_VARIABLE OS_VERSION_ID)
	string(REGEX REPLACE "VERSION_ID=['\"]*([^'\"]+)['\"\r\n ]+" "\\1" OS_VERSION_ID ${OS_VERSION_ID})
	set(OS_VERSION "${OS_ID} ${OS_VERSION_ID}")
	set(REGEX_CURRENT_DIR ".*/(.*)")
	# link_libraries(pthread stdc++fs dl gomp)
elseif(WIN32)
	set(OS_VERSION "Windows")
	set(REGEX_CURRENT_DIR ".*\\(.*)")
else()
	message(FATAL_ERROR "Unsupported platform: ${CMAKE_SYSTEM}")
endif()
message(STATUS "OS version: ${OS_VERSION}")
# ******************************** Platform ********************************


# 设置库名前缀
set(BINARY_PREFIX "CXE")

add_subdirectory("./MediaDetect")
add_subdirectory("./app")



