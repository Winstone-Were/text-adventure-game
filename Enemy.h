#pragma once
#include <string>

class Player;

class Enemy {
public:
    std::string name;
    int health;
    int combatRating;

    Enemy(std::string name, int health, int combatRating);

    void attack(Player& player);
};
