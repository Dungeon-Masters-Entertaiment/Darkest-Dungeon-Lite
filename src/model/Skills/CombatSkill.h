#ifndef DARKEST_DUNGEON_LITE_SKILL_H
#define DARKEST_DUNGEON_LITE_SKILL_H

#include <string>

enum class CombatSkillType {
    MELEE,
    RANGED,
    MOVE,
    NONE,
    TELEPORT
};

class CombatSkill {
public:
    // Name of the skill
    std::string _id;
    // Level of the skill
    int _level;
    // Type of the skill
    CombatSkillType _type;
    // Accuracy of the skill
    int _atk;
    // Damage of the skill in percentage of the base damage
    int _dmg;
    // Critical chance of the skill
    int _crit;
    //The ranks that the ability targets. If an '@' symbol precedes the numbers, this indicates that it targets friendly ranks.
    // If an '~' symbol precedes the numbers, this indicates that it targets all of the denoted ranks. If an '?' symbol precedes the numbers,
    // this indicates that it will randomly target one of the denoted ranks.
    std::string _targets;
    // The ranks that the ability can be used from.
    int _launch;
    //Is crit chance valid
    bool _is_crit_valid;
    //Is the skill guaranteed to be generated on the start of the battle
    bool _generation_guaranteed;
    //Move backwards and forwards
    std::pair<int, int> _move;
    // Chance to cause bleeding

public:
    // Use the skill
//    virtual void Use() = 0;
};

#endif //DARKEST_DUNGEON_LITE_SKILL_H