//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MAPGENERATOR_H
#define DARKEST_DUNGEON_LITE_MAPGENERATOR_H

#include "../src/model/Drawable/Map.h"
#include <vector>
#include <memory>

struct Rectangle {
    int x, y, width, height;
};

struct Room {
    int x, y, width, height;

    Room(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height) {}
};

class MapGenerator {
public:
    virtual Map GenerateMap() = 0; // Pure virtual function

};

class BinarySpaceMapGenerator : public MapGenerator {
public:
    friend class BSP;

    Map GenerateMap() override;
};

class BSP {
public:

    BSP(int x, int y, int width, int height) : _rect{x, y, width, height} {};

    void Split();

    std::unique_ptr<Room> _room = nullptr;

    std::unique_ptr<BSP>& GetLeftChild();

    std::unique_ptr<BSP>& GetRightChild();

private:
    void SplitHorizontally();

    void SplitVertically();

    Rectangle _rect;
    std::unique_ptr<BSP> _left_child = nullptr;
    std::unique_ptr<BSP> _right_child = nullptr;
};

#endif //DARKEST_DUNGEON_LITE_MAPGENERATOR_H
