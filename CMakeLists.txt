cmake_minimum_required(VERSION 3.24)
project(Seagull)

set(CMAKE_CXX_STANDARD 17)

link_directories(library)
include_directories(include)

add_executable(Seagull source/main.cpp source/PKArt/Rectangle.cpp include/PKArt/Rectangle.h source/console_interface.cpp include/console_interface.h source/PKArt/Circle.cpp include/PKArt/Circle.h source/PKArt/Shape.cpp include/PKArt/Shape.h source/CGL/CGL.cpp include/CGL/CGL.h source/CGL/game_object.cpp include/CGL/game_object.h include/CGL/Component.h source/CGL/Components/GraphicsComponent.cpp)

target_link_libraries(Seagull pdcurses)


