#include "Map.h"
#include <iostream>

void Map::GenerateMap(int width, int height) {
    BSP bsp(0, 0, width, height);
    bsp.Split();

    // Generate map using rooms in BSP tree
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            _body[i][j] = ' ';  // Empty space
        }
    }

    // Create rooms
    std::function<void(BSP &)> CreateRooms = [&](BSP &node) {
        if (node._room) {
            for (int i = node._room->x; i < node._room->x + node._room->width; i++) {
                for (int j = node._room->y; j < node._room->y + node._room->height; j++) {
                    _body[i][j] = 'R';  // Room
                }
            }
        }
        if (node.GetLeftChild()) CreateRooms(*node.GetLeftChild());
        if (node.GetRightChild()) CreateRooms(*node.GetRightChild());
    };
    CreateRooms(bsp);

    std::function<void(BSP &)> CreateCorridors = [&](BSP &node) {
        if (node.GetLeftChild() && node.GetRightChild()) {
            for (int i = node.GetLeftChild()->_room->x + node.GetLeftChild()->_room->width / 2;
                 i <= node.GetRightChild()->_room->x + node.GetRightChild()->_room->width / 2; i++) {
                _body[i][node.GetLeftChild()->_room->y + node.GetLeftChild()->_room->height / 2] = 'C';  // Corridor
            }
            for (int j = node.GetLeftChild()->_room->y + node.GetLeftChild()->_room->height / 2;
                 j <= node.GetRightChild()->_room->y + node.GetRightChild()->_room->height / 2; j++) {
                _body[node.GetLeftChild()->_room->x + node.GetLeftChild()->_room->width / 2][j] = 'C';  // Corridor
            }
        }
        if (node.GetLeftChild()) CreateCorridors(*node.GetLeftChild());
        if (node.GetRightChild()) CreateCorridors(*node.GetRightChild());
    };
    CreateCorridors(bsp);
}

void Map::Draw() {
    for (int i = 0; i < _body.size(); i++) {
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
    }
}