#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include <iostream>

#include "model/MapGenerators/MapFabric.h"
#include "Drawable.h"
#include "model/Rooms/Cell.h"
#include "model/Rooms/Hall.h"
#include "model/Rooms/Room.h"


class Map : public AbstractDrawable {
public:
    std::vector<std::vector<char>> _body;
    std::vector<std::shared_ptr<Room>> _rooms;
    std::vector<std::shared_ptr<Hall>> _halls;

    friend class AntohaFabric;
    friend class BinarySpaceMapGenerator;
    friend class Game;

public:
    Map(int width, int height) {
        _body.assign(width, std::vector<char>(height));
    }

    Map &operator=(const Map &) = delete;

    void Draw(std::shared_ptr<window_work>) override;
};


#endif //DARKEST_DUNGEON_LITE_MAP_H