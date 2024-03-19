#include "view/graphics.h"
#include "../../keyboard.h"


auto begin_time = std::chrono::high_resolution_clock::now();

Monitor::Monitor() {
    // инициализация (должна быть выполнена
    // перед использованием ncurses)
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, TRUE);
    curs_set(0);
}
Monitor::~Monitor() {
    endwin(); // завершение работы с ncurses
}
void window_work::draw_dot(int x, int y) {
    mvwaddch(cur_win, y, x, '.');
}

void Dungeon_Map::display_hero() {
    mvwaddch(cur_win, y_cur, x_cur, '@');
    update();
}

void window_work::update() {
    wrefresh(cur_win);
}

void window_work::resize_win(int new_y, int new_x) {
    werase(cur_win);
    y_mx = new_y;
    x_mx = new_x;
    wresize(cur_win, y_mx, x_mx);
}

void window_work:: paint_sides() {
    box(cur_win, 0, 0);
    update();
}

void window_work::draw_rectangle(int x1, int y1, int x2, int y2) {
    mvwhline(cur_win, y1, x1, 0, x2 - x1);
    mvwhline(cur_win, y2, x1, 0, x2 - x1);
    mvwvline(cur_win, y1, x1, 0, y2 - y1);
    mvwvline(cur_win, y1, x2, 0, y2 - y1);

    mvwaddch(cur_win, y1, x1, ACS_ULCORNER);
    mvwaddch(cur_win, y2, x1, ACS_LLCORNER);
    mvwaddch(cur_win, y1, x2, ACS_URCORNER);
    mvwaddch(cur_win, y2, x2, ACS_LRCORNER);
}

void window_work::draw_colored_dot(int x, int y, int color) {
    wattron(cur_win, COLOR_PAIR(color));
    mvwaddch(cur_win, y, x, ACS_BULLET);
    wattroff(cur_win, COLOR_PAIR(color));
}

void window_work::draw_colored_rectangle(int x1, int y1, int x2, int y2, int color) {
    wattron(cur_win, COLOR_PAIR(color));

    mvwhline(cur_win, y1, x1, 0, x2 - x1);
    mvwhline(cur_win, y2, x1, 0, x2 - x1);
    mvwvline(cur_win, y1, x1, 0, y2 - y1);
    mvwvline(cur_win, y1, x2, 0, y2 - y1);

    mvwaddch(cur_win, y1, x1, ACS_ULCORNER);
    mvwaddch(cur_win, y2, x1, ACS_LLCORNER);
    mvwaddch(cur_win, y1, x2, ACS_URCORNER);
    mvwaddch(cur_win, y2, x2, ACS_LRCORNER);

    wattroff(cur_win, COLOR_PAIR(color));
}

void window_work::fill_rectangle(int x1, int y1, int x2, int y2, int colour) {
    wattron(cur_win, COLOR_PAIR(colour + 1));
    for(int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            mvwaddch(cur_win, y, x, ' ');
        }
    }
    wattroff(cur_win, COLOR_PAIR(colour + 1));
}

void window_work::draw_blinking_rectangle(int x1, int y1, int x2, int y2, short colour_1, short colour_2) {
    auto cur_time = std::chrono::high_resolution_clock::now();
    auto amount_of_time = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - begin_time);

    //getch();

    int col_flag = 0;

    draw_rectangle(x1, y1, x2, y2);
    if (amount_of_time.count() / 500 % 2) {
        //attron(COLOR_PAIR(colour_1 + 1));
        //col_flag = 1;
        fill_rectangle(x1, y1, x2, y2, colour_1);
    }
    else {
        fill_rectangle(x1, y1, x2, y2, colour_2);
        //attron(COLOR_PAIR(colour_2 + 1));
        //col_flag = 2;
    }
}

void window_work::fill_area(std::pair<int, int> *pairs, int color) {

}

Dungeon_Map :: Dungeon_Map(WINDOW* win, int y, int x) : window_work() {
    cur_win = win;
    y_cur = y;
    x_cur = x;
    getmaxyx(cur_win, y_mx, x_mx);
    keypad(cur_win, true);
    nodelay(cur_win, TRUE);
    start_color();
    for (int i = 0; i < 16; i++) {
        init_pair(i + 1, 1, i);
    }
}

void Dungeon_Map :: mv_up() {
    mvwaddch(cur_win, y_cur, x_cur, ' ');
    y_cur--;
    if(y_cur < 1) {
        y_cur = 1;
    }
}

void Dungeon_Map :: mv_down() {
    mvwaddch(cur_win, y_cur, x_cur, ' ');
    y_cur++;
    if(y_cur == y_mx - 1) {
        y_cur = y_mx - 2;
    }
}

void Dungeon_Map :: mv_left() {
    mvwaddch(cur_win, y_cur, x_cur, ' ');
    x_cur--;
    if(x_cur < 1) {
        x_cur = 1;
    }
}

void Dungeon_Map :: mv_right() {
    mvwaddch(cur_win, y_cur, x_cur, ' ');
    x_cur++;
    if(x_cur == x_mx - 1) {
        x_cur = x_mx - 2;
    }
}

int Dungeon_Map :: get_mv() {
    int cur_side = wgetch(cur_win);
    switch(cur_side) {
        case KEY_UP:
            mv_up();
            break;
        case KEY_DOWN:
            mv_down();
            break;
        case KEY_LEFT:
            mv_left();
            break;
        case KEY_RIGHT:
            mv_right();
            break;
        default:
            break;
    }
    return cur_side;
}

void Monitor::divide_screen() {
    int height, width;
    getmaxyx(stdscr, height, width);
    width = width - (width % 2 == 1);
    WINDOW *win = newwin(height / 3 * 2, width, 0, 0);
    WINDOW *win2 = newwin(height / 3, width / 2, height / 3 * 2, 0);
    WINDOW *win3 = newwin(height / 3, width / 2, height / 3 * 2, width / 2);
    auto Dung_Map = std::make_shared<Dungeon_Map>(win3, 1, 1); // Создаем класс карты
    refresh(); // Обновляем ВЕСЬ экран
    box(win, 0, 0);
    box(win2, 0, 0);
    Dung_Map -> paint_sides();
    wrefresh(win);
    wrefresh(win2);
    Dung_Map -> display_hero();
    AntohaFabric generator;
    static Map map = generator.Build(50, 50);
    int c;
    do {
        int n_height, n_width;
        getmaxyx(stdscr, n_height, n_width);
        if(n_height != height || n_width != width) {
            werase(win);
            werase(win2);
            height = n_height;
            width = n_width;
            width = width - (width % 2 == 1);
            wresize(win, height / 3 * 2, width);
            wresize(win2, height - height / 3 * 2, width / 2);
            mvwin(win2, height / 3 * 2, 0);
            Dung_Map -> resize_win(height - height / 3 * 2, width / 2);
            mvwin(win3, height / 3 * 2, width / 2);
            refresh();
        }
        Dung_Map -> paint_sides();
        box(win, 0, 0);
        box(win2, 0, 0);
        wrefresh(win);
        wrefresh(win2);
        c = Dung_Map -> get_mv();
        Dung_Map -> display_hero();
        map.Draw(Dung_Map);
    } while(c != 27);
}

//Все что ниже использовалось для копирования в класс window_work
//Все что ниже использовалось для копирования в класс window_work
//Все что ниже использовалось для копирования в класс window_work
//Все что ниже использовалось для копирования в класс window_work
//Все что ниже использовалось для копирования в класс window_work
//
//
//void Monitor::draw_rectangle(int x1, int y1, int x2, int y2) {
//    mvhline(y1, x1, 0, x2-x1);
//    mvhline(y2, x1, 0, x2-x1);
//    mvvline(y1, x1, 0, y2-y1);
//    mvvline(y1, x2, 0, y2-y1);
//    mvaddch(y1, x1, ACS_ULCORNER);
//    mvaddch(y2, x1, ACS_LLCORNER);
//    mvaddch(y1, x2, ACS_URCORNER);
//    mvaddch(y2, x2, ACS_LRCORNER);
//}
//
//void Monitor::draw_dot(int x, int y) {
//    mvaddch(y, x, '.');
//}
////making draw_circle method
//
//
//void Monitor::draw_hero_position(int x, int y) {
//    mvaddch(y, x, '@');
//}
//
//void Monitor::which_move(int input_char, int&x, int& y) {
//    if(input_char == KEY_UP) y--;
//    else if(input_char == KEY_DOWN) y++;
//    else if(input_char == KEY_LEFT) x--;
//    else if(input_char == KEY_RIGHT)x++;
//}
//
//void Monitor::make_an_event_loop() {
//
//    begin_time = std::chrono::high_resolution_clock::now();
//    int x = 0;
//    int y = 0;
//    int input_char = 0;
//    start_color();
//    init_pair(1, COLOR_RED, COLOR_BLACK);
//    init_pair(2, COLOR_GREEN, COLOR_BLACK);
//    init_pair(3, COLOR_BLUE, COLOR_BLACK);
//
//    /*do{
//        clear();
//
//        //draw_rectangle(3, 3, 7, 7);
//        //draw_rectangle(25, 10, 30, 20);
//        //draw_dot(5, 5);
//        //draw_dot(27, 15); //Ivan Tests
//
//        //draw_blinking_rectangle(8, 8, 15, 15, 2, 4);
//        //std::vector<std::pair <int, int>> cur = {{3, 4}, {5, 6}};
//        //draw_blinking_area(cur, 2, 4); //Ruslan Tests
//
//        //draw_colored_dot(5, 5, 1);
//        //draw_colored_rectangle(20, 5, 30, 10, 2);
//        //fill_rectangle(40, 5, 50, 10, 3); //Alena Tests
//
//        draw_colored_dot(x, y, 2);
//        which_move(input_char, x, y);
//        draw_hero_position(x, y);
//    }while((input_char = getch()) != 27); //27 is ESC
//    getch(); // ждём нажатия символа
//    endwin();*/
//
//
//    // подсказка
//    /*
//    // Измеряем размер экрана в рядах и колонках
//    int row, col;
//    getmaxyx(stdscr, row, col);
//    // перемещение курсора в стандартном экране
//    move(row / 2, col / 2 - 25);
//    printw("Hello world"); // вывод строки
//    refresh(); // обновить экран
//    */
//}
//
//
//void Monitor::draw_blinking_rectangle(int x1, int y1, int x2, int y2, short colour_1, short colour_2) {
//
//    auto cur_time = std::chrono::high_resolution_clock::now();
//    auto amount_of_time = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - begin_time);
//
//    start_color();
//    init_pair(1, 1, colour_1);
//    init_pair(2, 1, colour_2);
//
//    //attron(COLOR_PAIR(1));
//    int col_flag = 0;
//    if (amount_of_time.count() / 500 % 2) {
//        attron(COLOR_PAIR(1));
//        //attron(1);
//        col_flag = 1;
//    }
//    else {
//        attron(COLOR_PAIR(2));
//        //attron(2);
//        col_flag = 4;
//    }
//    for(int i = x1; i <= x2; i++) {
//        for (int j = y1; j < y2; j++) {
//            mvprintw(j, i, " ");
//        }
//    }
//    //if (amount_of_time.count() % 500 < 100) refresh();
//    //attroff(COLOR_PAIR(1));
//
//    if (col_flag == 1) attroff(COLOR_PAIR(1)); //attroff(1);//attroff(COLOR_PAIR(1));
//    else attroff(COLOR_PAIR(2)); //attroff(2); //attroff(COLOR_PAIR(2));
//
//}
//
//void Monitor::draw_blinking_area(std::vector <std::pair<int, int>>& pairs, short colour_1, short colour_2) {
//    auto cur_time = std::chrono::high_resolution_clock::now();
//    auto amount_of_time = std::chrono::duration_cast<std::chrono::milliseconds>(cur_time - begin_time);
//
//    start_color();
//    init_pair(1, 1, colour_1);
//    init_pair(2, 1, colour_2);
//
//    int col_flag = 0;
//    if (amount_of_time.count() / 500 % 2) {
//        attron(COLOR_PAIR(1));
//        col_flag = 1;
//    }
//    else {
//        attron(COLOR_PAIR(2));
//        col_flag = 4;
//    }
//    for(auto & pair : pairs) {
//        mvprintw(pair.second, pair.first, " ");
//    }
//    if (col_flag == 1) attroff(COLOR_PAIR(1)); //attroff(1);//attroff(COLOR_PAIR(1));
//    else attroff(COLOR_PAIR(2)); //attroff(2); //attroff(COLOR_PAIR(2));
//
//}
//
//
//void Monitor::draw_circle(int x0, int y0, int r) {
//    const int N = 100;
//    const int SIZE = 2 * r + 1;
//    const double PI = 4 * atan( 1.0 );
//    double dtheta = 2.0 * PI / N;
//    for ( int t = 0; t < N; t++ ) {
//        double theta = PI - ( t + 1 ) * dtheta;
//        int i = 0.5 * ( 1 + cos( theta )) * ( SIZE - 1 ) + 0.5;
//        int j = 0.5 * ( 1 + sin( theta )) * ( SIZE - 1 ) + 0.5;
//        mvaddch(j + y0, i + x0, '*');
//    }
//}
//
//void Monitor::draw_colored_dot(int x, int y, int color) {
//    attron(COLOR_PAIR(color));
//    mvaddch(y, x, ACS_BULLET);
//    attroff(COLOR_PAIR(color));
//}
//
//void Monitor::draw_colored_rectangle(int x1, int y1, int x2, int y2, int color) {
//    attron(COLOR_PAIR(color));
//
//    mvhline(y1, x1, 0, x2 - x1);
//    mvhline(y2, x1, 0, x2 - x1);
//    mvvline(y1, x1, 0, y2 - y1);
//    mvvline(y1, x2, 0, y2 - y1);
//
//    mvaddch(y1, x1, ACS_ULCORNER);
//    mvaddch(y2, x1, ACS_LLCORNER);
//    mvaddch(y1, x2, ACS_URCORNER);
//    mvaddch(y2, x2, ACS_LRCORNER);
//
//    attroff(COLOR_PAIR(color));
//}
//
//void Monitor::fill_rectangle(int x1, int y1, int x2, int y2, int color) {
//    attron(COLOR_PAIR(color));
//    for(int y = y1; y <= y2; y++) {
//        for (int x = x1; x <= x2; x++) {
//            mvaddch(y, x, ' ' | A_REVERSE);
//        }
//
//    }
//    attroff(COLOR_PAIR(color));
//}
