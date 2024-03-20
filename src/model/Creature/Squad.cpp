#include "Squad.h"
#include <algorithm>
#include <cstdlib>

// Добавление героя в отряд
void Squad::addHero(const std::shared_ptr<Hero>& hero) {
    heroes.push_back(hero);
}

// Удаление героя из отряда по индексу
void Squad::removeHero(int index) {
    if (index >= 0 && index < heroes.size()) {
        heroes.erase(heroes.begin() + index);
    }
}

// Атака другого отряда
void Squad::attackSquad(Squad& enemySquad) {
    int attackingindx = getRandomLivingHero();
    int targetindx                  = enemySquad.getCount();
    int damage                      = 12;
    
    // Взятие рандомного оружия

    attackSquad(enemySquad, targetindx, attackingindx, damage);
}

void Squad::attackSquad(Squad& enemySquad, int targetindx, int indx, int damage) { // Заменить на оружие, а не дамаг по-хорошему 
    std::shared_ptr<Hero> attacking = heroes[indx];
    // В случае оружия реализовать логику крита/дамага 
    enemySquad.takeDamage(targetindx, damage);

}

// Проверка, жив ли ещё хоть один герой в отряде
bool Squad::isAllDead() const {
    return std::none_of(heroes.begin(), heroes.end(), [](const auto& hero) {
        return !hero->isDead();
    });
}

// Получить случайного живого героя из отряда
int Squad::getRandomLivingHero() {
    std::vector<int> livingHeroes;
    int i = 0;
    for (auto& hero : heroes) {
        if (!hero->isDead()) {
            livingHeroes.push_back(i);
        }
        i++;
    }
    if (!livingHeroes.empty()) {
        size_t randomIndex = std::rand() % livingHeroes.size();
        return livingHeroes[randomIndex];
    }
    return -1; // В случае, если живых героев нет
}

// Лечение всего отряда
void Squad::healSquad(int amount) {
    for (auto& hero : heroes) {
        if (!hero->isDead()) {
            hero->heal(amount);
        }
    }
}

void Squad::takeDamage(int indx, int amount) {
    std::shared_ptr<Hero> target = heroes[indx];

    if(target.get()->getHealth() > 0) {
        target.get()->takeDamage(std::min(target.get()->getHealth(), amount));
        if(target.get()->getHealth() == 0){
            target.get()->takeDamage(12); // рандом хп для трупа
        }
    }
    else{
        target.get()->takeDamage(std::min(target.get()->getHealth(), -amount));
        if(target.get()->getHealth() == 0){
            removeHero(indx);
        }
    }
}
