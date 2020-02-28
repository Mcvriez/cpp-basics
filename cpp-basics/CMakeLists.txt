cmake_minimum_required(VERSION 3.13)
project(cpp-basics)
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES chapter16.cpp)

add_executable(cpp-basics
        chapter16.cpp
        fltk_lib/Graph.cpp
        fltk_lib/GUI.cpp
        fltk_lib/Simple_window.cpp
        fltk_lib/Window.cpp chapter16.cpp)

set(FLTK_SKIP_FLUID true)
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ldl -lpthread")


find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIR})
target_link_libraries(cpp-basics ${FLTK_BASE_LIBRARY} ${FLTK_PLATFORM_DEPENDENT_LIBS} fltk)