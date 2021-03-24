#include "Player.h"

void createProfile(pPLAYERLIST playerList)
{
	playerList->head = NULL;
}
void deleteProfile(pPLAYERLIST playerList, pPLAYER profile)
{
	if (playerList->head == NULL)
		return;

	pNODE prev = NULL;
	pNODE currentPlayer = playerList->head;
	while (currentPlayer->player != profile)
	{
		prev = currentPlayer;
		currentPlayer = currentPlayer->nextPlayer;
		if (currentPlayer->player == profile)
			break;
		else if (currentPlayer == NULL)
			return;
	}
	prev->nextPlayer = currentPlayer->nextPlayer;  //skip the current node
	currentPlayer = NULL;						   //point the current node to null then free it
	free(currentPlayer);
}
void alterName(pPLAYER profile, char* newName);
void sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pPLAYER playerSelectByString(char* name);
void addFund(pPLAYER profile, int additionalFund);