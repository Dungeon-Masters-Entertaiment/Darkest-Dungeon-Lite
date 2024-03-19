#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw(std::shared_ptr<window_work> monitor) {
    auto current_monitor = std::dynamic_pointer_cast<Dungeon_Map>(monitor);
    for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            //monitor.draw_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height);
            //monitor.fill_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height, COLOR_GREEN);
            current_monitor->draw_blinking_rectangle(2 * cell->x + 2 - 15, cell->y + 1 - 15, 2 * (cell->x + cell->width) + 1 - 15, cell->y + cell->height - 15, COLOR_GREEN, COLOR_RED);
        }
    }

    for (auto& room : _rooms) {
        //monitor.draw_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1);
        //monitor.fill_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1, COLOR_RED);
        current_monitor->draw_blinking_rectangle(2 * room->x - 15, room->y - 15, 2 * (room->x + room->width) - 1 - 15, room->y + room->height - 1 - 15, COLOR_RED, COLOR_GREEN);
    }
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
