cmake_minimum_required(VERSION 3.20)
project(lutop CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(lutop
    src/main.cpp
    src/parser.cpp
)
