cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 14)

find_package(glog REQUIRED)
find_package(nlohmann_json REQUIRED)


add_executable(
        main
        main.cpp
#        src/json_parser/JSONParser.cpp
)

target_sources(
        main PRIVATE src/json_parser/JSONParser.cpp
)


target_link_libraries(main glog::glog)
target_link_libraries(main nlohmann_json::nlohmann_json)

target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)