#ifndef DARKEST_DUNGEON_LITE_Hall_H
#define DARKEST_DUNGEON_LITE_Hall_H

#include <vector>
#include "Cell.h"

class Hall {
    std::vector<std::shared_ptr<Cell>> rooms_in_hall;
    std::shared_ptr<Cell> entrance;
    std::shared_ptr<Cell> exit; 
    friend Cell;
};
#endif 