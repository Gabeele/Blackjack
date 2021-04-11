#pragma once

#include <string.h>
#include <time.h>

#define NAME_SIZE 100
#define DEFAULT_BALANCE 2000

typedef struct playerList {

	struct PLAYERNODE *head;

}PLAYERLIST, *pPLAYERLIST;

typedef struct playerNode {

	struct PLAYER *data;
	struct PLAYERNODE *nextNode;

}PLAYERNODE, *pPLAYERNODE;

typedef struct player {

	char name[NAME_SIZE];
	int balance;


}PLAYER, *pPLAYER;

pPLAYER createPlayer( char []);

pPLAYERNODE createNode(pPLAYER player);

pPLAYERLIST createList();

pPLAYER playerSelectByString(pPLAYERLIST list, char input[]);

int playerListLength(pPLAYERLIST list);

pPLAYER getPlayerFromList(pPLAYERLIST list, int index);

int checkInt(int input);

int checkAbort(char name[]);

void playRound(pPLAYER player);

void changePlayerName(pPLAYER player, char name[]);

void deleteProfile(pPLAYER player);

void sortList(pPLAYERLIST list);

void resetBalance(pPLAYER player);

int getBalance(pPLAYER player);

char* getName(pPLAYER player);

pPLAYER getPlayer(pPLAYERNODE);

pPLAYER addPlayer(pPLAYERLIST, char[]);

