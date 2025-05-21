cmake_minimum_required(VERSION 3.31)
project(peed C)

set(CMAKE_C_STANDARD 99)

add_executable(fibonacci_exec fibonacci/main.c)
add_executable(passagem_exec passagemReferencia/main.c)
add_executable(substring_exec substring/main.c)
add_executable(media_exec matriz/media_alunos_disciplina/main.c)
add_executable(multiplicacao_exec matriz/multiplicacao/main.c)
