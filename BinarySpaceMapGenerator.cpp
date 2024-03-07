#include "MapGenerator.h"
#include "Map.h"
#include <cstdlib> // for rand()
#include <memory>

BSP BinarySpaceMapGenerator::Generate(int x, int y, int width, int height) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(1, 100);
    int random_seed = distribution(generator);

    BSP bsp(x, y, width, height, random_seed);
    bsp.Split();
    return bsp;
}

Map BinarySpaceMapGenerator::Build(int width, int height) {
    BSP bsp = Generate(0, 0, width, height);
    Map map(width, height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map._body[i][j] = ' ';  // Empty space
        }
    }

    std::vector<Room *> rooms;
    const int MIN_DISTANCE = 2;  // Set the minimum distance between rooms// Set the minimum distance between rooms

    std::function<void(BSP &)> CreateRooms = [&](BSP &node) {
        if (node._room) {
            bool tooClose = false;
            for (auto &room: rooms) {
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
                        map._body[i][j] = 'R';
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
            if (x >= 0 && x < width && midY1 >= 0 && midY1 < height && map._body[x][midY1] == ' ') {
                map._body[x][midY1] = 'C';  // Corridor
            }
        }

        // Create a vertical corridor from the end of the horizontal corridor to the second room
        for (int y = midY1; y != midY2; y += (midY2 > midY1 ? 1 : -1)) {
            if (midX2 >= 0 && midX2 < width && y >= 0 && y < height && map._body[midX2][y] == ' ') {
                map._body[midX2][y] = 'C';  // Corridor
            }
        }
    }
    return map;
}


void BSP::Split() {
    // Base case: if this node is already small enough, create a room
    if (_rect.width < 4 || _rect.height < 4) {
        return;
    }

    // Decide whether to split vertically or horizontally
    bool splitH = (rand() % 2 == 0);
    if (_rect.width > _rect.height && _rect.width / _rect.height >= 1.25)
        splitH = false;
    else if (_rect.height > _rect.width && _rect.height / _rect.width >= 1.25)
        splitH = true;

    // Determine the maximum size of the child nodes
    int max = (splitH ? _rect.height : _rect.width) - 5; // Subtract 5 to leave space for the room and corridor

    // If the area is too small to split, create a room
    if (max <= 3) {
        _room = std::make_unique<Room>(_rect.x + 1, _rect.y + 1, 3, 3); // Create a 3x3 room
        return;
    }

    // Determine where to split the node
    int split = rand() % max;

    // Create the child nodes
    if (splitH) {
        _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width, split + 5);
        _right_child = std::make_unique<BSP>(_rect.x, _rect.y + split + 5, _rect.width, _rect.height - split - 5);
    } else {
        _left_child = std::make_unique<BSP>(_rect.x, _rect.y, split + 5, _rect.height);
        _right_child = std::make_unique<BSP>(_rect.x + split + 5, _rect.y, _rect.width - split - 5, _rect.height);
    }

    // Recursively split the child nodes
    _left_child->Split();
    _right_child->Split();
}

void BSP::SplitHorizontally() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width, _rect.height / 2);
    _right_child = std::make_unique<BSP>(_rect.x, _rect.y + _rect.height / 2, _rect.width, _rect.height / 2);
}

void BSP::SplitVertically() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width / 2, _rect.height);
    _right_child = std::make_unique<BSP>(_rect.x + _rect.width / 2, _rect.y, _rect.width / 2, _rect.height);
}

std::unique_ptr<BSP> &BSP::GetLeftChild() {
    return _left_child;
}

std::unique_ptr<BSP> &BSP::GetRightChild() {
    return _right_child;
}


