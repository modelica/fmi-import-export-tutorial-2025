cmake_minimum_required (VERSION 3.15)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set (MODEL_NAME model)
set (MODEL_IDENTIFIER model)

project (${MODEL_IDENTIFIER})

if (WIN32)
    set(FMI_PLATFORM windows)
elseif (APPLE)
    set(FMI_PLATFORM darwin)
else ()
    set(FMI_PLATFORM linux)
endif ()

if ("${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
    set (FMI_PLATFORM "x86_64-${FMI_PLATFORM}")
else ()
    set (FMI_PLATFORM "x86-${FMI_PLATFORM}")
endif ()

message(STATUS "FMI_PLATFORM: ${FMI_PLATFORM}")

add_library(${MODEL_IDENTIFIER} SHARED modelDescription.xml sources/model.c)

target_compile_definitions(${MODEL_IDENTIFIER} PUBLIC FMI3_OVERRIDE_FUNCTION_PREFIX)

target_include_directories(${MODEL_IDENTIFIER} PUBLIC
    "../Reference-FMUs/include"
    ${CMAKE_CURRENT_SOURCE_DIR}/sources
)

set_target_properties(${MODEL_IDENTIFIER} PROPERTIES
    PREFIX ""
    RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    LIBRARY_OUTPUT_DIRECTORY         "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    ARCHIVE_OUTPUT_DIRECTORY         "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/binaries/${FMI_PLATFORM}"
)

add_custom_command(TARGET ${MODEL_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E tar cfv "${CMAKE_CURRENT_SOURCE_DIR}/${MODEL_NAME}.fmu" --format=zip
    "sources/"
    "modelDescription.xml"
    "sources/buildDescription.xml"
    "sources/model.c"
    "binaries"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
