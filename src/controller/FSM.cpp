//
// Created by Егор Кулин on 29.02.2024.
//

#include "FSM.h"

void FSMGame::ChangeState(State *new_state) {
    _current_state = new_state;
    _current_state->OnEnter(this);
}
