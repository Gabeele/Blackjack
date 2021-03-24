#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 50
typedef struct player
{
	int ID;
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

void createProfile(pPLAYERLIST playerList);
void deleteProfile(pPLAYERLIST playerList, pNODE profile);
void alterName(pNODE profile, char* newName);
pNODE sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pNODE playerSelectByString(char* name);
void addFund(pNODE profile, int additionalFund);
