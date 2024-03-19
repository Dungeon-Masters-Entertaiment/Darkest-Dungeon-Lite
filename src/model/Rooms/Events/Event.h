#pragma once
#include <string>

class Event {
public:
    virtual ~Event() = default;
    virtual void triggerEvent() = 0;
    virtual std::string getDescription() const = 0;
};
