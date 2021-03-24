//CSCN71030 - Project II 
//
//Group 5
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Player.h"
#include "FileIO.h"
#define MAXSIZE 20

int save(playerlist saveList, int length) { //Save Function
	FILE* fptr;
	fptr = fopen("Saved.txt", "w");
	if (fptr == NULL) { //make sure file opens
		pritnf_s("Error Saving");
		exit(1);
	}
	for (int i = 0; i < length; i++) { //save all info on different lines
		fputs(saveList.head.player->name, fptr);
		fputc('\n', fptr);
		fputs(saveList.head.player->balance, fptr);
		fputc('\n', fptr);
		fputs(saveList.head.player->id, fptr);
		fputc('\n', fptr);
		saveList.head.player = saveList.head.nextPlayer; //move to next player
	}
	fclose(fptr); //close files
	return 0;
}

int read(playerlist saveList, int length) {
	FILE* fptr;
	fptr = fopen("saved.txt", "r"); //open file
	if (fptr == NULL) { //make sure it opens
		pritnf_s("Error Retrieving Data");
		exit(1);
	}
	for (int i = 0; i < length; i++) { //save everything on seperate lines
		fgets(saveList.head.player->name, MAXSIZE, fptr);  
		fgets(saveList.head.player->balance, MAXSIZE, fptr); 
		fgets(saveList.head.player->id, MAXSIZE, fptr);
		saveList.head.player = saveList.head.nextPlayer; //move to next player
	}
	fclose(fptr); //close file
	return 0;
}