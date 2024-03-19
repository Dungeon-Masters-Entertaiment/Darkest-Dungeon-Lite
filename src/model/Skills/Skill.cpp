//
// Created by Natalya Sklyar on 19.03.2024.
//

#include "Skill.h"

Skill::Skill() = default;

Skill::Skill(std::string _id, SkillType _type, int _atk, std::pair<int, int> _dmg, int _crit, std::string _effect, int _launch, std::string _targets)
    : id(std::move(_id)), type(_type), atk(_atk), dmg(_dmg), crit(_crit), effect(std::move(_effect)), launch(_launch), targets(std::move(_targets)) {}

const std::string& Skill::getId() const { return id; }
SkillType Skill::getType() const { return type; }
int Skill::getAtk() const { return atk; }
const std::pair<int, int>& Skill::getDmg() const { return dmg; }
int Skill::getCrit() const { return crit; }
const std::string& Skill::getEffect() const { return effect; }
int Skill::getLaunch() const { return launch; }
const std::string& Skill::getTargets() const { return targets; }

