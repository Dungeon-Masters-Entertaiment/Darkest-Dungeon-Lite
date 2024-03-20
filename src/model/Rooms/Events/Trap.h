#pragma once
#include "Event.h"

class Trap : public Event {
public:
    void triggerEvent() override;
    std::string getDescription() const override;
};
