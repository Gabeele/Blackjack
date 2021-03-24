#include "Player.h"

void createProfile(pPLAYERLIST playerList)
{
	playerList->head = NULL;
}
void deleteProfile(pPLAYERLIST playerList, pNODE profile)
{
	if (playerList->head == NULL)
		return;

	pNODE prev = NULL;
	pNODE currentPlayer = playerList->head;
	while (strcmp(currentPlayer->player->name, profile->player->name)!=0)
	{
		prev = currentPlayer;
		currentPlayer = currentPlayer->nextPlayer;
		if (currentPlayer == NULL)
			return;
	}
	//when the wanted deleted profile is found, do this:
	prev->nextPlayer = currentPlayer->nextPlayer;  //skip the current node
	currentPlayer = NULL;						   //point the current node to null then free it
	free(currentPlayer);
}
void alterName(pNODE profile, char* newName)
{
	strcpy_s(profile->player->name, strlen(newName), newName);
}
void sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pNODE playerSelectByString(char* name);
void addFund(pNODE profile, int additionalFund);