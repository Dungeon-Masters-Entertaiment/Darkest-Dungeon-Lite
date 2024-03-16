#ifndef DARKEST_DUNGEON_LITE_Cell_H
#define DARKEST_DUNGEON_LITE_Cell_H
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Hero {
public:
    // Конструктор класса
    Hero(std::string name, int health, int damage, int speed)
        : name(name), health(health), damage(damage), speed(speed) {}

    // Метод для атаки другого персонажа
    void attack(Hero& target);

    // Метод для получения урона
    void takeDamage(int amount); 
    
    // Метод для лечения
    void heal(int amount);

    // Геттеры для атрибутов персонажа
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }
    int getSpeed() const { return speed; }

private:
    std::string name; // Имя персонажа
    int health;       // Здоровье
    int damage;       // Урон
    int speed;        // Скорость
};
#endif //DARKEST_DUNGEON_LITE_Cell_H
