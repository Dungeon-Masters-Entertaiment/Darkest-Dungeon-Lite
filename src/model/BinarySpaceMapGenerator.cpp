#include "MapGenerator.h"
#include <cstdlib> // for rand()
#include <memory>

void BSP::Split() {
    if (_left_child || _right_child) {
        if (_left_child) _left_child->Split();
        if (_right_child) _right_child->Split();
    } else {
        // Decide to split horizontally or vertically
        if (_rect.width > _rect.height && _rect.width / _rect.height >= 1.25)
            SplitHorizontally();
        else if (_rect.height > _rect.width && _rect.height / _rect.width >= 1.25)
            SplitVertically();
        else if (rand() % 2 == 0)
            SplitHorizontally();
        else
            SplitVertically();

        // Create room in this node
        _room = std::make_unique<Room>(_rect.x + 1, _rect.y + 1, _rect.width - 2, _rect.height - 2);
    }
}

void BSP::SplitHorizontally() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width, _rect.height / 2);
    _right_child = std::make_unique<BSP>(_rect.x, _rect.y + _rect.height / 2, _rect.width, _rect.height / 2);
}

void BSP::SplitVertically() {
    _left_child = std::make_unique<BSP>(_rect.x, _rect.y, _rect.width / 2, _rect.height);
    _right_child = std::make_unique<BSP>(_rect.x + _rect.width / 2, _rect.y, _rect.width / 2, _rect.height);
}

