//CSCN71030 - Project II 
//
//Group 5
#define MAXSIZE 20
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "FileIO.h"
#include "Player.h"


int save(pPLAYERLIST saveList, int length) { //Save Function
	FILE* fptr;
	fptr = fopen("Saved.txt", "w");
	if (fptr == NULL) { //make sure file opens
		printf_s("Error Saving");
		return 1;
	}
	for (int i = 0; i < length; i++) { //save all info on different lines
		fprintf(fptr, "%s", saveList->head->player->name);
		fputc('\n', fptr);
		fprintf(fptr, "%d", ~(saveList->head->player->balance));
		fputc('\n', fptr);
		saveList->head->player = saveList->head->nextPlayer; //move to next player
	}
	fclose(fptr); //close files
	return 0;
}

int read(pPLAYERLIST saveList) {
	char temp[MAXSIZE];
	FILE* fptr;
	fptr = fopen("saved.txt", "r"); //open file
	if (fptr == NULL) { //make sure it opens
		printf_s("Error Retrieving Data");
		return 1;
	}
	while (!feof(fptr)) {
		fgets(temp, MAXSIZE, fptr);
		pPLAYER newPlayer = createPlayer(temp);
		fgets(temp, MAXSIZE, fptr);
		newPlayer->balance = atoi(temp);
		newPlayer->balance = ~(newPlayer->balance);
		insertNewPlayer(saveList, newPlayer);
	}
	fclose(fptr); //close file
	return 0;
}