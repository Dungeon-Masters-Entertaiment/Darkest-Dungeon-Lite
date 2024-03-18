#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw() {
    monitor.draw_blinking_rectangle(20, 21, 22, 26, 2, 4);
    monitor.draw_rectangle(5, 6, 7, 8);
    for (auto& room : _rooms) {
        monitor.draw_rectangle((room->x * 3) - (room->width * 3) / 2, room->y * 3 - (room->height * 3) / 2, (room->x * 3 + (room->width + 1) * 3) / 2, (room->y * 3 + (room->height + 1) * 3) / 2);
        //monitor.draw_colored_rectangle((room->x * 3) - (room->width * 3) / 2, room->y * 3 - (room->height * 3) / 2, (room->x * 3 + (room->width + 1) * 3) / 2, (room->y * 3 + (room->height + 1) * 3) / 2, 5);
        //monitor.fill_rectangle((room->x * 3) - (room->width * 3) / 2, room->y * 3 - (room->height * 3) / 2, (room->x * 3 + (room->width + 1) * 3) / 2, (room->y * 3 + (room->height + 1) * 3) / 2, 5);
    }
    /*for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            monitor.draw_colored_rectangle((cell->x * 3) - (cell->width * 3) / 2, cell->y * 3 - (cell->height * 3) / 2, (cell->x * 3 + (cell->width + 3) * 5) / 2, (cell->y * 3 + (cell->height + 1) * 3) / 2, 4);
            monitor.fill_rectangle((cell->x * 3) - (cell->width * 3) / 2, cell->y * 3 - (cell->height * 3) / 2, (cell->x * 3 + (cell->width + 1) * 3) / 2, (cell->y * 3 + (cell->height + 1) * 3) / 2, 4);
        }
    }*/



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

