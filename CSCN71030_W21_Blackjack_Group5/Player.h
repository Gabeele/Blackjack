#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 50
#define DEFAULT_BALANCE 2000
typedef struct player
{
	char name[MAXLENGTH];
	int balance;
}PLAYER, *pPLAYER;

typedef struct node
{
	pPLAYER player;
	struct node* nextPlayer;
}*pNODE, NODE;

typedef struct playerList
{
	pNODE head;
}PLAYERLIST, * pPLAYERLIST;

pPLAYERLIST initializePlayerList();
pPLAYER createPlayer(char* name);
void insertNewPlayer(pPLAYERLIST playerList, pPLAYER newPlayer);
void deleteProfile(pPLAYERLIST playerList, pPLAYER profile);
void alterName(pPLAYER profile, char* newName);
void sortPlayerList(pNODE head);
void printPlayerList(pNODE head);
pPLAYER playerSelectByString(pPLAYERLIST playerList, char* inputName);
void resetBalance(pPLAYER profile);
void addFund(pPLAYER profile, int additionalFund);
pPLAYER getPlayer(pNODE node);
char* getName(pPLAYER player);
int getBalane(pPLAYER player);




