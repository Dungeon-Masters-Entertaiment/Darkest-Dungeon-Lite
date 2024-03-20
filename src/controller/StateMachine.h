//
// Created by Daniel Chiliaev on 19/03/2024.
//

#ifndef STATEMACHINE_H
#define STATEMACHINE_H


#include "State.h"

//class FSM;

class StateMachine : public State {
protected:
  FSM *sub_machine;

public:
  void Update(FSM *fsm) override;
};

#endif // STATEMACHINE_H
