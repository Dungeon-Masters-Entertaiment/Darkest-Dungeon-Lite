#ifndef DARKEST_DUNGEON_LITE_SKILL_H
#define DARKEST_DUNGEON_LITE_SKILL_H

class Skill {
protected:
    // Damage dealt by the skill
    int _damage;
    // Accuracy of the skill
    int _accuracy;
    // Chance of a critical hit
    int _critChance;
    // Multiplier for critical hit damage
    int _critMultiplier;
    // Chance to stun the target
    int _stunChance;
    // Chance to cause bleeding
    int _bleedChance;
    // Chance to cause blight
    int _blightChance;
    // Chance to debuff the target
    int _debuffChance;
    // Chance to buff the user
    int _buffChance;
    // Amount of health restored
    int _heal;
    // Amount of stress healed
    int _stressHeal;
    // Amount of stress inflicted
    int _stress;
    // Duration of the skill's effect
    int _duration;
    // Range of the skill
    int _range;
    // Target of the skill
    int _target;
    // Whether the skill targets the user
    int _selfTarget;
    // Whether the skill targets an enemy
    int _enemyTarget;
    // Whether the skill targets an ally
    int _allyTarget;
    // Whether the skill targets all characters
    int _allTarget;
    // Whether the skill targets the user
    int _self;
    // Whether the skill targets an enemy
    int _enemy;
    // Whether the skill targets an ally
    int _ally;
    // Whether the skill targets all characters
    int _all;
    // Whether the skill targets the front row
    int _front;
    // Whether the skill targets the back row
    int _back;
    // Whether the skill targets the first character
    int _first;
    // Whether the skill targets the last character
    int _last;
    // Whether the skill targets a random character
    int _random;
    // Additional targeting options...
public:
    // Use the skill
    virtual void Use() = 0;
};

#endif //DARKEST_DUNGEON_LITE_SKILL_H