#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw(std::shared_ptr<window_work> monitor, FSMGame & fsm) {

    int height, width;
    getmaxyx(stdscr, height, width);
    int center_x = width/2;
    int center_y = height/2;

    auto current_monitor = std::dynamic_pointer_cast<Dungeon_Map>(monitor);
    for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            //monitor.draw_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height);
            //monitor.fill_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height, COLOR_GREEN);

            //current_monitor->draw_blinking_rectangle(2 * (cell->x - fsm.this_room->x + 1) + center_x, (cell->y - fsm.this_room->y + 1) + center_y, 2 * (cell->x - fsm.this_room->x + cell->width) + 1  + center_y, cell->y - fsm.this_room->x + cell->height + center_x, COLOR_GREEN, COLOR_RED);
            current_monitor->draw_blinking_rectangle(2 * cell->x + 4 - 15, cell->y + 2 - 15, 2 * (cell->x + cell->width) + 3 - 15, cell->y + cell->height + 1 - 15, COLOR_GREEN, COLOR_RED);
        }
    }

    for (auto& room : _rooms) {
        //monitor.draw_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1);
        //monitor.fill_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1, COLOR_RED);

        //current_monitor->draw_blinking_rectangle(2 * (room->x - fsm.this_room->x + 1) + center_x, (room->y - fsm.this_room->y + 1) + center_y, 2 * (room->x - fsm.this_room->x + room->width) + 1  + center_y, room->y - fsm.this_room->x + room->height + center_x, COLOR_GREEN, COLOR_RED);
        //current_monitor->draw_blinking_rectangle(2 * (room->x - fsm.this_room->x + 1), (room->y - fsm.this_room->y + 1), 2 * (room->x - fsm.this_room->x + room->width) + 1, room->y - fsm.this_room->x + room->height, COLOR_GREEN, COLOR_RED);
        current_monitor->draw_blinking_rectangle(2 * room->x + 2 - 15, room->y + 1 - 15, 2 * (room->x + room->width) + 1 - 15, room->y + room->height - 15, COLOR_CYAN, COLOR_MAGENTA);
    }
    current_monitor->draw_blinking_rectangle(2 * fsm.this_room->x + 2 - 15, fsm.this_room->y + 1 - 15, 2 * (fsm.this_room->x + fsm.this_room->width) + 1 - 15, fsm.this_room->y + fsm.this_room->height - 15, COLOR_BLUE, COLOR_YELLOW);
    //current_monitor->draw_blinking_rectangle(center_x + 2, 1 + center_y, 2 * (center_x - fsm.this_room->x + fsm.this_room->width) + 1  + center_y, 2 * fsm.this_room->width + 1  + center_y, COLOR_GREEN, COLOR_RED);


    //current_monitor->draw_blinking_rectangle(2 * fsm.this_room->x)


    // debug-вывод
    /*for (int i = 0; i < _body.size(); i++) {
        for (int j = 0; j < _body[i].size(); j++) {
            switch (_body[i][j]) {
                case ' ':
                    std::cout << " ";  // Empty space
                    break;
                case 'R':
                    std::cout << "R";  // Room
                    break;
                case 'C':
                    std::cout << "C";  // Corridor
                    break;
            }
        }
        std::cout << std::endl;
    }*/


}
