#include "view/graphics.h"
#include "../../keyboard.h"
#include "../../BMP.h"

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

void Monitor::make_an_event_loop(FSMGame fsm) {
    int input_char = 0;
    do{
        clear();
        if(input_char) Keyboard::getInstance().change_key(KeyboardKey(input_char));
        // STATE_MACHINE
        fsm.Update();
        
    }while((input_char = getch()) != ((int)KeyboardKey::ESC)); //27 is ESC

    getch(); 

    endwin();
}
