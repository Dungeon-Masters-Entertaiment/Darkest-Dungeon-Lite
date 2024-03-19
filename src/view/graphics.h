//
// Created by Ivan Novikov on 07.03.2024.
//
#ifndef DARKEST_DUNGEON_LITE_GRAPHICS_H
#define DARKEST_DUNGEON_LITE_GRAPHICS_H

#include "../../BMP.h"
#include <chrono>
#include <cmath>
#include "controller/FSM.h"
#include "controller/Game.h"
class Monitor{
public:
    Monitor();
    ~Monitor();
    void make_an_event_loop(FSMGame fsm);
};




#endif //DARKEST_DUNGEON_LITE_GRAPHICS_H

