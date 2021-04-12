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


pPLAYER PlayerSelectMenu(char *cmdLnPlayer, pPLAYERLIST playerList) {
	int playerIndex = 0;

	if (playerList->head == NULL) {	//When there is no players in the list

		printf("ATTENTION: There are no players initalized, creating new player...\n\n");
		inputCreatePlayer(playerList);	

		system("cls");
		return getPlayer(playerList->head);	//Selects the newly inserted player
	}
	else {	//If there is any command line arguments
		
		pPLAYER playerSelected = playerSelectByString(playerList, cmdLnPlayer);

		if (playerSelected == NULL) {	//Check if there is a player by that name
			
			printPlayerList(playerList);
			printf("0) Create New Player\n\n");

			do {	

				
				printf("\nSelect a Player Number");
				
				playerIndex = getInput();

				if (playerIndex == NULL) {	//If the user selected 0 prompt the user to input a new player
					inputCreatePlayer(playerList);
				}

			} while (playerIndex > getListLength(playerList) || playerIndex < 0);
		 }
		
		else {
			return (playerSelected);
		}

	}

	system("cls");
	return (getPlayerFromList(playerList, playerIndex - 1));	//Minus one due to list starting at 0

}

void mainMenu(pPLAYERLIST playerList, pPLAYER player) {	//Displays the main menu 
	do {	
		int menuInput;
	
		printf("Welcome, %s\n", getName(player) );
		printf("Current Balance: %d\n", getBalane(player));
		printf("\t1) Learn to Play\n");
		printf("\t2) Menu and Operation Instructions\n");
		printf("\t3) Profile Options\n");
		printf("\t4) Play Game\n");
		printf("\t5) View Leaderboard\n");
		printf("\t0) Quit\n");

		menuInput = getInput();
		if (menuInput == NULL) {
			return;
		}

		switch (menuInput) {

		case 0:
			//save the profile list
			return;
			break;

		case 1:
			system("cls");
			displayLearnToPlay();

			break;
		case 2:
			system("cls");
			displayInstructions();

			break;
		case 3:
			system("cls");
			profileOptions(playerList, player);

			if (player == NULL) {	//If the player gets deleted then program needs to save and exit.
				return;
			}

			break;
		case 4:
			system("cls");
			card deck[numDeck];
			playRound(player, deck);

			break;
		case 5:
			system("cls");
			displayLeaderboard(playerList);

			break;
		}

	} while (1);
}
	
void profileOptions(pPLAYERLIST playerList, pPLAYER player) {	//Displays the list of things the player can change of their profile
	char name[MAX_NAME_LENGTH];
	int menuInput;

	do {

		printf("Player Options Menu\n");
		printf("\t1) Change name\n");
		printf("\t2) View Stats\n");
		printf("\t3) Reset Balance\n");
		printf("\t0) Exit\n\n");

		menuInput = getInput();


		if (menuInput == NULL) {
			return;
		}

		switch (menuInput)
		{
		case 1:
			printf("\n\nChange name to: ");
			scanf_s("%s", name, MAX_NAME_LENGTH);

			alterName(player, &name);
			break;
		case 2:
			printPlayer(player);
			break;
		case 3:
			refillBalancePrompt(player);
			break;
		case 0:
			return;
			break;
		}

	} while (1);

	system("cls");
}

void printPlayer(pPLAYER player) {

	printf("%s - $%d\n", player->name, player->balance);

}

void printPlayerList(pPLAYERLIST playerList) {	//Cycles through the prints the list with numbering scheme
	int counter = 1;

	pNODE node = playerList->head;

	while (node != NULL) {
		
		printf("%d) %s\n", counter, getName(node->player));

		node = node->nextPlayer;

		counter++;
	}
}

void inputCreatePlayer(pPLAYERLIST playerList) {

	char name[MAX_NAME_LENGTH];

	printf("------Create Player-----\n\n");

	do {
		printf("\tDefault Balance: %d\n", DEFAULT_BALANCE);
		printf("\tEnter Player Name: ");
		scanf_s("%s", name, MAX_NAME_LENGTH);


	} while (strlen(name) == 0);	//While the string length is 0 loop this
	
	if (checkAbort(name)) {
		return;
	}

	pPLAYER player = createPlayer(&name);	
	insertNewPlayer(playerList, player);

	printf("Enter Player Name: ");
}

void displayLeaderboard(pPLAYERLIST playerList) {	

	sortPlayerList(playerList->head);

	printf("Leaderboard\n\n");
	
	int counter = 1;

	pNODE node = playerList->head;

	while (node != NULL) {

		printf("%d) %s\tBalance - $%d\n", counter, getName(node->player), getBalane(node->player));

		node = node->nextPlayer;

		counter++;
	}

	printf("--------------------------------\n");
	
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
	printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");

	
}

void displayInstructions()
{
	printf("                                                     ---Game Instuctions---\n");
	printf("Moving Around Menus: You can move around the interfaces by entering menu options like 1 or 4.\n");
	printf("Exiting: To back out at any time enter in 0000 to return to the menu. To exit the program select the exit menu option.\n");
	printf("Adding Funds: Funds can be added to a players profile. However, this can only be done every 24 hours.\n");

	printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");

}

int refillBalancePrompt(pPLAYER player) {	//Has the user refill their balances 

	int menuOption = 0;

	printf("Balance Notice\nBalance is %d, would you like to reset it to the default?\n", getBalane(player));
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

}

int getInput() {	//Interfaces with the user to get input and checks conditions.
	char userInput[MAX_INPUT];

	do {

		printf("\nEnter Option: ");
		scanf_s("%s",userInput, MAX_INPUT);

		int value = checkInt(&userInput);

		if (value == 0) {// 0  is good, 1 is abort, bad is 2

			break;
		}
		else if (value == 1) {

			printf("Inncorrect input...\n");
		}
		else if (value == 2) {

			return NULL;
		}

	} while (1);

	return atoi(userInput);
}
