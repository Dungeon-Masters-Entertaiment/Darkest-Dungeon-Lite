//
// Created by Daniel Chiliaev on 19/03/2024.
//

#include "StateMachine.h"
#include "../controller/FSM.h"
void StateMachine::Update(FSM *fsm) {

  dynamic_cast<FSMGame*>(fsm) -> Update();
}