cmake_minimum_required(VERSION 3.24)
project(Lab_1___Classes_in_C__)

set(CMAKE_CXX_STANDARD 17)

link_directories(library)
include_directories(include)

add_executable(Lab_1___Classes_in_C__ source/main.cpp source/Rectangle.cpp include/Rectangle.h source/console_interface.cpp include/console_interface.h)

target_link_libraries(Lab_1___Classes_in_C__ pdcurses)


