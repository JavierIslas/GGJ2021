#include "GameMode.h"
#include <iostream>
#include "Player.h"

GameMode::GameMode(Player gc){
	player = gc;

}

int GameMode::runDungeon(){
	cout << "Dungeon Start\n";
	player.currentRoom = &Dungeon[0];
	player.previousRoom = &Dungeon[0];
	while(true){
		enterRoom(player.currentRoom);
		if(player.bIsDead()){
			cout << "Game Over";
			return perfomrEndGame();
		}else if(player.currentRoom->bIsExit){
			if(player.currentRoom->enemies.size() == 0){
				cout << "You won\nPlay again?";
				return perfomrEndGame();
			}
		}
		handleMovement(player.currentRoom);
	}
}

void GameMode::enterRoom(Room *newRoom){
	if(newRoom->enemies.size() != 0){
		handleEnemieRoom(newRoom);
	} else if(newRoom->items.size() != 0){
		handleLootRoom(newRoom);
	}else{
		handleEmptyRoom(newRoom);
	}
}

void GameMode::handleEmptyRoom(Room *room){
	cout << "You find nothing\n";
	string actions[] = {"1: Move to next room"};
	while(true){
		printAction(1, actions);
		string input;
		cin >> input;
		if(input == "1"){
			return;
		}else cout << "Invalid choise.\n";
	}
}

void GameMode::handleLootRoom(Room *room){
	cout << "You find a chest\n";
	string actions[] = {"1: Loot Chest","2: Move to next room"};
	while(true){
		printAction(2, actions);
		string input;
		cin >> input;
		if(input == "1"){
			handleLootAction(room);
			return;
		} else if(input == "2"){
			return;
		} else cout << "Invalid choise.\n";
	}
}

void GameMode::handleEnemieRoom(Room *room){
	GameCharacter enemy = room->enemies.front();
	cout << "You enter the room and see " << enemy.name << "\n";
	string actions[] = {"1: Fight " + enemy.name,"2: Go back"};
	while(true){
		printAction(2, actions);
		string input;
		cin >> input;
		if(input == "1"){
			handleFightAction(&enemy);
			return;
		} else if(input == "2"){
			player.changeRoom(player.previousRoom);
			enterRoom(player.currentRoom);
			return;
		} else cout << "Invalid choise.\n";
	}
}

void GameMode::handleFightAction(GameCharacter *cE){
	string actions[] = {"1: Attack " + cE->name,"2: Retreat"};
	while(true){
		printAction(2, actions);
		string input;
		cin >> input;
		if(input == "1"){
			int damage = cE->takeDamage(player.attack);
			cout << "Your attack does " << damage << " to " << cE->name << "\n";
		} else if(input == "2"){
			player.changeRoom(player.previousRoom);
			enterRoom(player.currentRoom);
			return;
		} else cout << "Invalid choise.\n";

		if(cE->bIsDead()){
			cout << "Enemy defeated " << cE->name << "\n";
			player.increaseStat(2, 1, 1);
			player.currentRoom->clearEnemies();
			return;
		}else {
			int damage = player.takeDamage(cE->attack);
			cout << cE->name << "'s attack does " << damage << " to you\n";
			if(player.bIsDead()){
				cout << "You died\n";
				return;
			}
		}
	}
}

void GameMode::handleLootAction(Room * cR){
	player.lootRoom(cR);
	cR->clearLoot();
	cout << "The Chest is empty now";
}

void GameMode::handleMovement(Room *room){
	while(true){
		if(room->pos == 0){
			string actions[] = {"1: Go West","2: Move North"};
			printAction(2, actions);
			string input;
			cin >> input;
			if(input == "1"){
				player.changeRoom(&Dungeon[1]);
				return;
			}else if(input == "2"){
				player.changeRoom(&Dungeon[2]);
				return;
			}else cout << "Invalid choise.\n";
		}else if(room->pos == 1){
			string actions[] = {"1: Go East"};
			printAction(1, actions);
			string input;
			cin >> input;
			if(input == "1"){
				player.changeRoom(&Dungeon[0]);
				return;
			}else cout << "Invalid choise.\n";
		}else if(room->pos == 2){
			string actions[] = {"1: Go East","2: Move North"};
			printAction(2, actions);
			string input;
			cin >> input;
			if(input == "1"){
				player.changeRoom(&Dungeon[3]);
				return;
			}else if(input == "2"){
				player.changeRoom(&Dungeon[0]);
				return;
			}else{
				string actions[] = {"1: Go West"};
				printAction(1, actions);
				string input;
				cin >> input;
				if(input == "1"){
					player.changeRoom(&Dungeon[2]);
					return;
				}
			}
		}
	}
}

void GameMode::printAction(int numAction, string actions[]){
	cout << "Choise next action: \n";
	for (int i = 0; i < numAction; ++i){
		cout << actions[i] << "\n";
	}
}

int GameMode::perfomrEndGame(){
	string actions[] = {"1: Yes", "2: No"};
	printAction(2, actions);
	string input;
	cin >> input;
	if(input == "1"){
		return 1;
	}else if(input == "2"){
		return 0;
	}else{
		cout << "Invalid option";
	}
}