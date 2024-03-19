//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_FIGHT_H
#define STATE_FIGHT_H

#include "controller/StateMachine.h"
#include "../State.h"

class State;

class FSM;

class FightFSM : public FSM {
public:
    void ChangeState(StateType state_type) override {};

    void Update() override {};

    void Render() override {};

    void OnEnter() override {};

    void OnExit() override {};

    //void AddSubMachine(FSM *sub_machine) override;
};

namespace states {

    class FightState : public StateMachine {
    protected:
        FightFSM *sub_machine;
    public:
        FightState() {
            sub_machine = new FightFSM();
            sub_machine->OnEnter();
        }

        void Handle(FSM *fsm) override {};

        void Update(FSM *fsm) override {};

        void Render(FSM *fsm) override {};

        void OnEnter(FSM *fsm) override {};

        void OnExit(FSM *fsm) override {};
    };
} // namespace states
#endif // STATE_FIGHT_H
