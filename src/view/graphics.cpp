#include "view/graphics.h"
#include "../../keyboard.h"
#include "../../BMP.h"
//#include <chrono>
//#include <thread>

Monitor::Monitor() {
    // инициализация (должна быть выполнена
    // перед использованием ncurses)
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
}

Monitor::~Monitor() {
    endwin(); // завершение работы с ncurses
}

void Monitor::make_an_event_loop(FSMGame fsm) {
    int input_char = -1;
    do{

        Keyboard::getInstance().change_key(input_char);
        // STATE_MACHINE
        fsm.Update();
        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
    }while((input_char = getch()) != ((int)KeyboardKey::ESC)); //27 is ESC

    getch(); 

    endwin();
}
