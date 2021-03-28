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
	sortPlayerList(playerList);
}
void deleteProfile(pPLAYERLIST playerList, pPLAYER profile)
{
	if (playerList->head == NULL)
		return;

	pNODE prev = playerList->head;
	pNODE currentPlayer = playerList->head;
	while (strcmp(currentPlayer->player->name, profile->name)!=0)
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
void alterName(pPLAYER profile, char* newName)
{
	strcpy_s(profile->name, strlen(newName), newName);
}
pNODE sortPlayerList(pPLAYERLIST playerList)
{
	if (playerList->head == NULL || playerList->head->nextPlayer == NULL)	//1-node playerList
		return NULL;

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
void printPlayerList(pNODE head)
{
	if (head == NULL)
		return;

	/*int i = 1;
	pNODE currentNode = (pNODE)malloc(sizeof(NODE));
	if (!currentNode)
	{
		fprintf(stdout, "Error allocating data\n");
		exit;
	}
	currentNode= playerList->head;
	while (playerList->head != NULL)
	{*/
		printf("%s\n", head->player->name);
		printPlayerList(head->nextPlayer);
		//i++;
		//currentNode = currentNode->nextPlayer;
	//}
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