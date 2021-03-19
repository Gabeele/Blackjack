#pragma once

#define NAME_SIZE 100

typedef struct playerList {

	pPLAYERNODE head;

}PLAYERLIST, * pPLAYERLIST;

typedef struct playerNode {

	pPLAYER data;
	pPLAYERNODE nextNode;

}PLAYERNODE, * pPLAYERNODE;

typedef struct player {

	char NAME[NAME_SIZE];
	double balance;
	int totalGames;
	int gamesWon;

}PLAYER, * pPLAYER;

