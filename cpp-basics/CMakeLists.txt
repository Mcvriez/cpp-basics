cmake_minimum_required(VERSION 3.13)
project(cpp-basics)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES "chapter17.cpp")

add_executable(cpp-basics chapter17.cpp lib/std_lib_facilities.h lib/Link.h lib/Link.cpp)

set(FLTK_SKIP_FLUID true)
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ldl -lpthread")

target_link_libraries(cpp-basics)