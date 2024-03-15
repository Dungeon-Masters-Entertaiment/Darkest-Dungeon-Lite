//
// Created by Ivan Novikov on 08.03.2024.
//

#include "graphics.h"
#include "BMP.h"

auto begin_time = std::chrono::high_resolution_clock::now();
Monitor::Monitor() {
    // инициализация (должна быть выполнена
    // перед использованием ncurses)
    initscr();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
}
Monitor::~Monitor() {
    endwin(); // завершение работы с ncurses
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

    start_color(); 
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    do{
        clear();
        // draw_rectangle(3, 3, 7, 7);
        // draw_rectangle(25, 10, 30, 20);

        // draw_dot(5, 5);
        // draw_dot(27, 15);

        // draw_blinking_rectangle(8, 8, 15, 15, 2, 4);

        draw_colored_dot(5, 5, 1); 
        draw_colored_rectangle(20, 5, 30, 10, 2); 
        fill_rectangle(40, 5, 50, 10, 3);

        if(input_char == KEY_UP) y--;
        else if(input_char == KEY_DOWN) y++;
        else if(input_char == KEY_LEFT) x--;
        else if(input_char == KEY_RIGHT)x++;
        draw_colored_dot(x, y, 2);
        // draw_hero_position(x, y);
    }while((input_char = getch()) != 27);
    getch(); // ждём нажатия символа
    endwin();


    // подсказка
    /*
    // Измеряем размер экрана в рядах и колонках
    int row, col;
    getmaxyx(stdscr, row, col);
    // перемещение курсора в стандартном экране
    move(row / 2, col / 2 - 25);
    printw("Hello world"); // вывод строки
    refresh(); // обновить экран
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

void Monitor::draw_blinking_area(std::vector <std::pair<int, int>>& pairs, short colour_1, short colour_2) {
    auto cur_time = std::chrono::high_resolution_clock::now();
    auto amount_of_time = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - begin_time);

    start_color();
    init_pair(1, 1, colour_1);
    init_pair(2, 1, colour_2);

    int col_flag = 0;
    if (amount_of_time.count() / 500 % 2) {
        attron(COLOR_PAIR(1));
        col_flag = 1;
    }
    else {
        attron(COLOR_PAIR(2));
        col_flag = 4;
    }
    for(auto & pair : pairs) {
        mvprintw(pair.second, pair.first, " ");
    }
    if (col_flag == 1) attroff(COLOR_PAIR(1)); //attroff(1);//attroff(COLOR_PAIR(1));
    else attroff(COLOR_PAIR(2)); //attroff(2); //attroff(COLOR_PAIR(2));

}

void Monitor::draw_circle(int x0, int y0, int r) {
    const int N = 100;
    const int SIZE = 2 * r + 1;
    const double PI = 4 * atan( 1.0 );
    double dtheta = 2.0 * PI / N;
    for ( int t = 0; t < N; t++ ) {
        double theta = PI - ( t + 1 ) * dtheta;
        int i = 0.5 * ( 1 + cos( theta )) * ( SIZE - 1 ) + 0.5;
        int j = 0.5 * ( 1 + sin( theta )) * ( SIZE - 1 ) + 0.5;
        mvaddch(j + y0, i + x0, '*');
    }
}

void Monitor::draw_colored_dot(int x, int y, int color) {
    attron(COLOR_PAIR(color)); 
    mvaddch(y, x, ACS_BULLET); 
    attroff(COLOR_PAIR(color)); 
}

void Monitor::draw_colored_rectangle(int x1, int y1, int x2, int y2, int color) {
    attron(COLOR_PAIR(color));

    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);

    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);

    attroff(COLOR_PAIR(color));
}

void Monitor::fill_rectangle(int x1, int y1, int x2, int y2, int color) {
    attron(COLOR_PAIR(color));
    for(int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            mvaddch(y, x, ' ' | A_REVERSE); 
        } 
        
    }

    attroff(COLOR_PAIR(color));
}