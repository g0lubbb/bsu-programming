cmake_minimum_required(VERSION 3.26)
project(kr1)

set(CMAKE_CXX_STANDARD 17)

add_executable(kr1 main.cpp
        fileIOData.h
        visibilityWindow.h
)
