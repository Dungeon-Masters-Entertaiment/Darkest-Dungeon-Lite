#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include <vector>
#include <memory>
#include "Drawable.h"
#include "Room.h"

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
};

#endif //DARKEST_DUNGEON_LITE_MAP_H