#ifndef DARKEST_DUNGEON_LITE_Hall_H
#define DARKEST_DUNGEON_LITE_Hall_H

#include <vector>
#include "Cell.h"
#include "Room.h"

class Hall {
    public: 
        Hall(std::shared_ptr<Room> first, std::shared_ptr<Room> second, int type, int width, int height, std::vector<std::vector<char>> _body);
    std::vector<std::shared_ptr <Cell>> rooms_in_hall;
    std::shared_ptr <Room> entrance;
    std::shared_ptr <Room> exit; 
    std::shared_ptr <Cell> location;
};
#endif 