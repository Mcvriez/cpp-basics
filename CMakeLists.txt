cmake_minimum_required(VERSION 2.8.9)

project (cppbasics)

include_directories(include)

add_executable(app use.cpp my.cpp)