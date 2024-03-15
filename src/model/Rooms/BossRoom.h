//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_BOSSROOM_H
#define DARKEST_DUNGEON_LITE_BOSSROOM_H


class BossRoom: public Cell {
    public:
        Cell(int id) : Room('B', 0, id, "Boss Room",
                                    "Room with strong enemy.",
                                    true, "High", {"boss"}) {}
};


#endif //DARKEST_DUNGEON_LITE_BOSSROOM_H
