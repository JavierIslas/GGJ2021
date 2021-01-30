#include <iostream>
#include "GameCharacter.h"
#include "Room.h"

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player: public GameCharacter{

public:
    Room *currentRoom;
    Room *previousRoom;
    vector<Item> inventory;

    Player(string="", int=0, int=0, int=0);

    void addItem(Item);

    void increaseStat(int, int, int);

    void lootRoom(Room *);

    void changeRoom(Room *);

};
#endif