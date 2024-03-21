//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_LOOT_H
#define STATE_LOOT_H
#include <memory>
#include "../State.h"
#include "../../../Inventory.h"
#include "../../../keyboard.h"
#include "../../model/GameItems/Items.h"
#include "../../model/GameItems/РealingPotion.h"
class State;
namespace states {

class LootState : public State {
  void Handle(FSM *fsm) override {};

  void Update(FSM *fsm) override {
    if((int) Keyboard::getInstance().get_key() == (int) KeyboardKey::ENTER) {
      Inventory::getInstance().addItem(std::make_shared<PealingPotion>());
    }
  };

  void Render(FSM *fsm) override {};

  void OnEnter(FSM *fsm) override {};

  void OnExit(FSM *fsm) override {};
};
}
#endif //STATE_LOOT_H
