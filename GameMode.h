#include <vector>
#include "item.h"
#include "GameCharacter.h"
#include "Player.h"

#ifndef GAMEMODE_H
#define GAMEMODE_H

class GameMode{

public:
    Player player;
    Room Dungeon[4];
    vector<Item> items;
    vector<GameCharacter> enemies;

    GameMode(Player);
    int runDungeon();
    void enterRoom(Room *);
    void handleEmptyRoom(Room *);
    void handleLootRoom(Room *);
    void handleEnemieRoom(Room *);
    void handleFightAction(GameCharacter *);
    void handleLootAction(Room *);
    void handleMovement(Room *);
    void printAction(int, string[]);
    int perfomrEndGame();
};

#endif