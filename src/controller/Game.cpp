
#include "Game.h"
#include "../model/Drawable/Player.h"
#include "../model/Drawable/Map.h"
Game::Game() {
    AntohaFabric generator;
    // Use the map instance to generate the map
    this->_map = std::make_unique<Map>(generator.Build(50, 50));
}

void Game::Start(){
    this->_map->Draw();
}