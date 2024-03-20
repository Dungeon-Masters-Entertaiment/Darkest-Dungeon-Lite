#include "Fight.h"

namespace states {

    void FightState::Handle(FSM *fsm) {
        // Этот метод можно использовать для обработки входящих событий
    }

    void FightState::Update(FSM *fsm) {
        KeyboardKey key = keyboard.get_key();
        
        // Проверяем, была ли нажата клавиша ENTER
        if (key == KeyboardKey::ENTER) {
            // Изменяем индекс героя
            heroidx++;
            // Проверяем, чтобы индекс не вышел за пределы вектора heroes
            if (heroidx >= event.Heroes.size()) {
                heroidx = 0; // Возвращаемся к началу списка, если достигли конца
            }

            // Выводим имя героя через std::cout
            std::cout << event.Heroes[heroidx].getName() << std::endl;
        }
    }

    void FightState::OnExit(FSM *fsm) {
        // Метод для обработки действий при выходе из состояния, если таковые требуются
    }
} // namespace states
