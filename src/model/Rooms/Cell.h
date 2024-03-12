//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_Cell_H
#define DARKEST_DUNGEON_LITE_Cell_H


class Cell {
    public:
        char chr;
        int view;
        int id;
        std::string name;
        std::string description;
        bool enemyPresence;
        std::string difficulty;
        std::vector<std::string> specialFeatures;

        Cell(char chr, int view, int id, std::string name,
                    std::string description,
                    bool enemyPresence,
                    std::string difficulty,
                    std::vector<std::string> specialFeatures) :
                    chr(chr)
                    view(view),
                    id(id),
                    name(name),
                    description(description),
                    enemyPresence(enemyPresence),
                    difficulty(difficulty),
                    specialFeatures(specialFeatures) {}

        virtual void displayInfo() {
            std::cout << "Symbol: " << chr << "\n"
                      << "View: " << view << "\n"
                      << "Cell ID: " << id << "\n"
                      << "Name: " << name << "\n"
                      << "Description: " << description << "\n"
                      << "Enemy Presence: " << (enemyPresence ? "Yes" : "No") << "\n"
                      << "Difficulty: " << difficulty << "\n"
                      << "Special Features: ";
            for (const auto& feature : specialFeatures) {
                std::cout << feature << " ";
            }
            std::cout << "\n\n";
        }
};



#endif //DARKEST_DUNGEON_LITE_Cell_H
