#ifndef ITEMS_H
#define ITEMS_H
#include <string>

class Item {
public:
    virtual ~Item() = default;
    virtual void use() = 0;
    virtual std::string getDescription() const = 0;
};
#endif
