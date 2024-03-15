//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MAPGENERATOR_H
#define DARKEST_DUNGEON_LITE_MAPGENERATOR_H

#include <vector>
#include <memory>
#include <random>
#include "../Drawable/Map.h"
#include <chrono>

struct Room {
    int x, y, width, height;
    std::vector<std::shared_ptr<Room>> conection;
    
    Room(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height) {}
};


class Map;

template<typename... Args>
class MapFabric {
    public:
        virtual Map Build(Args... args) = 0;
};

class AntohaFabric : public MapFabric<int, int> {
    private:
        std::mt19937 generator;
    public:
        AntohaFabric() {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            generator.seed(seed);
        }

        virtual Map Build(int width, int height) override;
};

class EgorFabric : public MapFabric<int, int>{
    private:
        std::mt19937 generator;
    public:
        EgorFabric() {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            generator.seed(seed);
        }

        virtual Map Build(int width, int height) override;

};

/*
struct Rectangle {
    int x, y, width, height;
};

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

class Antohastruct{
    public:
        Antohastruct(int width, int height, unsigned seed): width(width), height(height), seed(seed) {};
    private:
        int width, height;
        std::mt19937 generator;
        unsigned int seed;
};
template<typename T, typename... Args>
class AlgorithmFabric {
public:
    virtual T *CreateAlgorithm(Args... args) = 0;
};
class AntohaMapGenerator : public AlgorithmFabric<Antohastruct, int, int> {
    private:
        std::mt19937 generator;
    public:
        AntohaMapGenerator() {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            generator.seed(seed);
        }

        //Antohastruct Generate(int width, int height);
        Map Build(int width, int height);

        Antohastruct *CreateAlgorithm(int width, int height) override{
            return new Antohastruct(width, height, generator());
        }

};



class BinarySpaceMapGenerator : public AlgorithmFabric<BSP, int, int, int, int> {
private:
    std::mt19937 generator;

public:
    BinarySpaceMapGenerator() {
        unsigned     seed = std::chrono::system_clock::now().time_since_epoch().count();
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

*/

#endif //DARKEST_DUNGEON_LITE_MAPGENERATOR_H