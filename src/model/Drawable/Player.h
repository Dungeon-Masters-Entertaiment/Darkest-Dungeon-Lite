//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_PLAYER_H
#define DARKEST_DUNGEON_LITE_PLAYER_H

#include <vector>
#include "Drawable.h"
#include "Entity.h"
#include "Inventory.h"

class Player : public AbstractDrawable {
private:
    static Player *_instance;
    std::vector <std::vector<char>> _body;
    Inventory *_inventory;
public:
    Player();

    static Player *GetInstance();

    void Draw() override;
};

#endif //DARKEST_DUNGEON_LITE_PLAYER_H
