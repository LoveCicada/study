
cmake_minimum_required(VERSION 3.10)

make_project_name(TARGET_NAME)
message("STATUS" ${TARGET_NAME})

aux_source_directory(. SRC_FILES)

add_executable(${TARGET_NAME} ${SRC_FILES})

