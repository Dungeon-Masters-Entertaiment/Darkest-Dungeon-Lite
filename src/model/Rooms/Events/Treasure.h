#pragma once
#include "Event.h"
#include "../../../Inventory.h"
#include "../../GameItems/Gold.h"

class Treasure : public Event {
public:    
    ~Treasure () override = default;
    void triggerEvent() override {};
    std::string getDescription() const override {
        return "Treasure";
    };

    void trigger(){
        Inventory::getInstance().addItem(std::make_shared<Gold>());
    }

};
