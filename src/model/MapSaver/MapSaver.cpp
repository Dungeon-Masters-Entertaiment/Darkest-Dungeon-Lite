//
// Created by Daniel Chiliaev on 21/03/2024.
//

#include "MapSaver.h"
#include "fstream"


void MapSaver::save(Map *map) {
    std::ofstream of("out.json");
    nlohmann::json j = *map;
    of << j;
    of.close();
}
