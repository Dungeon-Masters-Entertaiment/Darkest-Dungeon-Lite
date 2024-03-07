//
// Created by Егор Кулин on 29.02.2024.
//
#include <ncurses.h>
int main(int argc, char **argv) {
    int x = 0;
    int y = 0;
    int c = 0;
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    do{
        clear();
        if(c == KEY_UP) y--;
        else if(c == KEY_DOWN) y++;
        else if(c == KEY_LEFT) x--;
        else if(c == KEY_RIGHT)x++;
        mvaddch(y, x, '@');
    }while((c = getch()) != 27);
    getch();
    endwin(); // завершение работы с ncurses

}