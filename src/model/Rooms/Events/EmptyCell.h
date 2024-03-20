#pragma once
#include "Event.h"
#include <vector>
#include "../../Hero/Hero.h"

class EmptyCell : public Event {

public:
    ~EmptyCell() override = default;
    void triggerEvent() override;
    std::string getDescription() const override {
        return "EC";
    };
};
