cmake_minimum_required(VERSION 3.11-3.18)
add_executable(genome_tests ${SOURCES} genome_tests.c)
add_test(NAME genome COMMAND genome_tests)