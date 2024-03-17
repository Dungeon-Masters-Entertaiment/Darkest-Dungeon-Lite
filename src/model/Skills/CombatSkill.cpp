//
// Created by Егор Кулин on 29.02.2024.
//

#include "CombatSkill.h"

#include <glog/logging.h>

#include <utility>

CombatSkill::CombatSkill(std::string _id, int _level)
    : _id(std::move(_id)), _level(_level), _type(), _atk(0), _dmg(0), _crit(0),
      _launch(0), _is_crit_valid(false), _generation_guaranteed(false){

}

