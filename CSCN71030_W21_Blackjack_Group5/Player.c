#include "Player.h"

pPLAYERLIST initializePlayerList()
{
	pPLAYERLIST newPlayerList = (pPLAYERLIST)malloc(sizeof(PLAYERLIST));
	if (!newPlayerList)
	{
		fprintf(stdout, "Error allocating data\n");
		exit;
	}
	newPlayerList->head = NULL;
	return newPlayerList;
}
pPLAYER createPlayer(char* name)
{
	pPLAYER newPlayer = (pPLAYER)malloc(sizeof(PLAYER));
	if (!newPlayer)
	{
		fprintf(stdout, "Error allocating data\n");
		exit;
	}
	memcpy(newPlayer->name, name, MAXLENGTH);
	newPlayer->balance = DEFAULT_BALANCE;

	return newPlayer;
}
void insertNewPlayer(pPLAYERLIST playerList, pPLAYER newPlayer)
{//add the new player to the front of the list and then sort the whole list
	pNODE newNode = (pNODE)malloc(sizeof(NODE));
	if (!newNode)
	{
		fprintf(stdout, "Error allocating data\n");
		exit;
	}
	newNode->player = newPlayer;
	newNode->nextPlayer = playerList->head;
	playerList->head = newNode;
	sortPlayerList(playerList->head);
}
/*void deleteProfile(pPLAYERLIST playerList, pPLAYER profile)
{
	if (playerList->head == NULL)
		return;

	pNODE currentNode = (pNODE)malloc(sizeof(NODE));
	pNODE temp = (pNODE)malloc(sizeof(NODE));
	currentNode = playerList->head;

	while (strcmp(currentNode->player->name, profile->name)!=0)
	{
		currentNode = currentNode->nextPlayer;
		//currentPlayer = currentPlayer->nextPlayer;
		if (currentNode == NULL)
			return;
	}
	//when the wanted deleted profile is found, do this:

	temp = currentNode->nextPlayer;  //skip the current node
	currentNode = temp->nextPlayer;

	free(temp);
}*/
void alterName(pPLAYER profile, char* newName)
{
	memcpy(profile->name, newName, strlen(newName));
}
void sortPlayerList(pNODE head)
{
	int swapped, i;
	pNODE node;
	pNODE temp = (pNODE)malloc(sizeof(NODE));
	pNODE nextNode = (pNODE)malloc(sizeof(NODE));
	do
	{
		swapped = 0;
		node = head;

		while (node->nextPlayer != NULL)
		{
			nextNode = node->nextPlayer;
			if (node->player->balance < nextNode->player->balance)
			{	//swapping
				 
				temp = node->player;
				node->player = nextNode->player;
				nextNode->player = temp;
				swapped = 1;
			}
			node = node->nextPlayer;
		}
	}while (swapped);

}
void printPlayerList(pNODE head)
{
	if (head == NULL)
		return;

	printf("Player: %s, Balance: %d\n", head->player->name, head->player->balance);
	printPlayerList(head->nextPlayer);
}
pPLAYER playerSelectByString(pPLAYERLIST playerList, char* inputName)
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
	return currentPlayer->player;
}
void resetBalance(pPLAYER profile)
{
	profile->balance = DEFAULT_BALANCE;
}
void addFund(pPLAYER profile, int additionalFund)
{
	profile->balance += additionalFund;
}

pPLAYER getPlayer(pNODE node)
{
	return node->player;
}
char* getName(pPLAYER player)
{
	return player->name;
}
int getBalane(pPLAYER player)
{
	return player->balance;
}