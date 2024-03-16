#include <iostream>
#include <string>
#include "Hero.h"

void Hero::attack(Hero& target) {
        std::cout << name << " attacks " << target.name << " for " << damage << " damage!" << std::endl;
        target.takeDamage(damage);
}

void Hero::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) {
        std::cout << name << " has been defeated." << std::endl;
    } else {
        std::cout << name << " now has " << health << " health remaining." << std::endl;
    }
}

void Hero::heal(int amount) {
    health += amount;
    std::cout << name << " heals for " << amount << " health!" << std::endl;
}