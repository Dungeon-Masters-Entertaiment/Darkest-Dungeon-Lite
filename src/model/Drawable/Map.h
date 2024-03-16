#ifndef DARKEST_DUNGEON_LITE_MAP_H
#define DARKEST_DUNGEON_LITE_MAP_H

#include "model/MapGenerators/MapFabric.h"
#include "Drawable.h"
#include "model/Rooms/Cell.h"

class Map : public AbstractDrawable {
protected:
    std::vector<std::vector<char>> _body;
    std::vector<std::shared_ptr<Cell>> _rooms;

    friend class AntohaFabric;
    friend class BinarySpaceMapGenerator;

public:
    Map(int width, int height) {
        _body.assign(width, std::vector<char>(height));
    }

    Map &operator=(const Map &) = delete;

    void Draw() override;
};

#endif //DARKEST_DUNGEON_LITE_MAP_H