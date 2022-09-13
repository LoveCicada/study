
cmake_minimum_required(VERSION 3.10)
project(safe_queue)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(safe_queue main.cpp)
target_link_libraries(safe_queue pthread)