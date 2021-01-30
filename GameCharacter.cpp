#include "GameCharacter.h"

GameCharacter::GameCharacter(string n, int mh, int ch, int a, int d){
	name = n;
    health = h;
    currentHealth = h;
    attack = a;
    defence = d;
}

int GameCharacter::takeDamage(int amount){
    
    int damage = amount - defence;
    if(damage < 0) damage = 0;

    currentHealth -= damage;
    cout << name << " now has " << currentHealth << "Health";
    return damage;
}

bool GameCharacter::bIsDead(){
    return currentHealth <= 0;
}