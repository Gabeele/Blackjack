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
}*pPLAYER;

typedef struct node
{
	pPLAYER player;
	pNODE nextPlayer;
}*pNODE;

typedef struct playerList
{
	pNODE head;
} *pPLAYERLIST;

void initializePlayerList(pPLAYERLIST playerList);
void insertNewPlayer(pPLAYERLIST playerList, char* playerName);
void deleteProfile(pPLAYERLIST playerList, pNODE profile);
void alterName(pNODE profile, char* newName);
pNODE sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pNODE playerSelectByString(pPLAYERLIST playerList, char* inputName);
void resetBalance(pNODE profile);
void addFund(pNODE profile, int additionalFund);
