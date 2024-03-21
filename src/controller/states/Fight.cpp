#include "Fight.h"

namespace states {

    void FightState::Handle(FSM *fsm) {
        // Этот метод можно использовать для обработки входящих событий
    }

    void FightState::Update(FSM *fsm) {
        KeyboardKey key = keyboard.get_key();
        auto fsm_game = dynamic_cast<FSMGame*>(fsm);
        if (key == KeyboardKey::ENTER) {
            fsm->ChangeState(StateType::WalkingState);
        }
    }

    void FightState::OnExit(FSM *fsm) {
        // Метод для обработки действий при выходе из состояния, если таковые требуются
    }
} // namespace states
