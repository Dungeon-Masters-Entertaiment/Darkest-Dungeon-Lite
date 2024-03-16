#ifndef DARKEST_DUNGEON_LITE_ENTITY_H
#define DARKEST_DUNGEON_LITE_ENTITY_H

#include <utility>

class Entity {
public:
    virtual ~Entity() = default; // Virtual destructor

    virtual void Draw() const = 0; // Render the entity
    virtual void Move(int dx, int dy) = 0; // Move the entity by dx, dy
    virtual void Attack(Entity& target) = 0; // Attack another entity
    virtual void Die() = 0; // Handle death of the entity
    virtual void TakeDamage(int damage) = 0; // Take damage from an attack
    virtual int GetDamage() const = 0; // Get the damage this entity can deal
    virtual int GetHealth() const = 0; // Get the current health of the entity
    virtual std::pair<int, int> GetPosition() const = 0; // Get the current position of the entity
    virtual void SetPosition(int x, int y) = 0; // Set the position of the entity
};

class Enemy : public Entity {

};

#endif //DARKEST_DUNGEON_LITE_ENTITY_H