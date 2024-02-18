cmake_minimum_required(VERSION 3.26)
project(calc)

set(CMAKE_CXX_STANDARD 17)

add_executable(calc main.cpp
        calc.cpp
        stack.cpp
        stack.h
        calc.h)
