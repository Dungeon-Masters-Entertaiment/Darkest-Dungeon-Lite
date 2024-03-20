//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_BUILDING_H
#define STATE_BUILDING_H

#include "../State.h"

//class State;
namespace states {

class BuildingState : public State {
  void Handle(FSM *fsm) override {};

  void Update(FSM *fsm) override {};

  void Render(FSM *fsm) override {};

  void OnEnter(FSM *fsm) override {};

  void OnExit(FSM *fsm) override {};
};
};

#endif // STATE_BUILDING_H
