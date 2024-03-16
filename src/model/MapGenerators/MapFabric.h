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

#endif //DARKEST_DUNGEON_LITE_MAPGENERATOR_H