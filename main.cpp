//
// Created by Егор Кулин on 29.02.2024.
//
// #include "src/controller/Game.h"
#include <iostream>
// #include "view/graphics.h"

#include "src/controller/Game.h"
#include <controller/states/MapState.h>
#include <fstream>
#include <jsonParser/JSONParser.h>
#include "model/MapSaver/MapSaver.h"

int main(int argc, char **argv) {
    /*AntohaFabric generator;
    // Use the map instance to generate the map
    static Map map = generator.Build(50, 50);
    map.Draw();
    */
    
    
    //cur.divide_screen();
    Game::getInstance()->Start();
    return 0;

  MapSaver::save(&map);
}