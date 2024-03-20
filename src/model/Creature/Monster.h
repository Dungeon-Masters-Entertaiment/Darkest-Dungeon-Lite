//
// Created by Natalya Sklyar on 20.03.2024.
//

#ifndef MYGAME_SRC_MODEL_CREATURE_MONSTER_H_
#define MYGAME_SRC_MODEL_CREATURE_MONSTER_H_

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <nlohmann/json.hpp>
#include "model/Skills/Skill.h"

using json = nlohmann::json;

class Monster {
 public:
  Monster() = default;
  Monster(std::vector<std::shared_ptr<Skill>> skills) : skills(std::move(skills)) {};

  std::vector<std::shared_ptr<Skill>> skills;

  friend void to_json(nlohmann::json &j, const Monster &monster) {
    j["skills"] = json::array();
    for (const auto &skill : monster.skills) {
      json skill_json;
      to_json(skill_json, *skill);
      j["skills"].push_back(skill_json);
    }
  }

  friend void from_json(const nlohmann::json &j, Monster &monster) {
    const auto& skills_json = j.at("skills");
    for (auto it = skills_json.begin(); it != skills_json.end(); ++it) {
      auto skill = std::make_shared<Skill>();
      it.value().get_to(*skill);
      monster.skills.push_back(skill);
    }
  }

};

#endif //MYGAME_SRC_MODEL_CREATURE_MONSTER_H_
