#ifndef DARKEST_DUNGEON_LITE_PLAYER_H
#define DARKEST_DUNGEON_LITE_PLAYER_H

#include <vector>
#include "Drawable.h"
#include "../Entities/Entity.h"

class Player : public AbstractDrawable {
private:
    std::vector <std::vector<char>> _body;
    //Inventory *_inventory;
    Player() = default;
public:
    static Player& GetInstance() {
        static Player instance;
        return instance;
    }

    Player(const Player&) = default;
    Player& operator=(const Player&) = default;

    void Draw(window_work*) override;
};

#endif //DARKEST_DUNGEON_LITE_PLAYER_H