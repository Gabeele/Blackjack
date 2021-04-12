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

pPLAYER getPlayerFromList(pPLAYERLIST playerList, int index) {

	pNODE node = playerList->head;

	for (int i = 0; i < index; i++) {

		node = node->nextPlayer;

		if (node == NULL) {
			printf("Error: No player found.\n");
			return NULL;
		}

	}

	return node->player;
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
	//if (playerList->head != NULL)
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
	} while (swapped);

}
void printPlayerListpMod(pNODE head)
{
	if (head == NULL)
		return;

	printf("Player: %s, Balance: %d\n", head->player->name, head->player->balance);
	printPlayerList(head->nextPlayer);
}
pPLAYER playerSelectByString(pPLAYERLIST playerList, char* inputName)
{
	int checkNameFlag = 0;

	//inputName[strlen(inputName)] = '\n';

	if (playerList->head == NULL)
		return NULL;
	pNODE currentPlayer = (pNODE)malloc(sizeof(NODE));
	currentPlayer = playerList->head;
	do
	{
		if (inputName == NULL) {
			return NULL;
		}

		for(int i = 0; i < strlen(inputName); i++) {

			if (inputName[i] != currentPlayer->player->name[i]) {
				checkNameFlag = 1;
			}

		}

		if (checkNameFlag == 0)
			return currentPlayer->player;
		else
			currentPlayer = currentPlayer->nextPlayer;
	} while (currentPlayer != NULL);
	printf("There is no matching player\n");
	return NULL;

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

int getListLength(pPLAYERLIST playerList) {
	int counter = 0;

	pNODE node = playerList->head;

	while (node != NULL) {

		counter++;
		node = node->nextPlayer;
	}

	return counter;
}