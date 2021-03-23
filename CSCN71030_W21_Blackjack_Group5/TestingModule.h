#pragma once

#include <string.h>

#define NAME_SIZE 100

typedef struct playerList {

	pPLAYERNODE head;

}PLAYERLIST, * pPLAYERLIST;

typedef struct playerNode {

	pPLAYER data;
	pPLAYERNODE nextNode;

}PLAYERNODE, * pPLAYERNODE;

typedef struct player {

	char name[NAME_SIZE];
	double balance;
	int totalGames;
	int gamesWon;

}PLAYER, * pPLAYER;

pPLAYER createPlayer(char [], double , int , int);
