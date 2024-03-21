//
// Created by Natalya Sklyar on 19.03.2024.
//

#include "Skill.h"


Skill::Skill() = default;

Skill::Skill(std::string _id, SkillType _type, int _atk, std::pair<int, int> _dmg, int _crit, std::string _effect, int _launch, std::string _targets)
    : id(std::move(_id)), type(_type), atk(_atk), crit(_crit), launch(_launch), targets(std::move(_targets)) {}

const std::string& Skill::getId() const { return id; }
SkillType Skill::getType() const { return type; }
int Skill::getAtk() const { return atk; }
int Skill::getCrit() const { return crit; }
int Skill::getLaunch() const { return launch; }
const std::string& Skill::getTargets() const { return targets; }

nlohmann::json Skill::toJson() const {
  nlohmann::json j;
  j["id"] = id;
  j["type"] = static_cast<int>(type);
  j["atk"] = atk;
//  j["dmg"] = {dmg.first, dmg.second};
  j["crit"] = crit;
//  j["effect"] = effect;
  j["launch"] = launch;
  j["targets"] = targets;
  return j;
}

Skill Skill::fromJson(const nlohmann::json& json) {
  std::string _id = json["id"];
  SkillType _type = static_cast<SkillType>(json["type"]);
  int _atk = json["atk"];
  int _dmg_min = json["dmg"][0];
  int _dmg_max = json["dmg"][1];
  int _crit = json["crit"];
  std::string _effect = json["effect"];
  int _launch = json["launch"];
  std::string _targets = json["targets"];


  return Skill(_id,
                     _type,
                     _atk,
                     {_dmg_min, _dmg_max},
                     _crit,
                     _effect,
                     _launch,
                     _targets);
}