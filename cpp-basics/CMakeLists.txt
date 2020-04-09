cmake_minimum_required(VERSION 3.15)
project(cpp_basics)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)

add_executable(cpp_basics
        lib/std_lib_facilities.h
        chapter19.cpp
        CMakeLists.txt lib/vector.h)
