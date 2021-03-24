#pragma once
//temp meant for testing will be deleted
#define MAXSIZE 20

typedef struct player { 
	int id;
	char name[MAXSIZE];
	int balance;

}PLAYER, * pPLAYER;

typedef struct playerNode {
	pPLAYER player;
	pNODE nextPlayer;
}NODE, *pNODE;

typedef struct playerlist {
	NODE head;
}playerlist, * pPLAYERLIST;