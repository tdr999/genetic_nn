cmake_minimum_required(VERSION 3.11-3.18)
add_executable(genome_tests genome_tests.c)
add_test(genome genome_tests)
add_test(genome2 genome_tests)