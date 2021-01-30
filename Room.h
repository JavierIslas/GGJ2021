#include <vector>
#include "item.h"
#include "GameCharacter.h"

#ifndef ROOM_H
#define ROOM_H

class Room{

public:
    int pos;
    bool bIsExit;
    vector<Item> items;
    vector<GameCharacter> enemies;

    Room(int=0, bool=false, vector<Item> = vector<Item>(), vector<GameCharacter> = vector<GameCharacter>);
    void clearLoot();
    void clearEnemies();
};

#endif