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

	printf("Type 0000 at any time to return and exit the program.\nPress any button to continue...");
	getchar();
	system("cls");

}

pPLAYER PlayerSelectMenu(char *cmdLnPlayer, pPLAYERLIST playerList) {
	int playerIndex = 0;

	if (playerList->head == NULL) {	//When there is no players in the list
		inputCreatePlayer(playerList);

		return playerList->head;	//Selects the newly inserted player
	}
	else {	//If there is any command line arguments
		pPLAYER playerSelected = playerSelectByString(playerList, cmdLnPlayer);

		if (playerSelected == NULL) {	//Check if there is a player by that name
			
			printPlayerList(playerList);
	
			do {	

				printf("Select a Player Number: ");
				
				playerIndex = getInput();

				if (playerIndex == NULL) {
					return;
				}


			} while (playerIndex >= playerListLength(playerList) || playerIndex < 0);
		 }
		else {
			return (playerSelected);
		}

	}

	return getPlayerFromList(playerList, playerIndex);

}

void mainMenu(pPLAYERLIST playerList, pPLAYER player) {
	int menuInput;

	printf("Welcome, %s\n", player->name );
	printf("Current Balance: %d\n", player->balance);
	printf("1) Learn to Play\n");
	printf("2) Menu and Operation Instructions\n");
	printf("3) Profile Options\n");
	printf("4) Play Game\n");
	printf("5) View Leaderboard\n");
	printf("0) Quit\n\n");

	printf("Enter a menu option: \n");
	

	menuInput = getInput();
	if (menuInput == NULL) {
		exit(0);
	}

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
	case 43:
		system("cls");
		profileOptions(player);

		if (player == NULL) {
			return;
		}

		system("cls");
		break;
	case 4:
		system("cls");
		playRound(player);
		system("cls");
		break;
	case 5:
		system("cls");
		displayLeaderboard(playerList);
		system("cls");
		break;
	}

}
	
void profileOptions(pPLAYER player) {
	char name[MAX_NAME_LENGTH];
	int menuInput;

	do {

		printf("Player Options Menu\n");
		printf("1) Change name\n");
		printf("2) View Stats\n");
		printf("3) Delete Account\n");
		printf("0) Exit\n\n");
		printf("Enter in a menu option: ");

		menuInput = getInput();


		if (menuInput == NULL) {
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
		case 3:
			printf("\nDeleting account is ireversible, and will exit the program. Click any key to continue...");
			getchar();

			deleteProfile(player);
			
			return;

		case 0:
			return;
			break;
		}

	} while (1);
}

void printPlayer(pPLAYER player) {

	printf("%s - $%d %d\n", player->name, player->balance);

}

void printPlayerList(pPLAYERLIST playerList) {	//Cycles through the prints the list with numbering scheme
	int counter = 1;

	pPLAYERNODE node = playerList->head;

	while (node != NULL) {
		
		printf("%d) %s\n", counter, getName(node->data));

		node->nextNode;

		counter++;
	}
}

void inputCreatePlayer(pPLAYERLIST playerList) {

	char name[MAX_NAME_LENGTH];

	printf("Create Player\n");

	do {
		scanf_s("%s", name, MAX_NAME_LENGTH);


	} while (strlen(name) == 0);
	
	if (checkAbort(name)) {
		return;
	}

	createPlayer(name);	//add


}

void displayLeaderboard(pPLAYERLIST playerList) {

	sortList(playerList);

	printf("Leaderboard\n\n");
	
	int counter = 1;

	pPLAYERNODE node = playerList->head;

	while (node != NULL) {

		printf("%d) %s - $%d\n", counter, getName(node->data), getBalance(node->data));

		node = node->nextNode;

		counter++;
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

int refillBalancePrompt(pPLAYER player) {

	int menuOption = 0;

	printf("Balance Notice\nBalance is 0, would you like to reset it to the default?\n");
	printf("1) Yes\n");
	printf("2) No\n");

	menuOption = getInput();
	if (menuOption == NULL) {
		return;
	}

	switch (menuOption)
	{
	case 1:

		resetBalance(player);
		break;
	case 2:
		break;

	}

	printf("\nClick any key to continue...\n");
	getchar();
}

int getInput() {
	int userInput = 0;

	do {

		printf("\nEnter Option: ");
		scanf_s("%d",userInput, MAX_INPUT);

		if (checkInt(userInput) == 0) {// 0  is good, 1 is bad, abort is 2

			break;
		}
		else if (checkInt(userInput) == 1) {

			printf("Inncorrect input...\n");
		}
		else if (checkInt(userInput) == 2) {

			return NULL;
		}

	} while (1);

	return userInput;
}
