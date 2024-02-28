//
// Created by Егор Кулин on 28.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_MONITOR_H
#define DARKEST_DUNGEON_LITE_MONITOR_H
#include "ncurses.h"

class Monitor {
public:
    Monitor();
    void Draw(Drawable *drawable);
    void Clear();
    void Refresh();
    void End();
    void Print(int x, int y, const char *str);
    void Print(int x, int y, const char *str, int color);
};
#endif //DARKEST_DUNGEON_LITE_MONITOR_H
