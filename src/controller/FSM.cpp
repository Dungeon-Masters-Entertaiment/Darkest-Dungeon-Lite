//
// Created by Егор Кулин on 29.02.2024.

#include "FSM.h"
#include "states/Building.h"
#include "states/City.h"
#include "states/Fight.h"
#include "states/Loot.h"
#include "states/Map.h"
#include "states/Walking.h"

#include <memory>

FSMGame::FSMGame() {
  states[StateType::CityState] = new states::СityState();
  states[StateType::BuildingState] = new states::BuildingState();
  states[StateType::MapState] = new states::MapState();
  states[StateType::WalkingState] = new states::WalkingState();
  states[StateType::LootState] = new states::LootState();
  states[StateType::FightState] = new states::FightState();
  ChangeState(StateType::WalkingState);
}

void FSMGame::ChangeState(StateType state_type) {
  auto new_state = states[state_type];
  curr_state->OnExit(this);
  curr_state = new_state;
  curr_state->OnEnter(this);
}
void FSMGame::Update() { curr_state->Update(this); }
void FSMGame::Render() { curr_state->Render(this); }
void FSMGame::OnEnter() { curr_state->OnEnter(this); }
void FSMGame::OnExit() { curr_state->OnExit(this); }
