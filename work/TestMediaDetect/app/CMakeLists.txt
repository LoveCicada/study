
set(NAME_BINART #{CURRENT_DIR})
aux_source_directory("./" SOURCE_FILES)

set(LINK_LIBS_NAME
    "${BINARY_PREFIX}MediaDetect"
)

add_executable(${NAME_BINART} ${SOURCE_FILES})