cmake_minimum_required(VERSION 3.15)
project(hw5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw5
        build.cpp
        build.hpp
        build_test2.cpp)
