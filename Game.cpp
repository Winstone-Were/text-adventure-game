#include "Game.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Game::handleStory(Player& player) {
    std::ifstream file("story.json");
    json storyData;
    file >> storyData;

    std::string currentStory = "start";
    while (player.lives > 0) {
        json scenario = storyData[currentStory];
        std::cout << scenario["story-line"] << std::endl;

        int choiceIndex = 1;
        for (const auto& choice : scenario["choices"]) {
            std::cout << choiceIndex << ": " << choice << std::endl;
            choiceIndex++;
        }

        int playerChoice;
        std::cin >> playerChoice;
        currentStory = scenario["next"][playerChoice - 1];
    }
}

void Game::initiateCombat(Player& player, Enemy& enemy) {
    while (player.health > 0 && enemy.health > 0) {
        std::cout << "Player Health: " << player.health << ", Enemy Health: " << enemy.health << std::endl;
        std::cout << "Choose action: 1. Attack 2. Defend" << std::endl;

        int action;
        std::cin >> action;

        if (action == 1) {
            enemy.health -= player.combatRating;
        } else if (action == 2) {
            player.modifyHealth(enemy.combatRating / 2);
        }

        if (enemy.health > 0) {
            enemy.attack(player);
        }
    }
    if (player.health <= 0) {
        player.lives--;
        player.health = 100;
        std::cout << "You lost a life. Lives left: " << player.lives << std::endl;
    } else {
        std::cout << "Enemy defeated!" << std::endl;
    }
}

void Game::saveGame(Player& player) {
    player.saveProgress();
    std::cout << "Game saved." << std::endl;
}

void Game::loadGame(Player& player, const std::string& playerName) {
    if (player.loadProgress(playerName)) {
        std::cout << "Game loaded." << std::endl;
    } else {
        std::cout << "No save file found." << std::endl;
    }
}

void Game::startGame() {
    std::cout << "Welcome to the Adventure Game!" << std::endl;
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player player(playerName);
    if (player.loadProgress(playerName)) {
        std::cout << "Welcome back, " << playerName << "!" << std::endl;
    } else {
        std::cout << "Good luck on your adventure, " << playerName << "!" << std::endl;
    }

    handleStory(player);
    saveGame(player);
    std::cout << "Thanks for playing!" << std::endl;
}
