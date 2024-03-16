#ifndef DARKEST_DUNGEON_LITE_Hall_H
#define DARKEST_DUNGEON_LITE_Hall_H

#include <vector>
#include "Cell.h"

class Hall {
    public: 
        Hall(std::shared_ptr<Cell> first, std::shared_ptr<Cell> second);
    std::vector<std::shared_ptr <Cell>> rooms_in_hall;
    std::shared_ptr <Cell> entrance;
    std::shared_ptr <Cell> exit; 
    std::shared_ptr <Cell> location;
    friend Cell;
};
#endif 