#pragma once
#include "Event.h"

class Trap : public Event {
public:
    ~Trap () override = default;
    void triggerEvent() override{};
    std::string getDescription() const override;
};
