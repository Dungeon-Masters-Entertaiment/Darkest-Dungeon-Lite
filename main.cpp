//
// Created by Егор Кулин on 29.02.2024.
//
// #include "src/controller/Game.h"
#include <iostream>
// #include "view/graphics.h"

#include "src/controller/Game.h"
#include <fstream>
#include <jsonParser/JSONParser.h>

int main(int argc, char **argv) {
  AntohaFabric generator;
  // // Use the map instance to generate the map
  static Map map = generator.Build(50, 50);
  // map.Draw();
  // */

  std::ofstream of("out.json");
  nlohmann::json j = map;
  of << j;
  of.close();

  static Map map2 = JSONParser::jsonToObject<Map>(j.dump());

  // cur.divide_screen();
  //  Game game;
  //  game.Start();
  //  return 0;

}