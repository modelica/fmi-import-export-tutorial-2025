cmake_minimum_required (VERSION 3.15)

project (import)

if (MSVC)
  add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()

add_executable(import
	../Reference-FMUs/include/fmi3Functions.h
	../Reference-FMUs/include/fmi3FunctionTypes.h
	../Reference-FMUs/include/fmi3PlatformTypes.h	
	../Reference-FMUs/include/FMI.h
	../Reference-FMUs/include/FMI3.h
	../Reference-FMUs/src/FMI.c
	../Reference-FMUs/src/FMI3.c
	main.c
)

target_include_directories(import PUBLIC "../Reference-FMUs/include")
