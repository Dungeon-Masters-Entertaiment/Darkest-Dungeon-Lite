#ifndef DARKEST_DUNGEON_LITE_INVENTORY_H
#define DARKEST_DUNGEON_LITE_INVENTORY_H
#include <vector>
#include <string>
#include <iostream>
class Inventory {
public:
    // Статический метод для получения единственного экземпляра класса
    static Inventory& getInstance() {
        static Inventory instance; // Создание единственного экземпляра при первом вызове
        return instance;
    }

    // Методы для работы с инвентарем
    void addItem(const std::string& item) {
        items.push_back(item);
    }

    void showItems() const {
        std::cout << "Инвентарь:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item << std::endl;
        }
    }

private:
    // Запрещаем явное создание объектов класса
    Inventory() {}
    ~Inventory() {}

    // Запрещаем копирование и присваивание
    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    // Вектор для хранения предметов в инвентаре
    std::vector<std::string> items;
};
#endif