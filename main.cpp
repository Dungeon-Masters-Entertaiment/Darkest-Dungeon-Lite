//
// Created by Егор Кулин on 29.02.2024.
//
#include "graphics.h"

void rectangle(int y1, int x1, int y2, int x2)
{

}

int main(int argc, char **argv) {
    // /*
    //std::cout << char(27) << '\n';
    int x = 0;
    int y = 0;
    int input_char = 0;

    Monitor monitor;




    do{
        clear();
        //WINDOW * win = newwin(3, 3, 5, 5);
        //
        monitor.draw_rectangle(3, 3, 7, 7);

        if(input_char == KEY_UP) y--;
        else if(input_char == KEY_DOWN) y++;
        else if(input_char == KEY_LEFT) x--;
        else if(input_char == KEY_RIGHT)x++;

        monitor.draw_hero_position(x, y);
    }while((input_char = getch()) != 27);
    getch();
    //endwin(); // завершение работы с ncurses




    //*/

    /*

    // инициализация (должна быть выполнена
    // перед использованием ncurses)
    initscr();

    // Измеряем размер экрана в рядах и колонках
    int row, col;
    getmaxyx(stdscr, row, col);

    // перемещение курсора в стандартном экране
    move(row / 2, col / 2 - 25);

    printw("Hello world"); // вывод строки
    refresh(); // обновить экран
    getch(); // ждём нажатия символа

    endwin(); // завершение работы с ncurses
    */
}
