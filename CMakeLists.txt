cmake_minimum_required(VERSION 3.24)
project(PKArt)

set(CMAKE_CXX_STANDARD 17)

link_directories(library)
include_directories(include)

add_executable(PKArt source/main.cpp source/Rectangle.cpp include/PKArt/Rectangle.h source/console_interface.cpp include/console_interface.h source/Circle.cpp include/PKArt/Circle.h source/Shape.cpp include/PKArt/Shape.h source/CGL.cpp include/CGL.h)

target_link_libraries(PKArt pdcurses)


