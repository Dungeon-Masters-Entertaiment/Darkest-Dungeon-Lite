#include "model/Drawable/Map.h"
#include "view/graphics.h"




void Map::Draw() {

    Monitor monitor;
    for (auto& room : _rooms) {
        monitor.draw_colored_rectangle(room->x, room->y, room->width, room->height, 1);
    }
    for (auto& hall : _halls) {
        for (auto& cell : hall->rooms_in_hall){
            monitor.draw_colored_rectangle(cell->x, cell->y, cell->width, cell->height, 3);
        }
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