
function(make_project_name OUT_NAME)
    STRING(REGEX REPLACE ".*/(.*)" "\\1" P_NAME ${CMAKE_CURRENT_SOURCE_DIR})
    set(${OUT_NAME} ${P_NAME} PARENT_SCOPE)
endfunction()

function(enable_nasm)
    if(UNIX AND NOT APPLE)
        set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
    elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
        if (CMAKE_CL_64)
            set(CMAKE_ASM_NASM_OBJECT_FORMAT win64)
        else()
            set(CMAKE_ASM_NASM_OBJECT_FORMAT win32)
        endif()
    else()
        set(CMAKE_ASM_NASM_OBJECT_FORMAT bin)
    endif()
    set(CMAKE_ASM_NASM_LINK_EXECUTABLE "nasm <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    enable_language(ASM_NASM)
endfunction(enable_nasm)

macro(config_install PROJECT)
    if(WIN32)
        install(
            TARGETS ${PROJECT}
            RUNTIME DESTINATION bin
        )
    else(WIN32)
        install(
            TARGETS ${PROJECT}
            LIBRARY DESTINATION lib
            PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ
        )
    endif(WIN32)
endmacro()

