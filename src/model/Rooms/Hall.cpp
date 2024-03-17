#include "Hall.h"

void fill_rooms_in_hall(int x, int y, int x1, int y1, int type, int width, int height, std::vector<std::vector<char>> &_body, Hall &first) {
    if (abs(x - x1) == 0) {
        type = 1; 
    }

    else if (abs(y - y1) == 0) {
        type = 0;
    }

    else if(abs(x - x1) <= 2 && abs(x - x1) != 0) {
        int k = (y < y1) * 2 - 1;
        fill_rooms_in_hall(x, y, x, y + 3 * k, type, width, height, _body, first);
        fill_rooms_in_hall(x, y + 3 * k, x1, y + 3 * k, type, width, height, _body, first);
        fill_rooms_in_hall(x1, y + 3 * k, x1, y1, type, width, height, _body, first);
        return;
    }

    else if(abs(y - y1) <= 2 && abs(y - y1) != 0) {
        int k = (x < x1) * 2 - 1;
        fill_rooms_in_hall(x, y, x + 3 * k, y, type,  width, height,_body, first);
        fill_rooms_in_hall(x + 3 * k, y, x + 3 * k, y1, type, width, height, _body, first);
        fill_rooms_in_hall(x + 3 * k, y1, x1, y1, type,  width, height,_body, first);
        return;
    }

   // int last_i = -1, last_i1 = -1;
    int last = 0;
    //std::shared_ptr<Cell> previous_cell = first.entrance;

    if(type == 0) {
        int i = x;
        int i1 = y;
        while(i != x1) {
            if(_body[i][y] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != i  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != y ))) {
                first.rooms_in_hall.push_back(std::make_shared<Cell>(i, y, 3, 3));
                if(first.rooms_in_hall.size() == 1) {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.entrance;
                } else {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                    first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
              //                  std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
                }
                // last_i = i;
                // last_i1 = y;
            }
            if(i <= x1) {i++; last = 1;}
            else {i--; last = 3;};
        }
        if(_body[i][y] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != i  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != y ))){
            first.rooms_in_hall.push_back(std::make_shared<Cell>(i, y, 3, 3));
            if(first.rooms_in_hall.size() == 1) {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.entrance;
            } else {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
            //                        std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
            }
            // last_i = i;
            // last_i1 = y;
        }
        while(i1 != y1) {
            if(_body[x1][i1] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != x1  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != i1 ))){
                //rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
                first.rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
                if(first.rooms_in_hall.size() == 1) {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1]  = first.entrance;
                } else {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                    first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
                 //                       std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
                }
                // last_i = x1;
                // last_i1 = i1;
            }
            if(i1 < y1) {i1++; last = 4;}
            else {i1--, last = 2;};
        }
        if(_body[x1][i1] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != x1  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != i1 ))) {
            //rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
            first.rooms_in_hall.push_back(std::make_shared<Cell>(x1, i1, 3, 3));
            if(first.rooms_in_hall.size() == 1) {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last -1 ] = first.entrance;
            } else {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
            //                        std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
            }
            // last_i = x1;
            // last_i1 = i1;
        }
 
    } else {

        int i = x;
        int i1 = y;
        while(i1 != y1) {
            if(_body[x][i1] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != x  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != i1 ))) {
                //rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
                first.rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
                if(first.rooms_in_hall.size() == 1) {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last -1 ] = first.entrance;
                } else {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last -1 ] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                    first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last -1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
          //                              std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
                }
                // last_i = x;
                // last_i1 = i1;
            }
            if(i1 < y1) {i1++; last = 4;}
            else {i1--; last = 2;}
        }
        if(_body[x][i1] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != x  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != i1 ))) {
            //rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
            first.rooms_in_hall.push_back(std::make_shared<Cell>(x, i1, 3, 3));
            if(first.rooms_in_hall.size() == 1) {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.entrance;
            } else {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
             //                       std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
            }
            // last_i = x;
            // last_i1 = i1;
        }
        while(i != x1) {
            if(_body[i][y1] == 'C' && (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != i  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != y1 ))) {
                //rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
                first.rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
                if(first.rooms_in_hall.size() == 1) {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.entrance;
                } else {
                    first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                    first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last -1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
                //                        std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
                }
                // last_i = i;
                // last_i1 = y1;
            }
            if(i <= x1) {i++; last = 1;}
            else {i--; last = 3;}
        }
        if(_body[i][y1] == 'C' &&  (first.rooms_in_hall.size() == 0 || (first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x != i  || first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y != y1 ))) {
            //rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
            first.rooms_in_hall.push_back(std::make_shared<Cell>(i, y1, 3, 3));
            if(first.rooms_in_hall.size() == 1) {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.entrance;
            } else {
                first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[last - 1] = first.rooms_in_hall[first.rooms_in_hall.size() - 2];
                first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> conection[(last - 1 + 2) % 4] = first.rooms_in_hall[first.rooms_in_hall.size() - 1];
               //                     std::cout<<first.rooms_in_hall.size()<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y<<"  "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> x<<" "<<first.rooms_in_hall[first.rooms_in_hall.size() - 2] -> y<< "   "<< last<<"    ";
            }
            // last_i = i;
            // last_i1 = y1;
        }
    }

    if(abs(first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> x - first.exit -> x) + abs(first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> y - first.exit -> y) <= 2) {
        first.rooms_in_hall[first.rooms_in_hall.size() - 1] -> conection[(last - 1 + 2) % 4] = first.exit ;
    }

    return;

}

Hall::Hall(std::shared_ptr<Room> first, std::shared_ptr<Room> second, int type, int width, int height, std::vector<std::vector<char>> _body) {
    if(first -> id > second -> id) {
        swap(first, second);
    }
    entrance = first;
    exit = second;
    fill_rooms_in_hall(first -> x, first -> y, second -> x, second -> y, type, width, height, _body, *this);
}