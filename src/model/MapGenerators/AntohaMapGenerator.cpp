#include "MapFabric.h"
#include <iostream>
#include "../Drawable/Map.h"
#include "../Rooms/Hall.h"

char get_zn(int x, int y, int width, int height, std::vector<std::vector<char>> &_body){
    if(x < 0 || x >= width || y < 0 || y >= height) {
        return ' ';
    }
    return _body[x][y];
}

void change_zn(int x, int y,int width, int height, std::vector<std::vector<char>> &_body) {
    if(x >= 0 && x < width && y < height && y >=0) {
        _body[x][y] = ' ';
    }
}

void clear_point(int x, int y, int width, int height, std::vector<std::vector<char>> &_body) {
    for(int i = -1; i <= 1; i++) {
        for(int i1 = -1; i1 <= 1; i1++) {
            change_zn(x + i, y + i1, width, height, _body);
        }
    }
}

bool search_around (int x, int y, int width, int height, std::vector<std::vector<char>> &_body) 
{
    for (int i = -4; i <= 4; i++) {
        for(int i1 = -4; i1 <= 4; i1++) {
            if(get_zn(x + i, y + i1, width, height, _body) != ' ') {
                return false;
            }
        }
    }
    return true;
}

bool small_search_around (int x, int y, int width, int height, std::vector<std::vector<char>> &_body) 
{
    for (int i = -1; i <= 1; i++) {
        for(int i1 = -1; i1 <= 1; i1++) {
            if(get_zn(x + i, y + i1, width, height, _body) != ' ') {
                return false;
            }
        }
    }
    return true;
}

void draw_room(int x, int y, std::vector<std::vector<char>> &_body) 
{
    for(int i = -1; i < 2; i++) {
        for(int i1 = -1; i1 < 2; i1++) {
            _body[x + i][y + i1] = 'R';
        }
    }
}

bool proof_way(int x, int y, int x1, int y1, int type, int width, int height, std::vector<std::vector<char>> &_body) {
    if(!type) {

        int i = x;
        int i1 = y;
        while(i != x1) {
            if((((abs(i - x) > 1 || abs(i1 - y) > 1) && (abs(i - x1) > 1 || abs(i1 - y1) > 1)) && _body[i][y] != ' ') || (((abs(i - x) > 2 || abs(i1 - y) > 2) && (abs(i - x1) > 2 || abs(i1 - y1) > 2)) && !small_search_around(i, y, width, height, _body))) {
                return false;
            }
            if(i <= x1) i++;
            else i--;
        }
        while(i1 != y1) {
            if((((abs(i - x) > 1 || abs(i1 - y) > 1) && (abs(i - x1) > 1 || abs(i1 - y1) > 1)) && _body[x1][i1] != ' ') || (((abs(i - x) > 2 || abs(i1 - y) > 2) && (abs(i - x1) > 2 || abs(i1 - y1) > 2)) && !small_search_around(x1, i1, width, height, _body))) {
                return false;
            }
            if(i1 < y1) i1++;
            else i1--;
        }

    } else {

        int i = x;
        int i1 = y;
        while(i1 != y1) {
            if((((abs(i - x) > 1 || abs(i1 - y) > 1) && (abs(i - x1) > 1 || abs(i1 - y1) > 1)) && _body[x][i1] != ' ') || (((abs(i - x) > 2 || abs(i1 - y) > 2) && (abs(i - x1) > 2 || abs(i1 - y1) > 2)) && !small_search_around(x, i1, width, height, _body))) {
                return false;
            }
            if(i1 < y1) i1++;
            else i1--;
        }
        while(i != x1) {
            if((((abs(i - x) > 1 || abs(i1 - y) > 1) && (abs(i - x1) > 1 || abs(i1 - y1) > 1)) && _body[i][y1] != ' ') || (((abs(i - x) > 2 || abs(i1 - y) > 2) && (abs(i - x1) > 2 || abs(i1 - y1) > 2)) && !small_search_around(i, y1, width, height, _body))) {
                return false;
            }
            if(i <= x1) i++;
            else i--;
        }

    }
    return true;
}
 
std::pair<int, int> make_the_way(int x, int y, int x1, int y1, int type, int width, int height, std::vector<std::vector<char>> &_body) {
    if (abs(x - x1) == 0) {
        type = 1; 
    }

    else if (abs(y - y1) == 0) {
        type = 0;
    }

    else if(abs(x - x1) <= 2 && abs(x - x1) != 0) {
        type = 1;
 
        int k = (y < y1) * 2 - 1;
        if(y + 3 * k >= 0 && y + 3 * k < 50 && small_search_around(x1, y + 3 * k, width, height, _body) && small_search_around(x, y + 3 * k,  width, height, _body) && proof_way(x, y, x1, y + 3 * k, type, width, height, _body)
                            && proof_way(x1, y + 3 * k, x1, y1, type, width, height, _body)){
            make_the_way(x, y, x, y + 3 * k, type, width, height, _body);
            make_the_way(x, y + 3 * k, x1, y + 3 * k, type, width, height, _body);
            make_the_way(x1, y + 3 * k, x1, y1, type, width, height, _body);
            
            if(y < y1) {
                return {2, 4};
            } else {
                return {4, 2};
            }
        } 
        return {0, 0};
 
    }

    else if(abs(y - y1) <= 2 && abs(y - y1) != 0) {
        type = 0;
        int k = (x < x1) * 2 - 1;
        if(x + 3 * k >= 0 && x + 3 * k < 50 && small_search_around(x + 3 * k, y1, width, height, _body) && small_search_around(x + 3 * k, y, width, height, _body) && proof_way(x, y, x + 3 * k, y1, type, width, height, _body)
                            && proof_way(x + 3 * k, y1, x1, y1, type, width, height, _body)){
            make_the_way(x, y, x + 3 * k, y, type,  width, height,_body);
            make_the_way(x + 3 * k, y, x + 3 * k, y1, type, width, height, _body);
            make_the_way(x + 3 * k, y1, x1, y1, type,  width, height,_body);
            
            if(x < x1) {
                return {3, 1};
            } else {
                return {1, 3};
            }
        } 
        return {0, 0};
    }
 
    if(!proof_way(x, y, x1, y1, type,  width, height, _body)) {
        return {0, 0};
    }

    int last = 0;
 
    if(type == 0) {

        int i = x;
        int i1 = y;
        while(i != x1) {
            if(_body[i][y] == ' ') {
                _body[i][y] = 'C';
            }
            if(i <= x1) {i++; last = 1;}
            else {i--; last = 3;};
        }
        if(_body[i][y] == ' '){
            _body[i][y] = 'C';
        }
        while(i1 != y1) {
            if(_body[x1][i1] == ' ') {
                _body[x1][i1] = 'C';
            }
            if(i1 < y1) {i1++; last = 4;}
            else {i1--, last = 2;};
        }
        if(_body[x1][i1] == ' ') {
            _body[x1][i1] = 'C';
        }

        if(x < x1) {
            return {3, last};
        } else {
            return {1, last};
        }
 
    } else {

        int i = x;
        int i1 = y;
        while(i1 != y1) {
            if(_body[x][i1] == ' ') {
                _body[x][i1] = 'C';
            }
            if(i1 < y1) {i1++; last = 4;}
            else {i1--; last = 2;}
        }
        if(_body[x][i1] == ' ') {
            _body[x][i1] = 'C';
        }
        while(i != x1) {
            if(_body[i][y1] == ' ') {
                _body[i][y1] = 'C';
            }
            if(i <= x1) {i++; last = 1;}
            else {i--; last = 3;}
        }
        if(_body[i][y1] == ' ') {
            _body[i][y1] = 'C';
        }

        if(y < y1) {
            return {2, last};
        } else {
            return {4, last};
        }
    }

}

int distance(std::pair<int, int> first, std::pair<int, int> second) {
    return abs(first.first - second.first) + abs(first.second - second.second);
}

template<typename T>
bool find(std::vector<std::shared_ptr<T>> &conection, std::shared_ptr<Room> f){
    for(auto &i:conection) {
        if(i != 0 && i -> x == f -> x && i -> y == f -> y) return true;
    }
    return false;
}

std::pair<int, int> normalised(std::pair<int, int> first) {
    first.first -= 1;
    first.second -= 1;
    return first;
}

Map AntohaFabric::Build(int width, int height) 
{
    Map map(width, height);
    for(int i = 0; i < width; i++) {
        for(int i1 = 0; i1 < height; i1++) {
            map._body[i][i1] = ' ';
        }
    }
    int actual_number_of_rooms = 24 + generator() % 10;
    std::vector<std::shared_ptr<Room>> chain;
    int quantity = 0;
    map._rooms.push_back(std::make_shared<Room>(25 + generator() % 3, 25 + generator() % 3, 3, 3));
    map._rooms.push_back(std::make_shared<Room>(22 + generator() % 8,  17 + generator() % 2, 3, 3));
    map._rooms.push_back(std::make_shared<Room>(22 + generator() % 8,  34 + generator() % 2, 3, 3));
    map._rooms.push_back(std::make_shared<Room>(17 + generator() % 2,  22 + generator() % 8, 3, 3));
    map._rooms.push_back(std::make_shared<Room>(34 + generator() % 2,  22 + generator() % 8, 3, 3));
    for(int i = 0; i < 5; i++) {
        draw_room(map._rooms[i]->x, map._rooms[i]->y, map._body);
    }

    for(int i = 1 ; i < map._rooms.size();i++) {
        if(i <= 2){
            std::pair<int, int> tip = make_the_way(map._rooms[0] -> x, map._rooms[0] -> y, map._rooms[i] -> x, map._rooms[i] -> y, 1,  width, height, map._body);
            if(tip != std::pair{0, 0}) {
                tip.first -= 1;
                tip.second -= 1;
                chain.push_back(map._rooms[i]);
                map._rooms[0] -> conection[tip.first] = map._rooms[i];
                map._rooms[i] -> conection[tip.second] = map._rooms[0];
            
                map._halls.push_back(std::make_shared<Hall>(map._rooms[0], map._rooms[i], 1, width, height, map._body)); 
                map._rooms[0] -> _hall_connection[tip.first] = map._halls[map._halls.size() - 1];
                map._rooms[i] -> _hall_connection[tip.second] = map._halls[map._halls.size() - 1];
                // std::cout<<map._rooms[0] -> x<<"  "<<map._rooms[0] -> y<<"   "<<map._rooms[i] -> x<<"  "<<map._rooms[i] -> y << "\n\n";
                // for(auto &ii : map._halls[0] -> rooms_in_hall) {
                //     std::cout<<ii -> x << " " << ii -> y << " " << ii -> conection[0] << " " << ii -> conection[1] << " " << ii -> conection[2] << " " << ii -> conection[3]<<"\n";
                // }
                // return map;

            }
        }
        else if(i > 2){
            std::pair<int, int> tip = make_the_way(map._rooms[0] -> x, map._rooms[0] -> y, map._rooms[i] -> x, map._rooms[i] -> y, 0,  width, height, map._body);
            if(tip != std::pair{0, 0}) {
                tip.first -= 1;
                tip.second -= 1;
                chain.push_back(map._rooms[i]);
                map._rooms[0] -> conection[tip.first] = map._rooms[i];
                map._rooms[i] -> conection[tip.second] = map._rooms[0];

                map._halls.push_back(std::make_shared<Hall>(map._rooms[0], map._rooms[i], 0, width, height, map._body)); 
                map._rooms[0] -> _hall_connection[tip.first] = map._halls[map._halls.size() - 1];
                map._rooms[i] -> _hall_connection[tip.second] = map._halls[map._halls.size() - 1];

                /*
                std::cout<<map._rooms[2] -> x<<"  "<<map._rooms[0] -> y<<"   "<<map._rooms[i] -> x<<"  "<<map._rooms[i] -> y << "\n\n";
                for(auto &ii : map._halls[2] -> rooms_in_hall) {
                    std::cout<<ii -> x << " " << ii -> y << " " << ii -> conection[0] << " " << ii -> conection[1] << " " << ii -> conection[2] << " " << ii -> conection[3]<<"\n";
                }
                return map;
                */
            }
        }
    }
    if(map._rooms[0] -> conection.size() == 4) {
        chain.erase(chain.begin());
    }

    quantity = 5;
    int f = 110;
    for(int i = 1; i < width - 1 && quantity < actual_number_of_rooms; i++) { 
        for(int i1 = 1; i1 < height - 1 && quantity < actual_number_of_rooms; i1++) {
            if(search_around(i, i1,  width, height, map._body)) {
                int proof = generator() % f;
                if(!proof) {
                    draw_room(i, i1, map._body);
                    map._rooms.push_back(std::make_shared<Room>(i, i1, 3, 3));
                  //  std::cout<<map._rooms[map._rooms.size() - 1] ->conection[0]<< " " << map._rooms[map._rooms.size() - 1] ->conection[1] << map._rooms[map._rooms.size() - 1] ->conection[2] << map._rooms[map._rooms.size() - 1] ->conection[3]<<"\n\n";
                    f = 110;
                    quantity += 1;
                }
                f--;
            }
        }
    }

    int siz = 3 + generator() % actual_number_of_rooms;
    
    while(siz--) {
        if(generator() % 5 != 0){

            std::shared_ptr<Room> index1, index2, index3;
            int number = -1;
            int min_distanse = width * height, min_distanse1 = width * height;
            for(int pos = 0; pos < chain.size(); pos++) {
                std::shared_ptr<Room> v = chain[pos];
                int min = width * height, min1 = width * height;
                std::shared_ptr<Room> neighbour = v, neighbour1 = v;
                for(int i = 0; i < map._rooms.size(); i++) {
                    if(map._rooms[i] != v && !find(map._rooms[i] -> conection, v)) {
                        int dlin = distance({map._rooms[i] -> x, map._rooms[i] -> y}, {v -> x, v -> y});
                        if(dlin < min) {
                            min1 = min;
                            neighbour1 = neighbour;
                            min = dlin;
                            neighbour = map._rooms[i];
                        } else if (dlin < min1) {
                            min1 = dlin;
                            neighbour1 = map._rooms[i];
                        }
                    }
                }
                if(number == -1 || min_distanse > min || (min_distanse == min && min_distanse1 < min1)) {
                    number = pos;
                    index1 = v;
                    index2 = neighbour;
                    index3 = neighbour1;
                    min_distanse = min;
                    min_distanse1 = min1;
                }
            }
            if(number != -1) {

                std::shared_ptr<Room> v = index1;
                std::shared_ptr<Room> neighbour = index2;
                std::shared_ptr<Room> neighbour1 = index3;
                int pos = number;
                bool change_here = false;

                if(v -> id > neighbour -> id) {
                    swap(v, neighbour);
                    change_here = true;
                }
                int gen = generator()%2;
                std::pair<int, int> f = make_the_way(v -> x, v -> y, neighbour -> x, neighbour -> y, gen, width, height, map._body);

                if (f != std::pair{0, 0}) {
                    f = normalised(f);
                    if(!find(chain, neighbour)) {
                        chain.push_back(neighbour);
                    }
                    v -> conection[f.first] = neighbour;
                    neighbour -> conection[f.second] = v;

                    map._halls.push_back(std::make_shared<Hall>(v, neighbour, gen, width, height, map._body)); 
                    v -> _hall_connection[f.first] = map._halls[map._halls.size() - 1];
                    neighbour -> _hall_connection[f.second] = map._halls[map._halls.size() - 1];

                    bool flag = true;
                    for(int i = 0; i < 4 && flag; i++) {
                        flag = (v -> conection[i] != nullptr);
                    }  
                    if(change_here) {
                        swap(v, neighbour);
                    }

                    if(flag) {
                        chain.erase(chain.begin() + pos);
                    }
                }
                if(f == std::pair{0, 0} || generator() % 2) {
                    change_here = false;
                    if(v -> id > neighbour1 -> id) {
                        swap(v, neighbour1);
                        change_here = true;
                    }

                    gen = generator() % 2;
                    f = make_the_way(v -> x, v -> y, neighbour1 -> x, neighbour1 -> y, gen, width, height, map._body);
                    if (f != std::pair{0, 0}) {
                        f = normalised(f);
                        if(!find(chain, neighbour1)) {
                            chain.push_back(neighbour1);
                        }
                        v -> conection[f.first] = neighbour1;
                        neighbour1 -> conection[f.second] = v;

                        map._halls.push_back(std::make_shared<Hall>(v, neighbour1, gen, width, height, map._body)); 
                        v -> _hall_connection[f.first] = map._halls[map._halls.size() - 1];
                        neighbour1 -> _hall_connection[f.second] = map._halls[map._halls.size() - 1];
                        
                        bool flag = true;
                        for(int i = 0; i < 4 && flag; i++) {
                            flag = (v -> conection[i] != nullptr);
                        }

                        if(flag) {
                            chain.erase(chain.begin() + pos);
                        }
                        
                        if(change_here) {
                            swap(v, neighbour1);
                        }

                    }
                }
            }

        } else {

            int pos = generator()%chain.size();
            std::shared_ptr<Room> v = chain[pos];
            int min = height * width, min1 = height * width;
            std::shared_ptr<Room> neighbour = v, neighbour1 = v;
            for(int i = 0; i < map._rooms.size(); i++) {
                if(map._rooms[i] != v && !find(map._rooms[i] -> conection, v)) {
                    int dlin = distance({map._rooms[i] -> x, map._rooms[i] -> y}, {v -> x, v -> y});
                    if(dlin < min) {
                        min1 = min;
                        neighbour1 = neighbour;
                        min = dlin;
                        neighbour = map._rooms[i];
                    } else if (dlin < min1) {
                        min1 = dlin;
                        neighbour1 = map._rooms[i];
                    }
                }
            }

            bool change_here = false;
            if ( v -> id > neighbour -> id) {
                swap(v, neighbour);
                change_here = true;
            }

            int gen = generator();
            std::pair<int, int> f = make_the_way(v -> x, v -> y, neighbour -> x, neighbour -> y, gen, width, height, map._body);
            if (f != std::pair{0, 0}) {
                f = normalised(f);
                if(!find(chain, neighbour)) {
                    chain.push_back(neighbour);
                }

                v -> conection[f.first] = neighbour;
                neighbour -> conection[f.second] = v;
            
                map._halls.push_back(std::make_shared<Hall>(v, neighbour, gen, width, height, map._body)); 
                v -> _hall_connection[f.first] = map._halls[map._halls.size() - 1];
                neighbour -> _hall_connection[f.second] = map._halls[map._halls.size() - 1];
                
                bool flag = true;
                for(int i = 0; i < 4 && flag; i++) {
                    flag = (v -> conection[i] != nullptr);
                }

                if(flag) {
                    chain.erase(chain.begin() + pos);
                }

                if(change_here){
                    swap(v, neighbour);
                }
            }
            if(f == std::pair{0, 0} ||  generator()%2) {
                change_here = false;
                if(v -> id > neighbour1 -> id) {
                    swap(v, neighbour1);
                    change_here = true;
                }
                gen = generator()%2;
                f = make_the_way(v -> x, v -> y, neighbour1 -> x, neighbour1 -> y, gen, width, height, map._body);
                if(f != std::pair{0, 0}) {
                    f = normalised(f);
                    if(!find(chain, neighbour1)){
                        chain.push_back(neighbour1);
                    }

                    v -> conection[f.first] = neighbour1;
                    neighbour1 -> conection[f.second] = v;
                    map._halls.push_back(std::make_shared<Hall>(v, neighbour1, gen, width, height, map._body)); 
                    v -> _hall_connection[f.first] = map._halls[map._halls.size() - 1];
                    neighbour1 -> _hall_connection[f.second] = map._halls[map._halls.size() - 1];
                    

                    bool flag = true;
                    for(int i = 0; i < 4 && flag; i++) {
                        flag = (v -> conection[i] != nullptr);
                    }

                    if(flag) {
                        chain.erase(chain.begin() + pos);
                    }

                    if(change_here){
                        swap(v, neighbour);
                    }
                }
            }
        }

    }

    int N = map._rooms.size();
    int i = 0;
    while (i < N) {
        int sizz = 0;
        for(int i1 = 0; i1 < 4 ; i1 ++) {
            if(map._rooms[i] -> conection[i1] == nullptr) {
                sizz += 1;
            }
        }
        if (sizz == 4) {
            clear_point(map._rooms[i] -> x, map._rooms[i] -> y, width, height, map._body);
            map._rooms.erase(map._rooms.begin() + i);
            i -= 2;
            N--;
        }
        i++;
    }

    return map;
}



