//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_TREASUREROOM_H
#define DARKEST_DUNGEON_LITE_TREASUREROOM_H


class TreasureCell : public Cell {
    public:
        TreasureCell(int id) : Cell('$', 0, id, "Treasure Room",
                                    "Contains valuable items, often guarded by an enemy.",
                                    true, "High", {"guardian", "treasure"}) {}
};


#endif //DARKEST_DUNGEON_LITE_TREASUREROOM_H
