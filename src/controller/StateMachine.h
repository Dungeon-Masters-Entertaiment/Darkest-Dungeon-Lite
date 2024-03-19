//
// Created by Daniel Chiliaev on 19/03/2024.
//
#include "State.h"
#ifndef STATEMACHINE_H
#define STATEMACHINE_H
class FSM;

class StateMachine : public State {
protected:
  FSM *sub_machine;

public:
  void Update(FSM *fsm);
};

#endif // STATEMACHINE_H
