
#ifndef DARKEST_DUNGEON_LITE_ROOM_H
#define DARKEST_DUNGEON_LITE_ROOM_H

#include <vector>
#include <iostream>
#include "Drawable.h"
#include "Entity.h"

class Room : public AbstractDrawable {
protected:
    std::vector <std::vector<char>> body;
    std::vector <Entity> entities;
public:
    virtual void Draw() = 0; // Make this function pure virtual
};

class EmptyRoom : public Room {
public:
    EmptyRoom();

    void Draw() override;
};


class Hallway : public Room {
public:
    Hallway();

    void Draw() override;
};

class FightRoom : public Room {
public:
    FightRoom();

    void Draw() override;
};

class BossRoom : public Room {
public:
    BossRoom();

    void Draw() override;
};


#endif //DARKEST_DUNGEON_LITE_ROOM_H
