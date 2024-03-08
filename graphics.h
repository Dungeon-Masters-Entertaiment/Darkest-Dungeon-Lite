//
// Created by Ivan Novikov on 07.03.2024.
//
#ifndef DARKEST_DUNGEON_LITE_GRAPHICS_H
#define DARKEST_DUNGEON_LITE_GRAPHICS_H

#include <iostream>
#include <vector>

#include <ncurses.h>



class Monitor{
public:
    Monitor();
    ~Monitor();
    void draw_rectangle(int x1, int y1, int x2, int y2);
    void draw_hero_position(int x, int y);
};




#endif //DARKEST_DUNGEON_LITE_GRAPHICS_H

