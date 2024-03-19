cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES src/*.cpp)
add_executable(main main.cpp ${SOURCES})
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(glog REQUIRED)
target_link_libraries(main glog::glog)
find_package(nlohmann_json REQUIRED)
target_link_libraries(main nlohmann_json::nlohmann_json)