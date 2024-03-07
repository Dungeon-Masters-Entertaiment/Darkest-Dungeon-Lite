#include "Map.h"
#include <iostream>


Map::Map() {
    _fabric = new BinarySpaceMapGenerator();
    _body.assign(50, std::vector<char>(50));
}

GenerationAlgorithm BinarySpaceMapGenerator::Generate() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

}

void Map::GenerateMap(int width, int height) {
    BSP bsp = BinarySpaceMapGenerator.Generate(0, 0, width, height);
    bsp.Split();

    // Generate map using rooms in BSP tree
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            _body[i][j] = ' ';  // Empty space
        }
    }

    std::vector<Room *> rooms;
    const int MIN_DISTANCE = 2;  // Set the minimum distance between rooms// Set the minimum distance between rooms

    std::function<void(BSP &)> CreateRooms = [&](BSP &node) {
        if (node._room) {
            bool tooClose = false;
            for (auto &room : rooms) {
                int dx = std::max(std::max(room->x - (node._room->x + 3), node._room->x - (room->x + 3)), 0);
                int dy = std::max(std::max(room->y - (node._room->y + 3), node._room->y - (room->y + 3)), 0);
                if (sqrt(dx * dx + dy * dy) < MIN_DISTANCE) {
                    tooClose = true;
                    break;
                }
            }
            if (tooClose) return;

            for (int i = node._room->x; i < node._room->x + 3; i++) {
                for (int j = node._room->y; j < node._room->y + 3; j++) {
                    if (i >= 0 && i < width - 2 && j >= 0 && j < height - 2 && _body[i][j] != 'R') {
                        _body[i][j] = 'R';
                    }
                }
            }
            rooms.push_back(node._room.get());
        }
        if (node.GetLeftChild()) CreateRooms(*node.GetLeftChild());
        if (node.GetRightChild()) CreateRooms(*node.GetRightChild());
    };
    CreateRooms(bsp);

    // Create corridors between adjacent rooms only
    for (int i = 0; i < rooms.size() - 1; i++) {
        Room *room1 = rooms[i];
        Room *room2 = rooms[i + 1];

        // Calculate the midpoints of the rooms
        int midX1 = room1->x + 1;
        int midY1 = room1->y + 1;
        int midX2 = room2->x + 1;
        int midY2 = room2->y + 1;

        // Create a horizontal corridor from the first room to the second
        for (int x = midX1; x != midX2; x += (midX2 > midX1 ? 1 : -1)) {
            if (x >= 0 && x < width && midY1 >= 0 && midY1 < height && _body[x][midY1] == ' ') {
                _body[x][midY1] = 'C';  // Corridor
            }
        }

        // Create a vertical corridor from the end of the horizontal corridor to the second room
        for (int y = midY1; y != midY2; y += (midY2 > midY1 ? 1 : -1)) {
            if (midX2 >= 0 && midX2 < width && y >= 0 && y < height && _body[midX2][y] == ' ') {
                _body[midX2][y] = 'C';  // Corridor
            }
        }
    }
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