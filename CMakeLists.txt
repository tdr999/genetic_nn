cmake_minimum_required(VERSION 3.11-3.18)
project(nn)

file (GLOB SOURCES src/*.c)
include_directories(./include)
add_library(nn STATIC ${SOURCES})

target_compile_options(nn PRIVATE
	$<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
	$<$<NOT:$<CXX_COMPILER_ID:MSVC>>
)

target_include_directories(nn PUBLIC include/)