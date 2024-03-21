#ifndef PEALINGPOTION_H
#define PEALINGPOTION_H
#include "Items.h"
#include <iostream>

class Gold : public Item{
public:
    Gold() {
        count = 10;
    }
    ~Gold() override = default;   
    void use() override {};
    int count;
    std::string getDescription() const override{
        return "This healing potion adds 4 - 6 health to the selected character";
    }
    void add(int amount) {
        count += amount;
    }
    void sub(int amount) {
        count -= amount;
    }
};
#endif
