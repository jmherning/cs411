cmake_minimum_required(VERSION 3.15)
project(ass2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ass2
        build.cpp
        build.h
        build_test.cpp)
