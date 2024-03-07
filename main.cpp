//
// Created by Егор Кулин on 29.02.2024.
//
#include <ncurses.h>
#include <vector>

//#include "graphics.h"



int main(int argc, char **argv) {

    initscr();

    int row = 50, col = 50;

    move(row / 2, col / 2);



    refresh(); // обновить экран
    getch(); // ждём нажатия символа

    endwin(); // завершение работы с ncurses

}