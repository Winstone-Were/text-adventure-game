#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(std::string enemyName, int enemyHealth, int enemyCombatRating)
    : name(enemyName), health(enemyHealth), combatRating(enemyCombatRating) {}

void Enemy::attack(Player& player) {
    player.modifyHealth(-combatRating);
}
