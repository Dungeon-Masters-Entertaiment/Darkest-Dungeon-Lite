//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_WALKING_H
#define STATE_WALKING_H
//#include "../keyboard.h"
#include "../State.h"
#include "../../model/Rooms/Room.h"
#include "../../model/Rooms/Hall.h"

class State;
namespace states {
    class WalkingState : public State {
    public:
        void update_position(int type, FSM *fsm, int direction) {
            if ((int) Keyboard::getInstance().get_key() == (type)) {
                FSMGame *fsm1 = dynamic_cast<FSMGame *>(fsm);
                auto current_room_real_pointer = fsm1->this_room.get();
                if (typeid(*current_room_real_pointer) == typeid(Room)) {
                    auto current_room = std::dynamic_pointer_cast<Room>(fsm1->this_room);
                    if (current_room->_hall_connection[direction] != nullptr) {
                        auto next_room = std::dynamic_pointer_cast<Room>(current_room->conection[direction]);
                        std::shared_ptr<Cell> first_corridor_cell = nullptr;
                        if (current_room->id < next_room->id) {
                            first_corridor_cell = std::dynamic_pointer_cast<Cell>(
                                    current_room->_hall_connection[direction]->entrance);
                        } else {
                            first_corridor_cell = std::dynamic_pointer_cast<Cell>(
                                    current_room->_hall_connection[direction]->exit);
                        }
                        fsm1->this_room = first_corridor_cell;
                        std::cout << typeid(*fsm1->this_room).name() << std::endl;
                    }
                } else {
                    auto current_corridor_cell = fsm1->this_room;
                    if (fsm1->this_room->conection[direction] != nullptr) {
                        fsm1->this_room = std::dynamic_pointer_cast<Cell>(fsm1->this_room->conection[direction]);
                    }
                }
            }
        }

        void Handle(FSM *fsm) override {

        };

        void Update(FSM *fsm) override {
            update_position((int) KeyboardKey::a, fsm, 0);
            update_position((int) KeyboardKey::d, fsm, 2);
            update_position((int) KeyboardKey::s, fsm, 1);
            update_position((int) KeyboardKey::w, fsm, 3);
        };

        void Render(FSM *fsm) override {};

        void OnEnter(FSM *fsm) override {

        };

        void OnExit(FSM *fsm) override {
        };
    };
} // namespace states
#endif // STATE_WALKING_H
