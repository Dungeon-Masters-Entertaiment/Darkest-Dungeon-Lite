cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_FLAGS "-lncurses")

project(Darkest_Dungeon_Lite)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Darkest_Dungeon_Lite
        main.cpp
        graphics.h
        )
