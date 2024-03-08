//
// Created by Ivan Novikov on 08.03.2024.
//

#include "graphics.h"

Monitor::Monitor() {
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
}
Monitor::~Monitor() {
    endwin();
}

void Monitor::draw_rectangle(int x1, int y1, int x2, int y2) {
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void Monitor::draw_hero_position(int x, int y) {
    mvaddch(y, x, '@');
}
