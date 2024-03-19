#pragma once
#include "Event.h"
#include "../../Hero/Hero.h"

class EnemyEncounter : public Event {
public:
    std::vector<Hero> Heroes;
    void triggerEvent() override;
    std::string getDescription() const override;
};
