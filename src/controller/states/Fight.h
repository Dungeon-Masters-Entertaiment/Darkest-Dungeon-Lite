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

        void Handle(FSM *fsm) ;

        void Update(FSM *fsm) ;
        
        void OnExit(FSM *fsm) ;
    };
} 