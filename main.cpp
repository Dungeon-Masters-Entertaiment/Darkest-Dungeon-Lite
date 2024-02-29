//
// Created by Егор Кулин on 29.02.2024.
//
#include "src/controller/Game.h"
#include "src/model/Drawable/Map.h"

void GenerateMap() {
    Map &map = Map::GetInstance();
    // Use the map instance to generate the map
    map.GenerateMap(50, 50);
    map.Draw();
}

int main(int argc, char **argv) {
    GenerateMap();
}