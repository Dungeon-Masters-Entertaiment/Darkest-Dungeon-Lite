#include "Fight.h"

namespace states {

    void FightState::Handle(FSM *fsm) {
        // Этот метод можно использовать для обработки входящих событий
    }

    void FightState::Update(FSM *fsm) {
        KeyboardKey key = keyboard.get_key();
        
        if (key == KeyboardKey::ENTER) {
            heroidx++;
            if (heroidx >= event.Heroes.getCount()) {
                heroidx = 0; 
            }

            std::cout << event.Heroes.get_by_inx(heroidx)->getName() << std::endl;
        }
    }

    void FightState::OnExit(FSM *fsm) {
        // Метод для обработки действий при выходе из состояния, если таковые требуются
    }
} // namespace states
