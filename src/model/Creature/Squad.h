#ifndef MYGAME_SRC_SQUAD_SQUAD_H_
#define MYGAME_SRC_SQUAD_SQUAD_H_

#include "Hero.h"
#include <vector>
#include <memory>

class Squad {
public:
    Squad() = default;
    virtual ~Squad() = default;

    // Методы
    void addHero(const std::shared_ptr<Hero>& hero); 
    void removeHero(int index); // Удаление героя из отряда по индексу
    void attackSquad(Squad& enemySquad); // Атака другого отряда (Рандомно)
    void attackSquad(Squad& enemySquad, int enemyindx, int indx, int damage); // Атака другого отряда, определенного персонажа
    bool isAllDead() const; // Проверка на живость всех героев в отряде
    int getRandomLivingHero(); // Получение случайного живого героя из отряда
    void takeDamage(int indx, int amount);

    int getCount() const { return heroes.size(); }
private:
    std::vector<std::shared_ptr<Hero>> heroes; // Вектор героев в отряде
};

#endif //MYGAME_SRC_SQUAD_SQUAD_H_
