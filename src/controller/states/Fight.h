#include "controller/StateMachine.h"
#include "../State.h"
#include <iostream>
#include "../../model/Rooms/Events/EnemyEncounter.h"
#include "../../../keyboard.h"


 namespace states {

    class FightState : public StateMachine {
    protected:
        Keyboard& keyboard = Keyboard::getInstance();
        int heroidx, enemyidx, skillidx;
        EnemyEncounter event;
    public:
        FightState() {
            heroidx = 0;
            enemyidx = 0;
        }

        void Handle(FSM *fsm) ;

        void Update(FSM *fsm) ;
        
        void OnExit(FSM *fsm) ;

        // Getters 
        int getHero() { return heroidx; }
        int gerEnemy() { return enemyidx; }
        int getSkill() { return skillidx; }
    };
} 


// heroidx - random() 
// state: choose skills 
// -> state: choose enemy
// punch 
// await(100)
// enemy punch 

// heroidx - random()

// squad.getCount == 0

// Origin FSM -> fight fsm
// uddate() every tick 
// GUI -> Fight.getEnemy 