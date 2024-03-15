//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_REGULARROOM_H
#define DARKEST_DUNGEON_LITE_REGULARROOM_H

#include "Cell.h"

class RegularCell : public Cell {
public:
    RegularCell(int id) : Cell('#', 0, id, "Regular Room",
                               "EmptyCell.",
                               false, "None", {}) {}
};

#endif //DARKEST_DUNGEON_LITE_REGULARROOM_H
