#ifndef COMBATSKILL_H
#define COMBATSKILL_H

#include "Skill.h"
#include <nlohmann/json.hpp>

class CombatSkill : public Skill {
 protected:
  bool is_crit_valid;
  bool generation_guaranteed;
  std::pair<int, int> move;

 public:
  CombatSkill();
  CombatSkill(std::string _id, SkillType _type, int _atk, std::pair<int, int> _dmg, int _crit, std::string _effect, int _launch, std::string _targets,
              bool _is_crit_valid, bool _generation_guaranteed, std::pair<int, int> _move);

  bool isCritValid() const;
  bool isGenerationGuaranteed() const;
  const std::pair<int, int>& getMove() const;

  // Методы сериализации и десериализации с использованием nlohmann::json
  nlohmann::json toJson() const;
  static CombatSkill fromJson(const nlohmann::json& json);

  NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(CombatSkill,
                                 id,
                                 atk,
                                 dmg,
                                 crit,
                                 launch,
                                 targets,
                                 is_crit_valid,
                                 generation_guaranteed,
                                 move)
};
#endif // COMBATSKILL_H

