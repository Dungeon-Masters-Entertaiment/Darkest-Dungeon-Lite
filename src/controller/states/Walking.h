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
        bool update_position(int type, FSM *fsm, int direction) {
            if ((int) Keyboard::getInstance().get_key() == (type)) {   
                FSMGame *fsm1 = dynamic_cast<FSMGame *>(fsm);
                if(std::dynamic_pointer_cast<Room>(fsm1->this_room) != nullptr) {
                auto current_room = std::dynamic_pointer_cast<Room>(fsm1->this_room);
                if (current_room->_hall_connection[direction] != nullptr) {
                    if(current_room->id < current_room->_hall_connection[direction] ->exit ->id) {
                        fsm1 ->this_room = current_room->_hall_connection[direction] ->rooms_in_hall[0];
                        return true;
                    } else {
                        fsm1 -> this_room = current_room->_hall_connection[direction] ->rooms_in_hall[current_room->_hall_connection[direction] ->rooms_in_hall.size() -1];
                        return true; 
                    }
                }
                } else {
                    if (fsm1->this_room->conection[direction] != nullptr) {
                        fsm1->this_room = std::dynamic_pointer_cast<Cell>(fsm1->this_room->conection[direction]);
                        return true;
                    }
                } 
            }
            return false;
        }

        void Handle(FSM *fsm) override {

        };

        void Update(FSM *fsm) override {
            bool f = false;
            f = std::max(f, update_position((int) KeyboardKey::a, fsm, 0));
            f = std::max(f, update_position((int) KeyboardKey::d, fsm, 2));
            f = std::max(f, update_position((int) KeyboardKey::s, fsm, 1));
            f = std::max(f, update_position((int) KeyboardKey::w, fsm, 3));
            if(f){
                FSMGame *fsm1 = dynamic_cast<FSMGame *>(fsm);
                auto current_room = std::dynamic_pointer_cast<Room>(fsm1->this_room);
                for(int i = 0; i < current_room -> events.size(); i++) {
                    if(current_room -> events[i] ->getDescription() == "BossFight") {

                    }
                    if(current_room -> events[i] ->getDescription() == "EnemyEncounter") {

                    }
                    if(current_room -> events[i] ->getDescription() == "Treasure") {

                    }
                }
            }
        };

        void Render(FSM *fsm) override {};

        void OnEnter(FSM *fsm) override {};

        void OnExit(FSM *fsm) override {};
    };
} // namespace states
#endif // STATE_WALKING_H
