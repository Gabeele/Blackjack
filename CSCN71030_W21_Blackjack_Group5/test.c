#include <stdio.h>
#include "FileIO.h"
#include "Player.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
	pPLAYERLIST playerList;
	playerList = initializePlayerList;
	read(playerList);
	printPlayerList(playerList->head);
	return 0;
}