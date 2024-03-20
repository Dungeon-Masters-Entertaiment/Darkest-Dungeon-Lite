
#include "Game.h"
//#include "../model/Drawable/Player.h"
#include "FSM.h"

Game::Game() {

}

void Game::Start(){

    AntohaFabric generator;
    // Use the map instance to generate the map
    this->_map = std::make_unique<Map>(generator.Build(50, 50));
    FSMGame fsm;
    fsm.ChangeState(StateType::WalkingState);
    fsm.this_room = this ->_map -> _rooms[0];
    //fsm.ChangeState(StateType::WalkingState);
    Monitor start_monitor;
    start_monitor.divide_screen(fsm, * this->_map);
}