cmake_minimum_required (VERSION 3.20)

include(ExternalProject)

# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set(CMAKE_POLICY_DEFAULT_CMP0091 NEW)
set(CMAKE_MSVC_RUNTIME_LIBRARY MultiThreaded)

project (FMITutorial)

set(FMI_ARCHITECTURE "" CACHE STRING "FMI Architecture")
set_property(CACHE FMI_ARCHITECTURE PROPERTY STRINGS "" "aarch64" "x86" "x86_64")

if (NOT FMI_ARCHITECTURE)
  if (${CMAKE_HOST_SYSTEM_PROCESSOR} MATCHES "AMD64|x86_64")
    set(FMI_ARCHITECTURE "x86_64")
  elseif (${CMAKE_HOST_SYSTEM_PROCESSOR} MATCHES "aarch64")
    set(FMI_ARCHITECTURE "aarch64")
  else ()
    message(FATAL_ERROR "Unknown System Architecture: ${CMAKE_SYSTEM_PROCESSOR}")
  endif ()
endif ()

# hide internal functions
if (UNIX AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
endif()

if (WIN32)
    set(FMI_PLATFORM "${FMI_ARCHITECTURE}-windows")
elseif (APPLE)
    set(FMI_PLATFORM "${FMI_ARCHITECTURE}-darwin")
else ()
    set(FMI_PLATFORM "${FMI_ARCHITECTURE}-linux")
endif ()

if (APPLE)

  if ("${FMI_ARCHITECTURE}" STREQUAL "x86_64")
    set(CMAKE_OSX_ARCHITECTURES "x86_64")
  elseif ("${FMI_ARCHITECTURE}" STREQUAL "aarch64")
    set(CMAKE_OSX_ARCHITECTURES "arm64")
  else ()
    message(FATAL_ERROR "Unsupported architecture darwin: ${FMI_ARCHITECTURE}")
  endif ()

endif ()

message(STATUS "FMI_PLATFORM: " ${FMI_PLATFORM})

ExternalProject_Add(
  fmisdk

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/fmisdk"
  BINARY_DIR "${CMAKE_BINARY_DIR}/fmisdk-${FMI_PLATFORM}"
  INSTALL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fmisdk-${FMI_PLATFORM}"

  CMAKE_ARGS
    -D CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -D FMI_ARCHITECTURE=${FMI_ARCHITECTURE}
    -D FMI_PLATFORM=${FMI_PLATFORM}
    -D CMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/fmisdk/fmisdk-${FMI_PLATFORM}

#   BUILD_BYPRODUCTS
#     "${CMAKE_BINARY_DIR}/fmisdk-${FMI_PLATFORM}/install/lib/fmisdk.lib"
)

#  ExternalProject_Add(
#    protobuf
#
#    URL https://protobuf.googlecode.com/files/protobuf-2.5.0.tar.gz
#    
#    UPDATE_COMMAND ""
#    PATCH_COMMAND ""
#    
#    SOURCE_DIR "${CMAKE_SOURCE_DIR}/3rdparty/protobuf"
#    CONFIGURE_COMMAND ""
#
#    BUILD_COMMAND devenv /upgrade ${CMAKE_SOURCE_DIR}/3rdparty/protobuf/vsprojects/protobuf.sln
#      COMMAND msbuild /p:OutputPath=${GLOBAL_OUTPUT_PATH}/protobuf/ /p:OutDir=${GLOBAL_OUTPUT_PATH}/protobuf/ ${CMAKE_SOURCE_DIR}/3rdparty/protobuf/vsprojects/protobuf.sln
#
#    INSTALL_COMMAND ""
#    
#    TEST_COMMAND ""
#  )

add_subdirectory(export)

add_subdirectory(import)
