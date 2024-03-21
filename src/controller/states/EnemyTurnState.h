//
// Created by Егор Кулин on 21.03.2024.
//

#ifndef MYGAME_ENEMYTURNSTATE_H
#define MYGAME_ENEMYTURNSTATE_H

#endif //MYGAME_ENEMYTURNSTATE_H

#include "../State.h"

namespace states {
    class EnemyTurnState : public State {
        virtual void Handle(FSM *fsm) override {};

        virtual void Update(FSM *fsm) override {};

        virtual void Render(FSM *fsm) override {};

        virtual void OnEnter(FSM *fsm) override {};

        virtual void OnExit(FSM *fsm) override {};
    };
}
