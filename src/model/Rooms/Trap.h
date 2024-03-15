//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_TRAP_H
#define DARKEST_DUNGEON_LITE_TRAP_H


class Trap: public Cell{
    public:
        Trap(int id) : Cell('!', 0, id, "Trap",
                            "Contains a trap, which can deal damage to the hero.",
                            false, "Low", {"trap"}) {}
};


#endif //DARKEST_DUNGEON_LITE_TRAP_H
