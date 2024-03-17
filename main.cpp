//
// Created by Егор Кулин on 29.02.2024.
//
//#include "src/controller/Game.h"
#include "model/Drawable/Map.h"
#include <iostream>
#include "model/MapGenerators/MapFabric.h"
#include "view/graphics.h"


void GenerateMap() {
    AntohaFabric generator;
    // Use the map instance to generate the map
    Map map = generator.Build(50, 50);
    map.Draw();
}

int main(int argc, char **argv) {
    //Generator();
    Monitor monitor;
    monitor.make_an_event_loop();

}