#pragma once
#include "Event.h"
#include "../../Creature/Hero.h"
#include "../../Creature/Squad.h"

class EnemyEncounter : public Event {
public:
    ~EnemyEncounter() override = default;

    Squad Enemyes; 
    Squad Heroes; 
    
    void triggerEvent() override{};
    std::string getDescription() const override {
        return "EnemyEncounter";
    };
};
