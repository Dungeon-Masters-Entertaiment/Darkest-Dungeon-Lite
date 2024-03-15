//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H
#define DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H

#include "TreasureCell.h"

class TreasureHallway : public TreasureCell {
public:
    TreasureHallway(int id1, int id) : TreasureCell(id1) {
        Cell cell = TreasureCell(id);
        cell.difficulty = "Low";
    }
};


#endif //DARKEST_DUNGEON_LITE_TREASUREHALLWAY_H
