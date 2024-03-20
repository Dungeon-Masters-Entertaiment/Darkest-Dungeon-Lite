//
// Created by Daniel Chiliaev on 21/03/2024.
//

#ifndef MAPSAVER_H
#define MAPSAVER_H

#include "model/Drawable/Map.h"
class MapSaver {
public:
    static void save(Map *map);
    static Map *load();
};
#endif //MAPSAVER_H
