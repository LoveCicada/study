cmake_minimum_required(VERSION 3.20)
 
project(callback)
 
# 查找当前目录下的所有源文件
# 并将名称保存到 SRC_LIST变量
aux_source_directory(. SRC_LIST)
 
add_executable(main ${SRC_LIST})