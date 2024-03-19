//
// Created by Егор Кулин on 29.02.2024.
//

#include "CombatSkill.h"
#include <glog/logging.h>
#include <utility>


CombatSkill::CombatSkill() = default;

CombatSkill::CombatSkill(std::string _id, SkillType _type, int _atk, std::pair<int, int> _dmg, int _crit, std::string _effect, int _launch, std::string _targets,
                         bool _is_crit_valid, bool _generation_guaranteed, std::pair<int, int> _move)
    : Skill(std::move(_id), _type, _atk, _dmg, _crit, std::move(_effect), _launch, std::move(_targets)),
      is_crit_valid(_is_crit_valid), generation_guaranteed(_generation_guaranteed), move(_move) {}

bool CombatSkill::isCritValid() const { return is_crit_valid; }
bool CombatSkill::isGenerationGuaranteed() const { return generation_guaranteed; }
const std::pair<int, int>& CombatSkill::getMove() const { return move; }

nlohmann::json CombatSkill::toJson() const {
  nlohmann::json j;
  j["id"] = id;
  j["type"] = static_cast<int>(type);
  j["atk"] = atk;
  j["dmg"] = {dmg.first, dmg.second};
  j["crit"] = crit;
  j["effect"] = effect;
  j["launch"] = launch;
  j["targets"] = targets;
  j["is_crit_valid"] = is_crit_valid;
  j["generation_guaranteed"] = generation_guaranteed;
  j["move"] = {move.first, move.second};
  return j;
}

CombatSkill CombatSkill::fromJson(const nlohmann::json& json) {
  std::string _id = json["id"];
  SkillType _type = static_cast<SkillType>(json["type"]);
  int _atk = json["atk"];
  int _dmg_min = json["dmg"][0];
  int _dmg_max = json["dmg"][1];
  int _crit = json["crit"];
  std::string _effect = json["effect"];
  int _launch = json["launch"];
  std::string _targets = json["targets"];
  bool _is_crit_valid = json["is_crit_valid"];
  bool _generation_guaranteed = json["generation_guaranteed"];
  int _move_x = json["move"][0];
  int _move_y = json["move"][1];

  return CombatSkill(_id, _type, _atk, {_dmg_min, _dmg_max}, _crit, _effect, _launch, _targets, _is_crit_valid, _generation_guaranteed, {_move_x, _move_y});
}


