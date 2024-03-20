#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw(std::shared_ptr<window_work> monitor, FSMGame & fsm) {

    auto Dung_monitor = std::dynamic_pointer_cast<Dungeon_Map>(monitor);
    int height, width;
    getmaxyx(Dung_monitor -> cur_win, height, width);
    int center_x = width / 2;
    int center_y = height / 2;
    int cur_pos_y = fsm.this_room-> y + 2;
    int cur_pos_x = 2 * fsm.this_room-> x + 4;
    werase(Dung_monitor -> cur_win);
    for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            //monitor.draw_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height);
            //monitor.fill_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height, COLOR_GREEN);

            //Dung_monitor->draw_blinking_rectangle(2 * (cell->x - fsm.this_room->x + 1) + center_x, (cell->y - fsm.this_room->y + 1) + center_y, 2 * (cell->x - fsm.this_room->x + cell->width) + 1  + center_y, cell->y - fsm.this_room->x + cell->height + center_x, COLOR_GREEN, COLOR_RED);
            Dung_monitor->fill_rectangle(2 * cell -> x + 4  + (center_x - cur_pos_x), cell->y + 2 + (center_y - cur_pos_y), 2 * (cell->x + cell->width) + 3 + (center_x - cur_pos_x), cell->y + cell->height + 1 + (center_y - cur_pos_y), COLOR_GREEN);
        }
    }

    for (auto& room : _rooms) {
        //monitor.draw_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1);
        //monitor.fill_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1, COLOR_RED);

        //Dung_monitor->draw_blinking_rectangle(2 * (room->x - fsm.this_room->x + 1) + center_x, (room->y - fsm.this_room->y + 1) + center_y, 2 * (room->x - fsm.this_room->x + room->width) + 1  + center_y, room->y - fsm.this_room->x + room->height + center_x, COLOR_GREEN, COLOR_RED);
        //Dung_monitor->draw_blinking_rectangle(2 * (room->x - fsm.this_room->x + 1), (room->y - fsm.this_room->y + 1), 2 * (room->x - fsm.this_room->x + room->width) + 1, room->y - fsm.this_room->x + room->height, COLOR_GREEN, COLOR_RED);
        Dung_monitor->fill_rectangle(2 * room->x + 2 + (center_x - cur_pos_x), room->y + 1 + (center_y - cur_pos_y), 2 * (room->x + room->width) + 1 + (center_x - cur_pos_x), room->y + room->height + (center_y - cur_pos_y), COLOR_CYAN);
    }
    Dung_monitor->fill_rectangle(2 * fsm.this_room->x + 2 + (center_x - cur_pos_x), fsm.this_room->y + 1 + (center_y - cur_pos_y), 2 * (fsm.this_room->x + fsm.this_room->width) + 1 + (center_x - cur_pos_x), fsm.this_room->y + fsm.this_room->height + (center_y - cur_pos_y), COLOR_BLUE);
    //Dung_monitor->draw_blinking_rectangle(center_x + 2, 1 + center_y, 2 * (center_x - fsm.this_room->x + fsm.this_room->width) + 1  + center_y, 2 * fsm.this_room->width + 1  + center_y, COLOR_GREEN, COLOR_RED);

    //Dung_monitor->draw_blinking_rectangle(2 * fsm.this_room->x)


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
