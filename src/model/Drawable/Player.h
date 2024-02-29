#ifndef DARKEST_DUNGEON_LITE_PLAYER_H
#define DARKEST_DUNGEON_LITE_PLAYER_H

#include <vector>
#include "Drawable.h"
#include "Entity.h"
#include "Inventory.h"

class Player : public AbstractDrawable {
private:
    std::vector <std::vector<char>> _body;
    Inventory *_inventory;
    Player() = default;
public:
    static Player& GetInstance() {
        static Player instance;
        return instance;
    }

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    void Draw() override;
};

#endif //DARKEST_DUNGEON_LITE_PLAYER_H