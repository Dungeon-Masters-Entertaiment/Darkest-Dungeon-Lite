//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include <vector>
#include "Drawable.h"

class Map : public AbstractDrawable {
protected:
    static Map *_instance;
    std::vector <std::vector<char>> _body;
    std::vector <Room> _rooms;
public:
    Map();

    static Map *GetInstance();

    void Draw() override;
};

#endif //DARKEST_DUNGEON_LITE_MAP_H
