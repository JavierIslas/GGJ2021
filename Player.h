#include "GameCharacter.h"
#include "Room.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public GameCharacter{

public:
    Room *currentRoom;
    Room *previousRoom;
    vector<Item> inventary;

    Player(string="", int=0, int=0, int=0);

    void addItem(Item);

    void increaseStat(int, int, int);

    void lootRoom(Room *);

    void chageRoom(Room *);

};
#endif