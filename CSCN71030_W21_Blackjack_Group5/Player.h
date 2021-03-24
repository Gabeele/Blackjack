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
void deleteProfile(pPLAYERLIST playerList, pPLAYER profile);
void alterName(pPLAYER profile, char* newName);
void sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pPLAYER playerSelectByString(char* name);
void addFund(pPLAYER profile, int additionalFund);
