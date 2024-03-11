//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_REGULARROOM_H
#define DARKEST_DUNGEON_LITE_REGULARROOM_H


class RegularRoom : public Room {
public:
    RegularRoom(int id) : Room(0, id, "Regular Room",
                               "Usually does not contain enemies, may contain a chest or other items.",
                               false, "None", {"chest", "items"}) {}
};

#endif //DARKEST_DUNGEON_LITE_REGULARROOM_H
