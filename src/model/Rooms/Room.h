//
// Created by andru on 12.03.2024.
//

#ifndef DARKEST_DUNGEON_LITE_ROOM_H
#define DARKEST_DUNGEON_LITE_ROOM_H


class Room {
public:
    int view;
    int id;
    std::string name;
    std::string description;
    bool enemyPresence;
    std::string difficulty;
    std::vector<std::string> specialFeatures;

    Room(int view, int id, std::string name,
                std::string description,
                bool enemyPresence,
                std::string difficulty,
                std::vector<std::string> specialFeatures) :
                view(view),
                id(id),
                name(name),
                description(description),
                enemyPresence(enemyPresence),
                difficulty(difficulty),
                specialFeatures(specialFeatures) {}

    virtual void displayInfo() {
        std::cout << "View: " << view << "\n"
                  << "Room ID: " << id << "\n"
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



#endif //DARKEST_DUNGEON_LITE_ROOM_H
