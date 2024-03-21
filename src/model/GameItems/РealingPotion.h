#ifndef PEALINGPOTION_H
#define PEALINGPOTION_H
#include "Items.h"
#include <iostream>

class PealingPotion : public Item{
public:
    ~PealingPotion() override = default;   
    void use() override {};
    std::string getDescription() const override{
        return "This healing potion adds 4 - 6 health to the selected character";
    }
};
#endif
