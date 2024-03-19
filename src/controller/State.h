#ifndef DARKEST_DUNGEON_LITE_STATE_H
#define DARKEST_DUNGEON_LITE_STATE_H


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


#endif //DARKEST_DUNGEON_LITE_STATE_H
