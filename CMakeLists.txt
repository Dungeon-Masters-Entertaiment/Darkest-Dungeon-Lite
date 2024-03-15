cmake_minimum_required(VERSION 3.15)
project(MyGame)

set(CMAKE_CXX_STANDARD 14)

find_package(glog REQUIRED)
find_package(nlohmann_json REQUIRED)


set(SOURCES ./src/json_parser/JSONParser.cpp ./src/model/Skills/CombatSkill.cpp  src/PointClass/Vector.cpp)
set(HEADERS ./src/json_parser/JSONParser.h ./src/model/Skills/CombatSkill.h  src/PointClass/Vector.h)

add_executable(glfw_template ${SOURCES} ${HEADERS}

       )

add_executable(
        main
        ${SOURCES} ${HEADERS} main.cpp
)


target_link_libraries(main PRIVATE glog::glog)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)


target_include_directories(main PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)