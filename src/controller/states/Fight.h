#include "controller/StateMachine.h"
#include "../State.h"
#include <iostream>
#include "../../model/Rooms/Events/EnemyEncounter.h"
#include "../../../keyboard.h"
#include "../../model/Creature/Monster.h"
#include "../FSM.h"
#include "AllieTurnState.h"
namespace states {

    class FightState : public FSM, public State {
    protected:
        Keyboard &keyboard = Keyboard::getInstance();
        int heroidx, enemyidx, skillidx;
        EnemyEncounter event;
        std::map<StateType, State *> states;
        std::vector <std::shared_ptr<Monster>> enemies;
    public:
        FightState(){
            heroidx = 0;
            enemyidx = 0;
        }

        virtual void ChangeState(StateType state_type) override {};

        virtual void Update() override {};

        virtual void Render() override {};

        virtual void OnEnter() override {
            this->states[StateType::AllieTurnState] = new states::AllieTurnState();
            states[StateType::FightState] = new states::FightState();
            enemies.clear();
            for (int i = 0; i < 3; i++){
                enemies.push_back(std::make_shared<Monster>());
            }
            std::cout << "Fight started" << std::endl;
        };

        virtual void OnExit() override {};

        virtual void Handle(FSM *fsm) override;

        virtual void Update(FSM *fsm) override;

        virtual void OnExit(FSM *fsm) override;

        virtual void Render(FSM *fsm) override {};

        virtual void OnEnter(FSM *fsm) override {};


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