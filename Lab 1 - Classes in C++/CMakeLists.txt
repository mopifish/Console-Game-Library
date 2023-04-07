cmake_minimum_required(VERSION 3.24)
project(Lab_1___Classes_in_C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_1___Classes_in_C__ source/main.cpp source/Rectangle.cpp include/Rectangle.h)

include_directories(include)
