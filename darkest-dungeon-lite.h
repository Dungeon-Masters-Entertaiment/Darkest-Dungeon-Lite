
#ifndef DARKEST_DUNGEON_LITE_DARKEST_DUNGEON_LITE_H
#define DARKEST_DUNGEON_LITE_DARKEST_DUNGEON_LITE_H

#include <vector>
#include <string.h>
#include <iostream>


//defining classes

//definition of class Drawable and Drawable extending classes
Class Drawable;
static Class Map : Drawable; // singleton pattern
static Class Player : Drawable; // singleton pattern (player sign at the map)
Class Room : Drawable;
Class Hallway : Room;
Class FightRoom : Room;
static Class BossRoom : Room; // singleton pattern

//definition of class Skill and Skill extending classes
Class Skill;
Class Hit : Skill;
Class Shot : Skill;
Class Heal : Skill;

//definition of class Equipment - field in Warrior and Inventory classes
Class Equipment;

//definition of class Item and Item extending classes
Class Item;
//Class Torch; // I actually don't know how to implement its functions for our game
Class HealthPotion : Item;
Class Key : Item;

//definition of static class Inventory (singleton pattern)
static Class Inventory;

//definition of class Entity and Entity extending classes
Class Entity;
Class Warrior : Entity;
Class Enemy : Entity;
Class NPC : Entity;
Class Boss : Enemy;

//THE END OF INITIAL CLASS DEFINITIONS



//extending classes with fields and methods declarations
//TODO: write function params


Class Drawable { // abstract class
    public:
        void draw(); // if object is map we output it in condole with ascii art, if it's something else we just change map structure
};

static Class Map : Drawable { // singleton pattern
    std::vector <std::vector <char>> body(50, vector <char> (50, ' ')); // 50x50 map
    std::vector <Room> rooms;
    Player player;
    public:
        void generate();
        void draw();
};

static Class Player : Drawable { //singleton pattern (player sign at the map)
    Room* current_room;
    public:
        void draw();
};

Class Room : Drawable { // abstract class for all rooms
    int center_x, center_y;
    std::vector <Room*> neighbors;
    std::vector <Item> trophies;
    bool need_a_key;
    public:
        void draw();
};

Class Hallway : Room { // 1x1 room with no more than 2 neighbours
    int center_x, center_y;
    std::vector <room*> neighbors;
    std::vector <Item> trophies;
    public:
        void draw();
};

Class FightRoom : Room { // 3x3 room with 4 neighbours (fight is not obligatory)
    int center_x, center_y;
    std::vector <room*> neighbors;
    std::vector <Enemy> enemies;
    std::vector <Item> trophies;
    std::vector <NPC> npcs;
    public:
        void draw();
};

static Class BossRoom : Room { // singleton pattern
    int center_x, center_y;
    std::vector <Room*> neighbors;
    static Boss boss;
    std::vector <Item> trophies;
    std::vector <NPC> npcs;
    public:
        void draw();
};

Class Skill { // abstract class
    int cool_down;
    int steps_after_use;
    public:
        void use();
};

Class Hit : Skill { //maximal cooldown is 1
    int cool_down;
    int steps_after_use;
    int damage;
    int crit_damage;
    int crit_chance;
    public:
        void use();
};

Class Shot : Skill { // minimal cooldown is 2
    int cool_down;
    int steps_after_use;
    int damage;
    int crit_damage;
    int crit_chance;
    public:
        void use();
};

Class Heal : Skill { // maximal cooldown is 3
    int cool_down;
    int steps_after_use;
    int heal;
    public:
        void use();
};

Class Equipment {
    std::vector <Item> items;
    public:
        std::vector <Item> get_items();
        void use_item();
};

Class Item { // abstract class
    public:
        void use();
};

Class HealthPotion : Item {
    int heal;
    public:
        void use();
};

Class Key : Item {
    public:
        void use();
};

static Class Inventory { // singleton pattern
    static std::vector <Item> items;
    int capacity;
    public:
        void use_item();
        void add_item();
        void remove_item();
};

Class Entity {
    int health;
    int max_health;
    std::vector <Skill> skills;
    int initiative;
    int attacks_in_battle;
    Equipment equipment;
    public:
        void use_skill();
        void take_damage();
        void die();
};



#endif //DARKEST_DUNGEON_LITE_DARKEST_DUNGEON_LITE_H


