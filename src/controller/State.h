#ifndef DARKEST_DUNGEON_LITE_STATE_H
#define DARKEST_DUNGEON_LITE_STATE_H

#include "FSM.h"

class FSM;

class State {
public:
    virtual void Handle(FSM *fsm) = 0;

    virtual void Update(FSM *fsm) = 0;

    virtual void Render(FSM *fsm) = 0;

    virtual void OnEnter(FSM *fsm) = 0;

    virtual void OnExit(FSM *fsm) = 0;

    virtual ~State() = default;
};

class StateGame : public State {
public:
    void Handle(FSM *fsm) override;

    void Update(FSM *fsm) override;

    void Render(FSM *fsm) override;

    void OnEnter(FSM *fsm) override;

    void OnExit(FSM *fsm) override;
};

#endif //DARKEST_DUNGEON_LITE_STATE_H
