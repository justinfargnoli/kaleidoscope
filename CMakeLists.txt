cmake_minimum_required(VERSION 3.16)
project(kaleidoscope)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/opt/llvm/include/)

add_executable(kaleidoscope toy.cpp)