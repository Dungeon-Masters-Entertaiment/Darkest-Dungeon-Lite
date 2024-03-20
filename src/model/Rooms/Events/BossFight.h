#pragma once
#include "Event.h"

class BossFight : public Event {
public:
     ~BossFight() override = default;
    void triggerEvent() override{};
    std::string getDescription() const override {
        return "BF";
    };
};
