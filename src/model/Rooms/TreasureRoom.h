//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_TREASUREROOM_H
#define DARKEST_DUNGEON_LITE_TREASUREROOM_H


class TreasureRoom : public Room {
public:
    TreasureRoom(int id) : Room(0, id, "Treasure Room",
                                "Contains valuable items, often guarded by an enemy.",
                                true, "High", {"treasure", "guardian"}) {}
};


#endif //DARKEST_DUNGEON_LITE_TREASUREROOM_H
