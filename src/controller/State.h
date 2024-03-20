#ifndef DARKEST_DUNGEON_LITE_STATE_H
#define DARKEST_DUNGEON_LITE_STATE_H
#include "../../keyboard.h"

#include "FSM.h"
class FSM;


class State {
public:

    State() = default;
    virtual void Handle(FSM *fsm) = 0;

    virtual void Update(FSM *fsm) = 0;

    virtual void Render(FSM *fsm) = 0;

    virtual void OnEnter(FSM *fsm) = 0;

    virtual void OnExit(FSM *fsm) = 0;
};


#endif //DARKEST_DUNGEON_LITE_STATE_H
