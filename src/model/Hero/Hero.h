#ifndef MYGAME_SRC_CLASSHERO_HERO_H_
#define MYGAME_SRC_CLASSHERO_HERO_H_

#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <nlohmann/json.hpp>
#include "model/Skills/CombatSkill.h"

using json = nlohmann::json;

class Hero {
 public:
  Hero() = default;
  Hero(std::vector<std::shared_ptr<CombatSkill>> combat_skills) : combat_skills(std::move(combat_skills)) {};

  std::vector<std::shared_ptr<CombatSkill>> combat_skills;

  friend void to_json(nlohmann::json &j, const Hero &hero) {
    j["combat_skills"] = json::array();
    for (const auto &skill : hero.combat_skills) {
      json skill_json;
      to_json(skill_json, *skill);
      j["combat_skills"].push_back(skill_json);
    }
  }

  friend void from_json(const nlohmann::json &j, Hero &hero) {
    const auto& combat_skills_json = j.at("combat_skills");
    for (auto it = combat_skills_json.begin(); it != combat_skills_json.end(); ++it) {  
      auto skill = std::make_shared<CombatSkill>();
      it.value().get_to(*skill);
      hero.combat_skills.push_back(skill);
    }
  }
  Hero(std::string name, int health, int damage)
        : name(name), health(health), damage(damage) {}

    // Метод для атаки другого персонажа
    void attack(Hero& target);

    // Метод для получения урона
    void takeDamage(int amount); 
    
    // Метод для лечения
    void heal(int amount);

    // Геттеры для атрибутов персонажа
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getDamage() const { return damage; }

private:
    std::string name; // Имя персонажа
    int health;       // Здоровье
    int damage;       // Урон

};

#endif //MYGAME_SRC_CLASSHERO_HERO_H_
