cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Map.h Map.cpp MapFabric.h AntohaMapGenerator.cpp Cell.h Cell.cpp) # Include Map.cpp here

target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/controller
        ${CMAKE_CURRENT_SOURCE_DIR}/src/model/Drawable
        )