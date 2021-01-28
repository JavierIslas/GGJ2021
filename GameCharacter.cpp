#include "GameCharacter.h"

GameCharacter::GameCharacter(string n, int mh, int ch, int a, int d){

}

int GameCharacter::takeDamage(int amount){
    
    int damage = amount - defence;
    if(damage < 0) damage = 0;

    currentHealth -= damage;

    return damage;
}

bool GameCharacter::bIsDead(){
    return currentHealth <= 0;
}