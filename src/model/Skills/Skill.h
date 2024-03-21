//
// Created by Natalya Sklyar on 19.03.2024.
//

#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <utility>
#include <nlohmann/json.hpp>

enum class SkillType;

class Skill {
 protected:
  std::string id;
  SkillType type;
  int atk;
  std::pair<int, int> dmg;
  int crit;
  std::string effect;
  int launch;
  std::string targets;

 public:
  Skill();
  Skill(std::string _id, SkillType _type, int _atk, std::pair<int, int> _dmg, int _crit, std::string _effect, int _launch, std::string _targets);

  const std::string& getId() const;
  SkillType getType() const;
  int getAtk() const;
  const std::pair<int, int>& getDmg() const;
  int getCrit() const;
  const std::string& getEffect() const;
  int getLaunch() const;
  const std::string& getTargets() const;

  nlohmann::json toJson() const;
  static Skill fromJson(const nlohmann::json& json);

  NLOHMANN_DEFINE_TYPE_INTRUSIVE(Skill,
      id,
      atk,
      dmg,
      crit,
      launch,
      targets)
};

#endif // SKILL_H
