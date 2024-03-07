//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MAPGENERATOR_H
#define DARKEST_DUNGEON_LITE_MAPGENERATOR_H

#include <vector>
#include <memory>
#include <random>
#include "Map.h"

struct Rectangle {
    int x, y, width, height;
};

struct Room {
    int x, y, width, height;

    Room(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height) {}
};


class Map;

class BSP{
public:

    BSP(int x, int y, int width, int height, unsigned seed) : _rect{x, y, width, height}, seed(seed), generator(seed){};

    void Split();

    std::unique_ptr<Room> _room = nullptr;

    std::unique_ptr<BSP> &GetLeftChild();

    std::unique_ptr<BSP> &GetRightChild();

private:
    void SplitHorizontally();

    void SplitVertically();

    Rectangle _rect;

    std::mt19937 generator;
    unsigned int seed;
    std::unique_ptr<BSP> _left_child = nullptr;
    std::unique_ptr<BSP> _right_child = nullptr;
};


template<typename T, typename... Args>
class AlgorithmFabric {
public:
    virtual T *CreateAlgorithm(Args... args) = 0;
};

class BinarySpaceMapGenerator : public AlgorithmFabric<BSP, int, int, int, int> {
private:
    std::mt19937 generator;

public:
    BinarySpaceMapGenerator() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        generator.seed(seed);
    }

    BSP Generate(int x, int y, int width, int height);

    Map Build(int width, int height);

    std::mt19937 &GetGenerator() {
        return generator;
    }

    BSP *CreateAlgorithm(int x, int y, int width, int height) override {
        return new BSP(x, y, width, height, generator());
    }
};


#endif //DARKEST_DUNGEON_LITE_MAPGENERATOR_H
