#ifndef DARKEST_DUNGEON_LITE_DRAWABLE_H
#define DARKEST_DUNGEON_LITE_DRAWABLE_H

#include "memory.h"
#include "../../view/graphics.h"
class window_work;
class AbstractDrawable {
public:
    virtual void Draw(std::shared_ptr<window_work>, FSMGame &) = 0;
};

#endif //DARKEST_DUNGEON_LITE_DRAWABLE_H