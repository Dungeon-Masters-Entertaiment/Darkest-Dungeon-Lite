//
// Created by Егор Кулин on 29.02.2024.
//

#ifndef DARKEST_DUNGEON_LITE_FSM_H
#define DARKEST_DUNGEON_LITE_FSM_H

#include "State.h"
#include <map>
//#include "../model/Drawable/Map.h"
#include "model/Rooms/Cell.h"

enum class StateType {
  CityState,
  BuildingState,
  MapState,
  WalkingState,
  LootState,
  FightState
};

class FSM {
public:
  virtual void ChangeState(StateType state_type) = 0;

  virtual void Update() = 0;

  virtual void Render() = 0;

  virtual void OnEnter() = 0;

  virtual void OnExit() = 0;

  //virtual void AddSubMachine(FSM *sub_machine) = 0;

  virtual ~FSM() = default;
};

class FSMGame : public FSM {
protected:
  State *curr_state = nullptr;
  std::map<StateType, State *> states;
  friend class Game;

public:
  std::shared_ptr<Cell> this_room = nullptr;
  FSMGame();

  void ChangeState(StateType state_type) override;

  void Update() override;

  void Render() override;

  void OnEnter() override;

  void OnExit() override;
};

#endif // DARKEST_DUNGEON_LITE_FSM_H
