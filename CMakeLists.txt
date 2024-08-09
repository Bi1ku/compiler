cmake_minimum_required(VERSION 3.30)
project(compiler)

add_executable(${PROJECT_NAME} ./src/main.c)

# lexer
add_library(lexer SHARED ./src/lexer.c)
target_link_libraries(${PROJECT_NAME} lexer)

# parser
add_library(parser SHARED ./src/parser.c)
target_link_libraries(${PROJECT_NAME} parser)

# actions
add_library(actions SHARED ./src/actions.c)
target_link_libraries(${PROJECT_NAME} actions)
