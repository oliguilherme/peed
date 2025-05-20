cmake_minimum_required(VERSION 3.31)
project(peed C)

set(CMAKE_C_STANDARD 99)

add_executable(fibonacci_exec fibonacci/main.c)
add_executable(passagem_exec passagemReferencia/main.c)
add_executable(substring_exec substring/main.c)
