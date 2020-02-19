cmake_minimum_required(VERSION 3.13)
project(cpp-basics)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES chapter_14_graphics_class_design.cpp)

add_executable(cpp-basics
        chapter_14_graphics_class_design.cpp
        Graph.cpp
        GUI.cpp
        Simple_window.cpp
        Window.cpp)

set(FLTK_SKIP_FLUID true)
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ldl -lpthread")


find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIR})
target_link_libraries(cpp-basics ${FLTK_BASE_LIBRARY} ${FLTK_PLATFORM_DEPENDENT_LIBS} fltk)