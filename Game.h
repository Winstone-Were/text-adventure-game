#pragma once
#include "Player.h"
#include "Enemy.h"
#include <string>

class Game {
public:
    void handleStory(Player& player);
    void initiateCombat(Player& player, Enemy& enemy);
    void saveGame(Player& player);
    void loadGame(Player& player, const std::string& playerName);
    void startGame();
};
