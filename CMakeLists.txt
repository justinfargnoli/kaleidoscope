cmake_minimum_required(VERSION 3.16)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 14)

add_executable(kaleidoscope main.cpp lex.cpp lex.h)