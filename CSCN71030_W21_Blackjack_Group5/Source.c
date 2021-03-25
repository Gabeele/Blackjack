//CSCN71030 - Project II 
//
//Group 5

#include "Player.h"

int main() {

	pPLAYERLIST playerList;
	playerList = initializePlayerList();

	if (playerList->head == NULL)
		printf("initializePlayerList passed\n");
	printf("\n");

	printf("insert new player\n");
	char* name = "Rachel L";
	pPLAYER player1 = createPlayer(name);
	insertNewPlayer(playerList, player1);
	pPLAYER player2 = createPlayer("Gavin");
	insertNewPlayer(playerList, player2);
	pPLAYER player3 = createPlayer("Collin");
	insertNewPlayer(playerList, player3);
	printPlayerList(playerList);
	printf("\n");

	printf("add fund + reset balance\n");
	addFund(player1, 1000);
	addFund(player3, 4);
	addFund(player2, 86);
	resetBalance(player3);
	printPlayerList(playerList);
	printf("\n");

	printf("alter name\n");
	alterName(player2, "Josh");
	printPlayerList(playerList);
	printf("\n");

	printf("seach for player node through the name\n");
	pPLAYER player4 = playerSelectByString(playerList, "Rachel");
	printf("%s - %d\n", player4->name, player4->balance);
	printf("\n");

	printf("delete\n");
	deleteProfile(playerList, player1);
	printPlayerList(initializePlayerList);
	printf("head: %s\n", playerList->head->player->name);
	printf("\n");



	return 0;
}