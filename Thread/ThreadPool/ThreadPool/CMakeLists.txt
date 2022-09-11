
cmake_minimum_required(VERSION 3.10)
project(threadpool)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(threadpool main.cpp)
target_link_libraries(threadpool pthread)