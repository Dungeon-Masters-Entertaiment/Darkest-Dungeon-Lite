//
// Created by Егор Кулин on 29.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_FSM_H
#define DARKEST_DUNGEON_LITE_FSM_H

#include "State.h"
class State;
class FSM {
public:
    virtual void ChangeState(State *new_state) = 0;

    virtual void Update() = 0;

    virtual void Render() = 0;

    virtual void OnEnter() = 0;

    virtual void OnExit() = 0;

    virtual void AddSubMachine(FSM* sub_machine) = 0;

    virtual ~FSM() = default;
};

class FSMGame : public FSM {
public:
    void ChangeState(State *new_state) override;

    void Update() override;

    void Render() override;

    void OnEnter() override;

    void OnExit() override;

    void AddSubMachine(FSM* sub_machine) override;
};

#endif //DARKEST_DUNGEON_LITE_FSM_H
