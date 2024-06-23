#include "Player.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Player::Player(std::string playerName) : name(playerName), health(100), lives(3), score(0), combatRating(10) {}

void Player::modifyHealth(int amount) {
    health += amount;
    if (health <= 0) {
        lives--;
        health = 100; // Reset health when a life is lost
    }
}

void Player::addItem(const Item& item) {
    inventory.push_back(item);
}

void Player::displayInventory() {
    std::cout << "Inventory:" << std::endl;
    for (const auto& item : inventory) {
        std::cout << "- " << item.name << std::endl;
    }
}

void Player::saveProgress() {
    json j;
    j["name"] = name;
    j["health"] = health;
    j["lives"] = lives;
    j["score"] = score;
    j["combatRating"] = combatRating;

    std::vector<json> items;
    for (const auto& item : inventory) {
        json itemJson;
        itemJson["name"] = item.name;
        itemJson["effects"] = item.effects;
        items.push_back(itemJson);
    }
    j["inventory"] = items;

    std::ofstream file(name + "_save.json");
    file << j;
}

bool Player::loadProgress(const std::string& playerName) {
    std::ifstream file(playerName + "_save.json");
    if (!file.is_open()) return false;

    json j;
    file >> j;

    name = j["name"];
    health = j["health"];
    lives = j["lives"];
    score = j["score"];
    combatRating = j["combatRating"];

    inventory.clear();
    for (const auto& itemJson : j["inventory"]) {
        Item item(itemJson["name"], itemJson["effects"].get<std::map<std::string, int>>());
        inventory.push_back(item);
    }
    return true;
}
