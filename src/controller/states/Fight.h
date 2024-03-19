//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_FIGHT_H
#define STATE_FIGHT_H

#include "controller/StateMachine.h"
#include "../State.h"

// need some wait before enemy attack.
// may be 


enum FightStateType {
    START,
    CHOOSEATTACK,
    ATTACK,
    ENEMYATTACK,
    VICTORY,
    DEFEAT
};


class State;

class FSM;

class FightFSM : public FSM, public State {
private:
    State* currentState;

public:
    FightFSM() : currentState(nullptr) {};

    void FightChangeState(FightStateType state_type) {};

    void Update() override {
        if (currentState != nullptr) {
            currentState->Update();
        }
    }

    void Render() override {
        if (currentState != nullptr) {
            currentState->Render();
        }
    }

    void OnEnter() override {
        FightChangeState(START);
    }

    void OnExit() override {
        if (currentState != nullptr) {
            currentState->OnExit();
            delete currentState;
            currentState = nullptr;
        }
    }

    // Определение и реализация конкретных состояний...
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
