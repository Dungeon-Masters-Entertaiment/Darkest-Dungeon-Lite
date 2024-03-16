#ifndef DARKEST_DUNGEON_LITE_Room_H
#define DARKEST_DUNGEON_LITE_Room_H
#include "Cell.h"
#include "Hall.h"

class Room : public Cell {
    public:
        Room(int x, int y, int width, int height) : Cell(x, y, width, height) {}
    private: 
        std::vector<std::shared_ptr<Hall>> _hall_connection = {nullptr, nullptr, nullptr, nullptr};
};
#endif