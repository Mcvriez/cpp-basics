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


find_package(FLTK REQUIRED)
include_directories(${FLTK_INCLUDE_DIR})
target_link_libraries(cpp-basics ${FLTK_BASE_LIBRARY} ${FLTK_PLATFORM_DEPENDENT_LIBS} )
#target_link_libraries(${PROJECT_NAME} fltk fltk_images)
