//CSCN71030 - Project II 
//
//Group 5
#define CRT_SECURE_NO_WARNINGS

#include "GUI.h"

#include "TestingModule.h"

int main() {

	//mainMenu();


	return 0;
}


pPLAYER createPlayer(pPLAYERLIST playerList, char name[]) {

	pPLAYER player;

	strcpy(player->name, name);
	player->balance = 100;
	player->totalGames = 0;
	player->gamesWon = 0;

	player->timeStamp = time(NULL);

	return player;

}

