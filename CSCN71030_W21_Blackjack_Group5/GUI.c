//CSCN71030 - Project II Group 5
//Blackjack 
//
//Febuary 26th, 2021 - 
//
//GUI Module - Created by Gavin Abeele gabeele2160@conestogac.on.ca
//This module's purpose is to interface with the user and the display. Here the system will interact using menus and user input to interact with other system modules
//

#include "GUI.h"

#include "TestingModule.h"


//Includes all modules

void printDisclamer() {

	printf("Type 0000 or Exit at any time to return and exit the program.\nPress any button to continue...");
	getchar();
	system("cls");

}



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
	char name[] = { "Gavin" };
	int score = 10.50, WLRatio = 1.5;

	printf("Welcome, %s\n", name );
	printf("Current Balance: %d, Wins/Loss Ratio: %d\n\n", score, WLRatio );
	printf("1) Learn to Play\n");
	printf("2) Menu and Operation Instructions\n");
	printf("3) Add Balance\n");
	printf("4) Profile Options\n");
	printf("5) Play Game\n");
	printf("6) View Leaderboard\n");
	printf("0) Quit\n\n");

	printf("Enter a menu option: \n");
	

	int menuInput = intagerValidation();

	switch (menuInput) {

	case 0:
		//save the profile list
		exit(0);
		break;

	case 1:
		displayLearnToPlay();
		break;
	case 2:
		displayInstructions();
		break;
	case 3:
		inputAddBalance(player);
		break;
	case 4:
		profileOptions(player);
		break;
	case 5:
		playGame(player);
		break;
	case 6:
		diplayLeaderboard(playerList);
		break;
	}

}
	

void printPlayer(pPLAYER player) {

	printf("%s - $%d %d\n", player->name, player->balance, player->gamesWon/(player->totalGames - player->gamesWon));

}

void displayLearnToPlay()
{
	printf("                                                     ---Learn to play BLACKJACK---\n");
	printf("Blackjack is a fun and simple casino style game. In fact, is the most popular table game in the casino!\n\n");
	printf("Goal: The goal of blackjack is to try to get the total card values as close to 21 without going over. As well, as beating the dealers hand.\n\n");
	printf("Terminology: \n");
	printf("\t Hit - To recieve another card from the dealer.\n");
	printf("\t Stand - Skip over, and don't receive another card.\n");
	printf("\t Bust - When the player or the deal go over 21 total card value.\n");
	printf("\t Push - When both you and the dealer's hards are equal.\n");
	printf("\t Split - Splitting cards when the hand has two of the same cards. Plays as two separate hands.\n");
	printf("\t Double Down - Doubling the bet, but not allowing any other hits.\n");
	printf("\n\n");
	printf("How to Play:\n");
	printf("\t 1) On the start of the round, place your bets.\n");
	printf("\t 2) Receive two cards.\n");
	printf("\t 3) Based on the your hand and the dealers hand, determine whether to hit or stand.\n");
	printf("\t 4) Repeat step 3 until everyone holds.\n");
	printf("\t 5) Cards are then tallied and a winner is determined\n");

}

void displayInstructions()
{
	printf("Instructions");

}