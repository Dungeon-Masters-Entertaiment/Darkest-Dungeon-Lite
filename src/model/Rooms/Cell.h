//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_Cell_H
#define DARKEST_DUNGEON_LITE_Cell_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>

class Cell {
    public:
        inline static int size = 0;
        char chr;
        int id;
        int view;
        std::string name;
        std::string description;
        bool enemy_presence;
        std::string difficulty;
        std::vector<std::string> special_features;
        int x, y, width, height;
        std::vector<std::shared_ptr<Cell>> conection = {nullptr, nullptr, nullptr, nullptr};

        Cell(int x, int y, int width, int height)
            : x(x), y(y), width(width), height(height), id(size) {size+=1;}

        Cell(char chr, int view, int id, std::string name,
                    std::string description,
                    bool enemyPresence,
                    std::string difficulty,
                    std::vector<std::string> special_features) :
                    chr(chr),
                    view(view),
                    id(id),
                    name(std::move(name)),
                    description(std::move(description)),
                    enemy_presence(enemyPresence),
                    difficulty(difficulty),
                    special_features(special_features) {}

        virtual void DisplayInfo() {
            std::cout << "Symbol: " << chr << "\n"
                      << "View: " << view << "\n"
                      << "Cell ID: " << id << "\n"
                      << "Name: " << name << "\n"
                      << "Description: " << description << "\n"
                      << "Enemy Presence: " << (enemy_presence ? "Yes" : "No") << "\n"
                      << "Difficulty: " << difficulty << "\n"
                      << "Special Features: ";
            for (const auto& feature : special_features) {
                std::cout << feature << " ";
            }
            std::cout << "\n\n";
        }
};



#endif //DARKEST_DUNGEON_LITE_Cell_H
