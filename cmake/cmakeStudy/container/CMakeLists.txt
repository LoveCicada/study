
cmake_minimum_required(VERSION 3.10)
project(ContainerTest)
include_directories(include)
file(GLOB INCLUDE "include/*.h")
file(GLOB SOURCE "src/*.cpp" "app/main.cpp")
add_executable(TemplateContainerTest ${INCLUDE} ${SOURCE})
