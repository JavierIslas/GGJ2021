#include "Room.h"

Room::Room(int p, bool e, vector<Item> i, vector<GameCharacter> npcs){
    pos = p;
    bIsExit = e;
    items = i;
    enemies = npcs;
}
void Room::clearLoot(){
    items.clear();
}
void Room::clearEnemies(){
    enemies.clear();
}