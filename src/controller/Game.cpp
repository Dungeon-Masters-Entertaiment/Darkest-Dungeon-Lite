
#include "Game.h"
#include "../model/Drawable/Player.h"
#include "FSM.h"
#include "../model/Rooms/Events/EnemyEncounter.h"
Game::Game() {

}

void Game::Start() {
    AntohaFabric generator;
    // Use the map instance to generate the map
    this->_map = std::make_unique<Map>(generator.Build(50, 50));
    this->_squad = std::make_unique<Squad>();
    ParseHeroes();
    FSMGame fsm;
    fsm.ChangeState(StateType::WalkingState);
    fsm.this_room = this->_map->_rooms[0];
    //fsm.ChangeState(StateType::WalkingState);
    Monitor start_monitor;
    start_monitor.divide_screen(fsm, *this->_map);
}

void Game::ParseHeroes() {
    Hero hero;
    for (int i = 0; i < 3; i++) {
        /*std::string name;
        std::ifstream names("res/HeroJSONs/heroes_list.txt");
        names >> name;
        std::ifstream file("res/HeroJSONs/" + name + ".json");
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string json_string = buffer.str();
        json j = json::parse(json_string);
        from_json(j, hero);*/
        this->_squad->addHero(std::make_shared<Hero>(hero));
    }

}