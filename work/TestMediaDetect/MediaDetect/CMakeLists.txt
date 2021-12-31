
# MediaDetect Lib

string(REGEX REPLACE ${REGEX_CURRENT_DIR} "\\1" CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(LIB_NAME "MediaDetect")

# 设置库名 CXEMediaDetect
# set(NAME_BINARY ${BINARY_PREFIX}${LIB_NAME}) 
set(NAME_BINARY ${BINARY_PREFIX}${CURRENT_DIR})

# libCXEMediaDetect.so

# 查找当前目录下的所有源文件
# 并将名称保存到DIR_LIB_SRCS 变量
aux_source_directory("./src" DIR_LIB_SRCS)

# 指定生成 libCXEMediaDetect.so 动态链接库
add_library(${NAME_BINARY} SHARED ${DIR_LIB_SRCS})

# 添加include
include_directories("../include")

# include cmake dir

# 加入 cutlist 库
# add_subdirectory("../lib")
link_directories("../lib")

set(EXTRA_LIBS VXCutlistV2Plus)

# 指定生成目标
target_link_libraries(${NAME_BINARY} PRIVATE ${EXTRA_LIBS})

