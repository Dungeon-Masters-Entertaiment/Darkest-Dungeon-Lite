//
// Created by Daniel Chiliaev on 18/03/2024.
//

#ifndef STATE_MAP_H
#define STATE_MAP_H
class State;
namespace states {

class MapState : public State {
  void Handle(FSM *fsm) override;

  void Update(FSM *fsm) override;

  void Render(FSM *fsm) override;

  void OnEnter(FSM *fsm) override;

  void OnExit(FSM *fsm) override;
};
} // namespace states
#endif // STATE_MAP_H
