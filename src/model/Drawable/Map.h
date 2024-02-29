#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include "../src/model/MapGenerator.h"
#include "Drawable.h"

class Map : public AbstractDrawable {
protected:
    std::vector<std::vector<char>> _body;
    std::vector<std::shared_ptr<Room>> _rooms;
    Map() = default;
public:
    static Map& GetInstance() {
        static Map instance;
        return instance;
    }

    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;

    void Draw() override;

    void GenerateMap(int width, int height);
};

#endif //DARKEST_DUNGEON_LITE_MAP_H