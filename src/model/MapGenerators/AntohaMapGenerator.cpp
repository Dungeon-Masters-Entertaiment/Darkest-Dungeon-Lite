#include "MapFabric.h"
#include <iostream>
#include "../Drawable/Map.h"

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
    for (int i = -3; i <= 3; i++) {
        for(int i1 = -3; i1 <= 3; i1++) {
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
 
bool make_the_way(int x, int y, int x1, int y1, int type, int width, int height, std::vector<std::vector<char>> &_body) {
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
            return true;
        } 
        return false;
 
    }

    else if(abs(y - y1) <= 2 && abs(y - y1) != 0) {
        type = 0;
        int k = (x < x1) * 2 - 1;
        if(x + 3 * k >= 0 && x + 3 * k < 50 && small_search_around(x + 3 * k, y1, width, height, _body) && small_search_around(x + 3 * k, y, width, height, _body) && proof_way(x, y, x + 3 * k, y1, type, width, height, _body)
                            && proof_way(x + 3 * k, y1, x1, y1, type, width, height, _body)){
            make_the_way(x, y, x + 3 * k, y, type,  width, height,_body);
            make_the_way(x + 3 * k, y, x + 3 * k, y1, type, width, height, _body);
            make_the_way(x + 3 * k, y1, x1, y1, type,  width, height,_body);
            return true;
        } 
        return false;
    }
 
    if(!proof_way(x, y, x1, y1, type,  width, height, _body)) {
        return false;
    }
 
    if(type == 0) {

        int i = x;
        int i1 = y;
        while(i != x1) {
            if(_body[i][y] == ' ') {
                _body[i][y] = 'C';
            }
            if(i <= x1) i++;
            else i--;
        }
        if(_body[i][y] == ' '){
            _body[i][y] = 'C';
        }
        while(i1 != y1) {
            if(_body[x1][i1] == ' ') {
                _body[x1][i1] = 'C';
            }
            if(i1 < y1) i1++;
            else i1--;
        }
        if(_body[x1][i1] == ' ') {
            _body[x1][i1] = 'C';
        }
 
    } else {

        int i = x;
        int i1 = y;
        while(i1 != y1) {
            if(_body[x][i1] == ' ') {
                _body[x][i1] = 'C';
            }
            if(i1 < y1) i1++;
            else i1--;
        }
        if(_body[x][i1] == ' ') {
            _body[x][i1] = 'C';
        }
        while(i != x1) {
            if(_body[i][y1] == ' ') {
                _body[i][y1] = 'C';
            }
            if(i <= x1) i++;
            else i--;
        }
        if(_body[i][y1] == ' ') {
            _body[i][y1] = 'C';
        }
    }
    return true;

}

int distance(std::pair<int, int> first, std::pair<int, int> second) {
    return abs(first.first - second.first) + abs(first.second - second.second);
}

bool find(std::vector<std::shared_ptr<Cell>> &conection, std::shared_ptr<Cell> f){
    for(auto &i:conection) {
        if(i == f) return true;
    }
    return false;
}

Map AntohaFabric::Build(int width, int height) 
{
    Map map(width, height);
    for(int i = 0; i < width; i++) {
        for(int i1 = 0; i1 < height; i1++) {
            map._body[i][i1] = ' ';
        }
    }
    int actual_number_of_rooms = 20 + generator() % 10;
    std::vector<std::shared_ptr<Cell>> chain;
    int quantity = 0;
    map._rooms.push_back(std::make_shared<Cell>(25 + generator() % 3, 25 + generator() % 3, 3, 3));
    map._rooms.push_back(std::make_shared<Cell>(22 + generator() % 8,  17 + generator() % 2, 3, 3));
    map._rooms.push_back(std::make_shared<Cell>(22 + generator() % 8,  34 + generator() % 2, 3, 3));
    map._rooms.push_back(std::make_shared<Cell>(17 + generator() % 2,  22 + generator() % 8, 3, 3));
    map._rooms.push_back(std::make_shared<Cell>(34 + generator() % 2,  22 + generator() % 8, 3, 3));
    for(int i = 0; i < 5; i++) {
        draw_room(map._rooms[i]->x, map._rooms[i]->y, map._body);
    }

    for(int i = 1 ; i < map._rooms.size();i++) {
        if(i<=2 && make_the_way(map._rooms[0] -> x, map._rooms[0] -> y, map._rooms[i] -> x, map._rooms[i] -> y, 1,  width, height, map._body)){
            chain.push_back(map._rooms[i]);
            map._rooms[i] -> conection.push_back(map._rooms[0]);
            map._rooms[0] -> conection.push_back(map._rooms[i]);
        }
        else if(i > 2 &&  make_the_way(map._rooms[0] -> x, map._rooms[0] -> y, map._rooms[i] -> x, map._rooms[i] -> y, 0,  width, height, map._body)){
            chain.push_back(map._rooms[i]);
            map._rooms[i] -> conection.push_back(map._rooms[0]);
            map._rooms[0] -> conection.push_back(map._rooms[i]);
        }
    }

    if(map._rooms[0] -> conection.size() == 4) {
        chain.erase(chain.begin());
    }

    quantity = 5;
    int f = 100;
    for(int i = 1; i < width - 1 && quantity < actual_number_of_rooms; i++) { 
        for(int i1 = 1; i1 < height - 1 && quantity < actual_number_of_rooms; i1++) {
            if(search_around(i, i1,  width, height, map._body)) {
                int proof = generator() % f;
                if(!proof) {
                    draw_room(i, i1, map._body);
                    map._rooms.push_back(std::make_shared<Cell>(i, i1, 3, 3));
                    f = 120;
                    quantity += 1;
                }
                f--;
            }
        }
    }

    int siz = 3 + generator() % actual_number_of_rooms;
    while(siz--) {
        if(generator() % 5 != 0){

            std::shared_ptr<Cell> index1, index2, index3;
            int number = -1;
            int min_distanse = width * height, min_distanse1 = width * height;
            for(int pos = 0; pos < chain.size(); pos++) {
                std::shared_ptr<Cell> v = chain[pos];
                int min = width * height, min1 = width * height;
                std::shared_ptr<Cell> neighbour = v, neighbour1 = v;
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

                std::shared_ptr<Cell> v = index1;
                std::shared_ptr<Cell> neighbour = index2;
                std::shared_ptr<Cell> neighbour1 = index3;
                int pos = number;

                bool f = make_the_way(v -> x, v -> y, neighbour -> x, neighbour -> y, generator()%2, width, height, map._body);
                if (f) {
                    if(!find(chain, neighbour)){
                        chain.push_back(neighbour);
                    }
                    neighbour -> conection.push_back(v);
                    v -> conection.push_back(neighbour);
                    if(v -> conection.size() == 4) {
                        chain.erase(chain.begin() + pos);
                    }
                }
                if(!f || generator()%2) {
                    if (make_the_way(v -> x, v -> y, neighbour1 -> x, neighbour1 -> y, generator()%2, width, height, map._body)) {
                        if(!find(chain, neighbour1)){
                            chain.push_back(neighbour1);
                        }
                        neighbour1 -> conection.push_back(v);
                        v -> conection.push_back(neighbour1);
                        if(v -> conection.size() == 4) {
                            chain.erase(chain.begin() + pos);
                        }
                    }
                }
            }

        } else {

            int pos = generator()%chain.size();
            std::shared_ptr<Cell> v = chain[pos];
            int min = height * width, min1 = height * width;
            std::shared_ptr<Cell> neighbour = v, neighbour1 = v;
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
            bool f = make_the_way(v -> x, v -> y, neighbour -> x, neighbour -> y, generator()%2, width, height, map._body);
            if (f) {
                if(!find(chain, neighbour)){
                    chain.push_back(neighbour);
                }
                neighbour -> conection.push_back(v);
                v -> conection.push_back(neighbour);
                if(v -> conection.size() == 4) {
                    chain.erase(chain.begin() + pos);
                }
            }
            if(!f ||  generator()%2) {
                if(make_the_way(v -> x, v -> y, neighbour1 -> x, neighbour1 -> y, generator()%2, width, height, map._body)) {
                    if(!find(chain, neighbour1)){
                        chain.push_back(neighbour1);
                    }
                    neighbour1 -> conection.push_back(v);
                    v -> conection.push_back(neighbour1);
                    if(v -> conection.size() == 4) {
                        chain.erase(chain.begin() + pos);
                    }
                }
            }
        }

    }
    
    for (int i = 0; i < map._rooms.size(); i++) {
        if (map._rooms[i] -> conection.size() == 0) {
            clear_point(map._rooms[i] -> x, map._rooms[i] -> y, width, height, map._body);
        }
    }
    return map;
}