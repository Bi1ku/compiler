cmake_minimum_required(VERSION 3.30)
project(compiler)

add_executable(${PROJECT_NAME} ./src/main.c)
add_library(lexer SHARED ./src/lexer.c)
