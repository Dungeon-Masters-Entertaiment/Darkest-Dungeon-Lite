#include "EnemyEncounter.h"
#include "../../Hero/Hero.h"
#include <iostream>
#include <vector>

void EnemyEncounter::triggerEvent() {
    this->Heroes = {Hero("Enemy", 1, 1), Hero("Character", 1, 1)};
}

std::string EnemyEncounter::getDescription() const {
    return "You've encountered a fierce enemy. Get ready to fight!";
} 
