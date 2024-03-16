#include "Hall.h"
 
void fill_rooms_in_hall(int x, int y, int x1, int y1, int type, int width, int height, std::vector<std::vector<char>> &_body, std::vector<std::shared_ptr <Cell>> &rooms_in_hall) {
    if (abs(x - x1) == 0) {
        type = 1; 
    }

    else if (abs(y - y1) == 0) {
        type = 0;
    }

    else if(abs(x - x1) <= 2 && abs(x - x1) != 0) {
        int k = (y < y1) * 2 - 1;
        fill_rooms_in_hall(x, y, x, y + 3 * k, type, width, height, _body, rooms_in_hall);
        fill_rooms_in_hall(x, y + 3 * k, x1, y + 3 * k, type, width, height, _body, rooms_in_hall);
        fill_rooms_in_hall(x1, y + 3 * k, x1, y1, type, width, height, _body, rooms_in_hall);
        return;
    }

    else if(abs(y - y1) <= 2 && abs(y - y1) != 0) {
        int k = (x < x1) * 2 - 1;
        fill_rooms_in_hall(x, y, x + 3 * k, y, type,  width, height,_body, rooms_in_hall);
        fill_rooms_in_hall(x + 3 * k, y, x + 3 * k, y1, type, width, height, _body, rooms_in_hall);
        fill_rooms_in_hall(x + 3 * k, y1, x1, y1, type,  width, height,_body, rooms_in_hall);
        return;
    }
    int last_i = -1, last_i1 = -1;
 
    if(type == 0) {
        int i = x;
        int i1 = y;
        while(i != x1) {
            if(_body[i][y] == 'C' && (last_i != i || last_i1 != y)) {
                rooms_in_hall.push_back(std::make_shared<Cell>(i, y, 3, 3));
                last_i = i;
                last_i1 = y;
                int siz = rooms_in_hall.size() - 1;
                if(rooms_in_hall.size() == 1){
                    rooms_in_hall[siz] -> conection;
                }
            }
            if(i <= x1) i++;
            else i--;
        }
        if(_body[i][y] == 'C' && (last_i != i || last_i1 != y)){
            rooms_in_hall.push_back(std::make_shared<Cell>(i, y, 3, 3));
            last_i = i;
            last_i1 = y;
        }
        while(i1 != y1) {
            if(_body[x1][i1] == 'C' && (last_i != x1 || last_i1 != i1)){
                rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
                last_i = x1;
                last_i1 = i1;
            }
            if(i1 < y1) i1++;
            else i1--;
        }
        if(_body[x1][i1] == 'C' && (last_i != x1 || last_i1 != i1)) {
            rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
            last_i = x1;
            last_i1 = i1;
        }
 
    } else {

        int i = x;
        int i1 = y;
        while(i1 != y1) {
            if(_body[x][i1] == 'C' && (last_i != x || last_i1 != i1)) {
                rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
                last_i = x;
                last_i1 = i1;
            }
            if(i1 < y1) i1++;
            else i1--;
        }
        if(_body[x][i1] == 'C' && (last_i != x || last_i1 != i1)) {
            rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
            last_i = x;
            last_i1 = i1;
        }
        while(i != x1) {
            if(_body[i][y1] == 'C' && (last_i != i || last_i1 != y1)) {
                rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
                last_i = i;
                last_i1 = y1;
            }
            if(i <= x1) i++;
            else i--;
        }
        if(_body[i][y1] == 'C' && (last_i != i || last_i1 != y1)) {
            rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
            last_i = i;
            last_i1 = y1;
        }
    }
    return;

}

Hall::Hall(std::shared_ptr<Cell> first, std::shared_ptr<Cell> second) {

}