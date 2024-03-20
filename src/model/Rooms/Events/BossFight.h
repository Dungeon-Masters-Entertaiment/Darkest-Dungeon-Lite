#pragma once
#include "Event.h"

class BossFight : public Event {
public:
    void triggerEvent() override;
    std::string getDescription() const override;
};
