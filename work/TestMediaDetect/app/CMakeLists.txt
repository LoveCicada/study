
string(REGEX REPLACE ${REGEX_CURRENT_DIR} "\\1" CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
message("STATUS" ${CURRENT_DIR})
set(NAME_BINART ${CURRENT_DIR})

aux_source_directory("./" DIR_SRCS)

set(LINK_LIBS_NAME
    "${BINARY_PREFIX}MediaDetect"
)

add_executable(${NAME_BINART} ${DIR_SRCS})