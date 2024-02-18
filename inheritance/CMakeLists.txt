cmake_minimum_required(VERSION 3.26)
project(inherit)

set(CMAKE_CXX_STANDARD 17)

add_executable(inherit main.cpp
        student.cpp
        student.h)
