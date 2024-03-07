//
// Created by Егор Кулин on 29.02.2024.
//
#include "src/controller/Game.h"
#include "Map.h"
#include "MapGenerator.h"

void GenerateMap() {
    BinarySpaceMapGenerator generator;
    // Use the map instance to generate the map
    Map map = generator.Build(50, 50);
    map.Draw();
}

int main(int argc, char **argv) {
    GenerateMap();
}