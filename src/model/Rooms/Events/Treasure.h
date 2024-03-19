#pragma once
#include "Event.h"

class Treasure : public Event {
public:
    void triggerEvent() override;
    std::string getDescription() const override;
};
