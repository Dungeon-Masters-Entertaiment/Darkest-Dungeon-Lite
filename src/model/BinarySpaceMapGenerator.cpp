#include "MapGenerator.h"
#include <cstdlib> // for rand()
#include <memory>

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

std::unique_ptr<BSP>& BSP::GetLeftChild() {
    return _left_child;
}

std::unique_ptr<BSP>& BSP::GetRightChild() {
    return _right_child;
}


