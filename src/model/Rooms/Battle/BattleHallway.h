//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H
#define DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H
#include "BattleCell.h"

class BattleHallway: public BattleCell {
    public:
        BattleHallway(int id1, int id) : BattleCell(id1) {
            Cell cell = BattleCell(id);
            cell.difficulty = "Low";
        }
};


#endif //DARKEST_DUNGEON_LITE_BATTLEHALLWAY_H
