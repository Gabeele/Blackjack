#include "Player.h"

void initializePlayerList(pPLAYERLIST playerList)
{
	playerList->head = NULL;
}
void insertNewPlayer(pPLAYERLIST playerList, char* playerName)
{
	pNODE newPlayer;
	strcpy_s(newPlayer->player->name, strlen(playerName), playerName);
	newPlayer->player->balance = DEFAULT_BALANCE;
	newPlayer->nextPlayer = playerList->head;
	playerList->head = newPlayer;
	sortPlayerList(playerList);
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
pNODE sortPlayerList(pPLAYERLIST playerList)
{
	if (playerList->head == NULL || playerList->head->nextPlayer == NULL)	//1-node playerList
		return;

	//find the node that has the largest value
	pNODE currentNode = playerList->head;
	pNODE largestNode = playerList->head;
	pNODE prevofCurrentNode = playerList->head;
	pNODE prevOfLargestNode = playerList->head;
	pNODE headNode = playerList->head;

	while (currentNode != NULL)
	{
		if (currentNode->player->balance > largestNode->player->balance)
		{
			prevOfLargestNode = prevofCurrentNode;
			largestNode = currentNode;
		}
		prevofCurrentNode = currentNode;
		currentNode = currentNode->nextPlayer;
	} //largest node is found

	//switch the first node with the largest node
	pNODE tmp;
	if (largestNode != playerList->head)
	{
		tmp = headNode->nextPlayer;
		prevOfLargestNode->nextPlayer = headNode;
		headNode->nextPlayer = largestNode->nextPlayer;
		largestNode->nextPlayer = tmp;
	}//now the largest node is the first node of the list

	//do the same thing for the rest of the list by calling the function again with the sub list
	playerList->head = largestNode->nextPlayer;
	largestNode->nextPlayer = sortPlayerList(playerList);
	return largestNode;	//the first node of the sorted list 
}
void printPlayerList(pPLAYERLIST playerList)
{
	if (playerList->head == NULL)
		return;

	int i = 1;
	pNODE currentNode = playerList->head;
	while (playerList->head == NULL)
	{
		printf("%d)\t %s\n", i, currentNode->player->name);
		i++;
		currentNode = currentNode->nextPlayer;
	}
}
pNODE playerSelectByString(pPLAYERLIST playerList, char* inputName)
{
	if (playerList->head == NULL)
		return NULL;
	pNODE currentPlayer = playerList->head;
	while (strcmp(currentPlayer->player->name, inputName) != 0)
	{
		currentPlayer = currentPlayer->nextPlayer;
		if (currentPlayer == NULL)
			return NULL;
	}
	return currentPlayer;
}
void addFund(pNODE profile, int additionalFund);