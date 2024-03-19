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


