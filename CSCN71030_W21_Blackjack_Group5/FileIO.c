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
	pNODE head = saveList->head;
	for (int i = 0; i < length - 1; i++) { //save all info on different lines
		fprintf(fptr, "%s", head->player->name);
		if (head->player->name[strlen(head->player->name) + 1] != '\n') {
			fputc('\n', fptr);
		}
		fprintf(fptr, "%d", ~(head->player->balance));
		fputc('\n', fptr);
		head = head->nextPlayer; //move to next player
	}
	fprintf(fptr, "%s", head->player->name);
	if (head->player->name[strlen(head->player->name)-1] != '\n') {
		fputc('\n', fptr);
	}
	fprintf(fptr, "%d", ~(head->player->balance));
	fclose(fptr); //close files
	return 0;
}

int read(pPLAYERLIST saveList) {
	char temp[MAXSIZE];
	FILE* fptr;
	fptr = fopen("saved.txt", "r"); //open file
	if (fptr == NULL) { //make sure it opens
		printf_s("Error: File not found.\n");
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