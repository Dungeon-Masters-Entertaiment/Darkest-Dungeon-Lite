#pragma once
#include "Event.h"

class Treasure : public Event {
public:
    ~Treasure () override = default;
    void triggerEvent() override;
    std::string getDescription() const override {
        return "T";
    };
};
