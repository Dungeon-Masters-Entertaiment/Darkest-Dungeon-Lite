#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include "MapGenerator.h"
#include "Drawable.h"

class Map : public AbstractDrawable {
protected:
    std::vector<std::vector<char>> _body;
    std::vector<std::shared_ptr<Room>> _rooms;

    friend class BinarySpaceMapGenerator;

public:
    Map(int width, int height) {
        _body.assign(width, std::vector<char>(height));
    }

    Map &operator=(const Map &) = delete;

    void Draw() override;

    void GenerateMap(BSP &bsp, int width, int height);
};

#endif //DARKEST_DUNGEON_LITE_MAP_H