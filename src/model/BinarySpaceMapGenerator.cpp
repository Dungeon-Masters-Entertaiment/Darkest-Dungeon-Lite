
#include "MapGenerator.h"
#include <cstdlib> // for rand()

void BinarySpaceMapGenerator::GenerateMap() {
    // Start with a single room that covers the entire map
    CreateRoom(0, 0, 50, 50);

    // Divide the map into smaller rooms
    for (int i = 0; i < 10; i++) {
        // Choose a random room
        int x = rand() % 50;
        int y = rand() % 50;

        // Choose a random direction for the corridor
        int direction = rand() % 4;

        // Draw the corridor and divide the room
        switch (direction) {
            case 0: // Up
                CreateCorridor(x, y, 1, 3);
                CreateRoom(x, y + 3, 3, 3);
                break;
            case 1: // Down
                CreateCorridor(x, y, 1, 3);
                CreateRoom(x, y - 3, 3, 3);
                break;
            case 2: // Left
                CreateCorridor(x, y, 3, 1);
                CreateRoom(x + 3, y, 3, 3);
                break;
            case 3: // Right
                CreateCorridor(x, y, 3, 1);
                CreateRoom(x - 3, y, 3, 3);
                break;
        }
    }
    void GenerateMap() {
        Map& map = Map::GetInstance();
        // Use the map instance to generate the map
    }
}

void BinarySpaceMapGenerator::CreateRoom(int x, int y, int width, int height) {
    for (int i = x; i < x + width && i < 50; i++) {
        for (int j = y; j < y + height && j < 50; j++) {
            map[i][j] = 1;  // 1 represents a room
        }
    }
}

void BinarySpaceMapGenerator::CreateCorridor(int x, int y, int width, int height) {
    for (int i = x; i < x + width && i < 50; i++) {
        for (int j = y; j < y + height && j < 50; j++) {
            map[i][j] = 1;  // 1 represents a corridor
        }
    }
}