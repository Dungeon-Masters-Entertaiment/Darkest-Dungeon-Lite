//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_BATTLEROOM_H
#define DARKEST_DUNGEON_LITE_BATTLEROOM_H


class BattleCell : public Cell {
    public:
        BattleCell(int id) : Cell('X', 0, id, "Battle Room",
                                  "Contains a group of enemies.",
                                  true, "Medium", {"enemy_group"}) {}
};

#endif //DARKEST_DUNGEON_LITE_BATTLEROOM_H
