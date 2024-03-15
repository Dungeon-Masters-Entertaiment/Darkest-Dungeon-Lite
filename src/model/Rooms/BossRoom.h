//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_BOSSROOM_H
#define DARKEST_DUNGEON_LITE_BOSSROOM_H
#include "Cell.h"

class BossRoom: public Cell {
    public:
        BossRoom(int id) : Cell('B', 0, id, "Boss Room",
                                    "Room with strong enemy.",
                                    true, "High", {"boss"}) {}
};


#endif //DARKEST_DUNGEON_LITE_BOSSROOM_H
