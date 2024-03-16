cmake_minimum_required(VERSION 3.22)
project(Darkest_Dungeon_Lite)
set(CMAKE_CXX_FLAGS "-lncurses")
set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(game main.cpp
        graphics.h BMP.h
        graphics.cpp BMP.cpp
)
target_link_libraries(game ${CURSES_LIBRARIES})
