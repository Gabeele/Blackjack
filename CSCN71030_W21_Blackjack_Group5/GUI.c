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



pPLAYER PlayerSelectMenu(char *cmdLnPlayer, pPLAYERLIST playerList) {
	int playerIndex;

	if (playerList->head == NULL) {	//When there is no players in the list
		inputCreatePlayer(playerList);

		return playerList->head;	//Selects the newly inserted player
	}
	else {	//If there is any command line arguments
		pPLAYER playerSelected = playerSelectByString(cmdLnPlayer);

		if (playerSelected == NULL) {	//Check if there is a player by that name
			
			printPlayerList(playerList);
	
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
		system("cls");
		displayLearnToPlay();
		system("cls");
		break;
	case 2:
		system("cls");
		displayInstructions();
		system("cls");
		break;
	case 3:
		system("cls");
		inputAddBalance(player);
		system("cls");
		break;
	case 4:
		system("cls");
		profileOptions(player);
		system("cls");
		break;
	case 5:
		system("cls");
		playGame(player);
		system("cls");
		break;
	case 6:
		system("cls");
		displayLeaderboard(playerList);
		system("cls");
		break;
	}

}
	
void profileOptions(pPLAYER player) {
	char name[MAX_NAME_LENGTH];

	do {

		printf("Player Options Menu\n");
		printf("1) Change name\n");
		printf("2) View Stats\n");
		printf("0) Exit\n\n");
		printf("Enter in a menu option: ");

		int menuInput = intagerValidation();

		if (verifyAbortIntager(menuInput)) {
			return;
		}

		switch (menuInput)
		{
		case 1:
			printf("\n\nChange name to: ");
			scanf_s("%s", name, MAX_NAME_LENGTH);

			changePlayerName(player, name);
			break;
		case 2:
			printPlayer(player);
			break;

		case 0:
			return;
			break;
		}

	} while (1);
}

void printPlayer(pPLAYER player) {

	printf("%s - $%d %d\n", player->name, player->balance, player->gamesWon/(player->totalGames - player->gamesWon));

}

void printPlayerList(pPLAYERLIST playerList) {	//Cycles through the prints the list with numbering scheme
	int counter = 1;

	pPLAYERNODE node = playerList->head;

	while (node != NULL) {
		
		printf("%d) %s\n", counter, node->data->name);

		node->nextNode;

		counter++;
	}
}

void inputCreatePlayer(pPLAYERLIST playerList) {

	char name[MAX_NAME_LENGTH];

	printf("Create Player\n");

	do {
		scanf_s("%c", name, MAX_NAME_LENGTH);


	} while (strlen(name) == 0);
	
	if (verifyAbortString(name)) {
		return;
	}

	createPlayer(playerList, name);	//add


}

void displayLeaderboard(pPLAYERLIST playerList) {
	int value = 0;
	pPLAYERNODE node = playerList->head;
	pPLAYERNODE smallestNode = playerList->head;

	value = node->data;

	while (node != NULL) {

		if (value > node->data) {
			value = node->data;
		}

		node = node->nextNode;
	}




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

	printf("\nClick any key to continue...\n");
	getchar();
}

void displayInstructions()
{
	printf("                                                     ---Game Instuctions---\n");
	printf("Moving Around Menus: You can move around the interfaces by entering menu options like 1 or 4.\n");
	printf("Exiting: To back out at any time enter in 0000 to return to the menu. To exit the program select the exit menu option.\n");
	printf("Adding Funds: Funds can be added to a players profile. However, this can only be done every 24 hours.\n");

	printf("\nClick any key to continue...\n");
	getchar();
}

void inputAddBalance(pPLAYER player) {

	int fundAmount = 0;

	printf("Adding Funds\nEnter in an amount from 0 - 100 to add funds to the account.\n");

	do {
		
		printf("\nDeposit Amount: ");
		fundAmount = intagerValidation();
		if (verifyAbortIntager(fundAmount)) {
			return;
		}

	} while (fundAmount >= 0 && fundAmount <= 100);

	if (addFunds(player, fundAmount)) {
		printf("\nFunds successfully transfered.\n");

	}
	else {
		printf("\nYou can only add funds once every 24 hours.\n");
	}

	printf("\nClick any key to continue...\n");
	getchar();
}

void playGame(pPLAYER player) {	//To play the game





}