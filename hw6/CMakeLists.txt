cmake_minimum_required(VERSION 3.15)
project(hw6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw6
        huffcode.cpp
        huffcode.hpp
        huffcode_test.cpp)
