cmake_minimum_required(VERSION 3.15)
project(cpp_basics)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)

add_executable(cpp_basics
        lib/Skiplist.cpp
        lib/Skiplist.h
        lib/std_lib_facilities.h
        chapter18.cpp
        CMakeLists.txt)
