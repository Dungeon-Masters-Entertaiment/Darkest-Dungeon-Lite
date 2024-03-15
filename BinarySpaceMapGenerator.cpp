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

void BSP::Split() {
    // Base case: if this node is already small enough, create a room
    if (_rect.width < 4 || _rect.height < 4) {
        return;
    }

    // Decide whether to split vertically or horizontally
    bool splitH = (generator() % 2 == 0);
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
    int split = (generator() + 1) % max;

    // Create the child nodes
    if (splitH) {
        _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width, split + 5, seed + 1);
        _right_child = std::make_unique<BSP>(_rect.x, _rect.y + split + 5, _rect.width, _rect.height - split - 5, seed + 1);
    } else {
        _left_child = std::make_unique<BSP>(_rect.x, _rect.y, split + 5, _rect.height, seed + 1);
        _right_child = std::make_unique<BSP>(_rect.x + split + 5, _rect.y, _rect.width - split - 5, _rect.height, seed + 1);
    }

    // Recursively split the child nodes
    _left_child->Split();
    _right_child->Split();
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

    std::function<void(BSP &)> CreateRooms = [&](BSP &node) {
        if (node._room) {
            // Add the room to the map
            for (int i = node._room->x; i < node._room->x + node._room->width; i++) {
                for (int j = node._room->y; j < node._room->y + node._room->height; j++) {
                    if (i >= 0 && i < width && j >= 0 && j < height) {
                        map._body[i][j] = 'R';  // Room
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
        int midX1 = room1->x + room1->width / 2;
        int midY1 = room1->y + room1->height / 2;
        int midX2 = room2->x + room2->width / 2;
        int midY2 = room2->y + room2->height / 2;

        // Generate a random number between 0 and 1
        std::default_random_engine generator;
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_direction = distribution(generator);

        // Create a corridor from the first room to the second
        if (random_direction < 0.5) {
            // First create a horizontal corridor, then a vertical corridor
            for (int x = std::min(midX1, midX2); x <= std::max(midX1, midX2); x++) {
                if (x >= 0 && x < width && midY1 >= 0 && midY1 < height && map._body[x][midY1] == ' ' && map._body[x][midY1 + 1] != 'C') {
                    map._body[x][midY1] = 'C';  // Corridor
                }
            }
            for (int y = std::min(midY1, midY2); y <= std::max(midY1, midY2); y++) {
                if (midX2 >= 0 && midX2 < width && y >= 0 && y < height && map._body[midX2][y] == ' ' && map._body[midX2 + 1][y] != 'C') {
                    map._body[midX2][y] = 'C';  // Corridor
                }
            }
        } else {
            // First create a vertical corridor, then a horizontal corridor
            for (int y = std::min(midY1, midY2); y <= std::max(midY1, midY2); y++) {
                if (midX1 >= 0 && midX1 < width && y >= 0 && y < height && map._body[midX1][y] == ' ' && map._body[midX1 + 1][y] != 'C') {
                    map._body[midX1][y] = 'C';  // Corridor
                }
            }
            for (int x = std::min(midX1, midX2); x <= std::max(midX1, midX2); x++) {
                if (x >= 0 && x < width && midY2 >= 0 && midY2 < height && map._body[x][midY2] == ' ' && map._body[x][midY2 + 1] != 'C') {
                    map._body[x][midY2] = 'C';  // Corridor
                }
            }
        }
    }
    return map;
}

void BSP::SplitHorizontally() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width, _rect.height / 2, this->seed);
    _right_child = std::make_unique<BSP>(_rect.x, _rect.y + _rect.height / 2, _rect.width, _rect.height / 2,
                                         this->seed);
}

void BSP::SplitVertically() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width / 2, _rect.height, this->seed);
    _right_child = std::make_unique<BSP>(_rect.x + _rect.width / 2, _rect.y, _rect.width / 2, _rect.height, this->seed);
}

std::unique_ptr<BSP> &BSP::GetLeftChild() {
    return _left_child;
}

std::unique_ptr<BSP> &BSP::GetRightChild() {
    return _right_child;
}


