cmake_minimum_required(VERSION 3.11-3.18)
project(nn)

file (GLOB SOURCES src/*.c)
include_directories(include)
add_executable(neat ${SOURCES} main.c)
target_include_directories(neat PUBLIC include/)
enable_testing()
add_subdirectory(tests)
