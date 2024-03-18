#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw() {

    for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            //monitor.draw_rectangle(cell->x - cell->width / 2, cell->y - cell->height / 2, cell->x + (cell->width + 1) / 2, cell->y + (cell->height + 1) / 2);
            //monitor.fill_rectangle(cell->x - cell->width / 2, cell->y - cell->height / 2, cell->x + (cell->width + 1) / 2, cell->y + (cell->height + 1) / 2, COLOR_GREEN);

            monitor.draw_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height);
            monitor.fill_rectangle(2 * cell->x + 2, cell->y + 1, 2 * (cell->x + cell->width) + 1, cell->y + cell->height, COLOR_GREEN);

        }
    }

    for (auto& room : _rooms) {
        //monitor.draw_rectangle(room->x - room->width / 2, room->y - room->height / 2, room->x + (room->width + 1) / 2, room->y + (room->height + 1) / 2);
        //monitor.fill_rectangle(room->x - room->width / 2, room->y - room->height / 2, room->x + (room->width + 1) / 2, room->y + (room->height + 1) / 2, COLOR_RED);

        monitor.draw_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1);
        monitor.fill_rectangle(2 * room->x, room->y, 2 * (room->x + room->width) - 1, room->y + room->height - 1, COLOR_RED);
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

