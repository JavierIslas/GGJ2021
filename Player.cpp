#include "Player.h"

Player::Player(string n, int h, int a, int d): GameCharacter(n, h, a, d){
	Item dagger = Item("Dagger", 0, 5, 0);
	addItem(dagger);
}

void Player::addItem(Item item){
	cout << "You equiped " << item.name << "\n";
	inventory.push_back(item);
	increaseStat(item.health, item.attack, item.defence);
}

void Player::increaseStat(int h, int a, int d){
	currentHealth = currentHealth + h;
	maxHealth = maxHealth + h;
	attack = attack + a;
	defence = defence + d;
	cout << "Yours new stats are: \n Current Health = " << currentHealth << "\n Attack: " << attack << "\n Defence: " << defence << "\n";
}

void Player::lootRoom(Room *room){
	vector<Item> items = room->items;
	for(int i = 0; i < items.size(); ++i) {
		cout << "You find " << items[i].name << "\n";
		addItem(items[i]);
	}
}

void Player::changeRoom(Room *newRoom){
	previousRoom = currentRoom;
	currentRoom = newRoom;
}
