#pragma once
#include <string>
#include <vector>
#include <map>

class Item {
public:
    std::string name;
    std::map<std::string, int> effects;

    Item(std::string name, std::map<std::string, int> effects)
        : name(name), effects(effects) {}
};

class Player {
public:
    std::string name;
    int health;
    int lives;
    int score;
    int combatRating;
    std::vector<Item> inventory;

    Player(std::string playerName);

    void modifyHealth(int amount);
    void addItem(const Item& item);
    void displayInventory();
    void saveProgress();
    bool loadProgress(const std::string& playerName);
};
