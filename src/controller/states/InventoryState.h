#ifndef INVENTORY_H
#define INVENTORY_H
#include "../State.h"
#include "../../../Inventory.h"
class State;
namespace states {

class InventoryState : public State {
  void Handle(FSM *fsm) override {};

  void Update(FSM *fsm) override {
    /*
    if((int) Keyboard::getInstance().get_key() == (int) KeyboardKey::ENTER) {
        if(Inventory::getInstance().getsizeItem() == )
    }
    */
  };

  void Render(FSM *fsm) override {};

  void OnEnter(FSM *fsm) override {};

  void OnExit(FSM *fsm) override {};
};
}

#endif // STATE_CITY_H