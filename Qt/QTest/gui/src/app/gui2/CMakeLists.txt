cmake_minimum_required(VERSION 3.10)

make_project_name(TARGET_NAME)
message(STATUS ${TARGET_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS QT_DIR=$ENV{QT_DIR})
find_program(QMAKE_EXECUTABLE NAMES qmake HINTS $ENV{QT_DIR} PATH_SUFFIXES bin)
execute_process(COMMAND ${QMAKE_EXECUTABLE} -query QT_VERSION OUTPUT_VARIABLE QT_VERSION)
if (QT_VERSION)
    message(STATUS "Qt version is ${QT_VERSION}")
    string(REPLACE "." ";" QT_VERSION_LIST ${QT_VERSION})
    list(GET QT_VERSION_LIST 0 QT_VERSION_MAJOR)
    set(Qt "Qt${QT_VERSION_MAJOR}")
else()
    message(WARNING "Not found valid qt version! could not config [${TARGET_NAME}] project")
    return()
endif()

list(PREPEND CMAKE_PREFIX_PATH $ENV{QT_DIR})
find_package(${Qt} COMPONENTS Widgets Core Gui REQUIRED)

find_src(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
add_executable(${TARGET_NAME} ${SRC_FILES})

target_link_libraries(${TARGET_NAME} PUBLIC
    ${Qt}::Widgets
    ${Qt}::Core
    ${Qt}::Gui
)

target_compile_definitions(${TARGET_NAME} PRIVATE
    NOMINMAX
)

message(STATUS ${BUILD_TESTING})

if (${BUILD_TESTING})
    find_test_src(TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR})
    set(TEST_PROJECT_NAME test_${TARGET_NAME})
    add_executable(${TEST_PROJECT_NAME} ${TEST_FILES})
    set_property(TARGET ${TEST_PROJECT_NAME} PROPERTY FOLDER "Test")
    source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TEST_FILES})
    target_include_directories(${TEST_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    find_package(${Qt} COMPONENTS Test REQUIRED)
    target_link_libraries(${TEST_PROJECT_NAME} PRIVATE
        ${Qt}::Widgets
        ${Qt}::Core
        ${Qt}::Gui
        ${Qt}::Test
    )
    add_test(NAME ${TEST_PROJECT_NAME} COMMAND ${TEST_PROJECT_NAME})
endif()
