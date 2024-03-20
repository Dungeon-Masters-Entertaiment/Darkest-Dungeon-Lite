
#include "Game.h"
#include "../model/Drawable/Player.h"
#include "FSM.h"
#include "../model/Rooms/Events/EnemyEncounter.h"

Game::Game() {
    AntohaFabric generator;
    // Use the map instance to generate the map
    this->_map = std::make_unique<Map>(generator.Build(50, 50));
    FSMGame fsm;
    fsm.this_room = this ->_map -> _rooms[0];
    fsm.ChangeState(StateType::WalkingState);
    EnemyEncounter Event;
    Event.triggerEvent();
    // Monitor start_monitor;
    // start_monitor.make_an_event_loop(fsm);
}

void Game::Start(){
    this->_map->Draw();
}