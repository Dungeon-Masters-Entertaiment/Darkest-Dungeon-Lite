//
// Created by Daniel Chiliaev on 18/03/2024.
//

// #ifndef STATE_FIGHT_H
// #define STATE_FIGHT_H

#include "controller/StateMachine.h"
#include "../State.h"
#include <iostream>
#include "../../model/Rooms/Events/EnemyEncounter.h"
#include "../../../keyboard.h"


 namespace states {

    class FightState : public StateMachine {
    protected:
        Keyboard& keyboard = Keyboard::getInstance();
        int heroidx, enemyidx;
        EnemyEncounter event;
    public:
        FightState() {
            heroidx = 0;
            enemyidx = 0;
        }

         void Handle(FSM *fsm) override {};

         void Update(FSM *fsm) override {};
        void OnExit(FSM *fsm) override {};
    };
} // namespace states
#endif // STATE_FIGHT_H
