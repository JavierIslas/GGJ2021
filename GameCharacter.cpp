#include "GameCharacter.h"

GameCharacter::GameCharacter(string n, int mh, int a, int d){
	name = n;
    maxHealth = mh;
    currentHealth = mh;
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