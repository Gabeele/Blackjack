//CSCN71030 - Project II Group 5
//Blackjack 
//
//Febuary 26th, 2021 - 
//
//GUI Module - Created by Gavin Abeele gabeele2160@conestogac.on.ca
//This module's purpose is to interface with the user and the display. Here the system will interact using menus and user input to interact with other system modules
//

#include "GUI.h"


//Includes all modules

void printDisclamer() {

	printf("Type 0000 or Exit at any time to return and exit the program.\nPress any button to continue...");
	getchar();
	system("cls");

}

/// <summary>
/// Print the player list and allow users to select the designated player
/// </summary>
/// <param name="cmdLnPlayer">Command Line Argument which can be used to select the player</param>
/// <param name="playerList">Pointer to the list of players</param>
pPLAYER PlayerSelectMenu(char *cmdLnPlayer, pPLAYERLIST playerList) {
	int playerIndex;

	if (playerList->head == NULL) {	//When there is no players in the list
		createPlayerMenu();
	}
	else {	//If there is any command line arguments
		pPLAYER playerSelected = playerSelectByString(cmdLnPlayer);

		if (playerSelected) {	//Check if there is a player by that name
			//printPlayerList()

			do {	

				printf("Select a Player Number: ");
				playerIndex = integerValdation();	//Input validation

				if (verifyAbortIntager(playerIndex)) {	//Verifies abort intager
					return;
				}

				playerIndex--;	

			} while (playerIndex >= playerListLength(playerList) || playerIndex < 0);
		 }
		else {
			return (playerSelected);
		}

	}

	return getPlayerFromList(playerList, playerIndex);

}

void mainMenu(pPLAYERLIST playerList, pPLAYER player) {

	printf("------Main Menu------");

}

