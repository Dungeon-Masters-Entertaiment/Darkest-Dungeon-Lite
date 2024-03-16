#ifndef DARKEST_DUNGEON_LITE_ROOM_H
#define DARKEST_DUNGEON_LITE_ROOM_H
#include "Cell.h"
#include "Hall.h"

class Room : public Cell {
    private: 
        std::vector<std::vector<int>> f; 
};
#endif DARKEST_DUNGEON_LITE_ROOM_H