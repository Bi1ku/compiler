cmake_minimum_required(VERSION 3.30)
project(compiler)

add_executable(${PROJECT_NAME} ./src/main.c)

# lexer
add_library(lexer SHARED ./src/lexer.c)
target_link_libraries(${PROJECT_NAME} lexer)

# parser
add_library(parser SHARED ./src/parser.c)
target_link_libraries(${PROJECT_NAME} parser)

# generator 
add_library(generator SHARED ./src/generator.c)
target_link_libraries(${PROJECT_NAME} generator)

# utils
add_library(utils SHARED ./src/utils.c)

# linking libraries and files
target_link_libraries(${PROJECT_NAME} utils)
target_link_libraries(lexer utils)
target_link_libraries(parser utils)
target_link_libraries(generator utils)
