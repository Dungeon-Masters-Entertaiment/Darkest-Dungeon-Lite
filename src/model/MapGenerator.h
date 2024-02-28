//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MAPGENERATOR_H
#define DARKEST_DUNGEON_LITE_MAPGENERATOR_H

class MapGenerator {
public:
    virtual Map GenerateMap() = 0; // Pure virtual function

};

class BinarySpaceMapGenerator : public MapGenerator {
public:
    Map GenerateMap() override;
};
#endif //DARKEST_DUNGEON_LITE_MAPGENERATOR_H
