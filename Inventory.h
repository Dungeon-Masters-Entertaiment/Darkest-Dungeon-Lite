#ifndef DARKEST_DUNGEON_LITE_INVENTORY_H
#define DARKEST_DUNGEON_LITE_INVENTORY_H
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "src/model/GameItems/Items.h"

class Inventory {
public:
    static Inventory& getInstance() {
        static Inventory instance; 
        return instance;
    }

    void addItem(std::shared_ptr<Item> first) {
        items.push_back(first);
    }

    void deleteItem(int i) {
        items.erase(items.begin() + i);
    }

    int getsizeItem(int i) {
        return items.size();
    }

    void showItems() const {
        std::cout << "Инвентарь: количество зелий лечени - " <<items.size()<<"\n";
    }


private:
    Inventory() {}
    ~Inventory() {}

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    std::vector<std::shared_ptr<Item>> items;
};
#endif