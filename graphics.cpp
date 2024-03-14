//
// Created by Ivan Novikov on 08.03.2024.
//

#include "graphics.h"
#include "BMP.h"
auto begin_time = std::chrono::high_resolution_clock::now();
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

void Monitor::draw_dot(int x, int y) {
    mvaddch(y, x, '.');
}
//making draw_circle method


void Monitor::draw_hero_position(int x, int y) {
    mvaddch(y, x, '@');
}

void Monitor::make_an_event_loop() {

    begin_time = std::chrono::high_resolution_clock::now();

    int x = 0;
    int y = 0;
    int input_char = 0;

    do{
        clear();
        draw_rectangle(3, 3, 7, 7);
        draw_rectangle(25, 10, 30, 20);

        draw_dot(5, 5);
        draw_dot(27, 15);

        draw_blinking_rectangle(8, 8, 15, 15, 2, 4);

        if(input_char == KEY_UP) y--;
        else if(input_char == KEY_DOWN) y++;
        else if(input_char == KEY_LEFT) x--;
        else if(input_char == KEY_RIGHT)x++;

        draw_hero_position(x, y);
    }while((input_char = getch()) != 27);
    getch();
    endwin();




    // это просто пример работы с ncurses
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

void Monitor::draw_blinking_rectangle(int x1, int y1, int x2, int y2, short colour_1, short colour_2) {

    auto cur_time = std::chrono::high_resolution_clock::now();
    auto amount_of_time = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - begin_time);

    start_color();
    init_pair(1, 1, colour_1);
    init_pair(2, 1, colour_2);

    //attron(COLOR_PAIR(1));
    int col_flag = 0;
    if (amount_of_time.count() / 500 % 2) {
        attron(COLOR_PAIR(1));
        //attron(1);
        col_flag = 1;
    }
    else {
        attron(COLOR_PAIR(2));
        //attron(2);
        col_flag = 4;
    }
    for(int i = x1; i <= x2; i++) {
        for (int j = y1; j < y2; j++) {
            mvprintw(j, i, " ");
        }
    }
    //if (amount_of_time.count() % 500 < 100) refresh();
    //attroff(COLOR_PAIR(1));

    if (col_flag == 1) attroff(COLOR_PAIR(1)); //attroff(1);//attroff(COLOR_PAIR(1));
    else attroff(COLOR_PAIR(2)); //attroff(2); //attroff(COLOR_PAIR(2));

}