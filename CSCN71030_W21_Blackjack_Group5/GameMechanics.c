// CSCN71030-21W-Sec1-Project II: Team Based Software
//
// Colin Smith
//
// Game Mechanics Module
//
// Game Functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GameMechanics.h"

void shuffle(card deck[])
{
	int randomOrder;
	int cardName;

	card card;

	srand(time(0));
	for (cardName = 0; cardName < numDeck; cardName++)
	{
		card = deck[cardName];
		randomOrder = rand() % (numDeck);

		deck[cardName] = deck[randomOrder];
		deck[randomOrder] = card;
	}
}


void setupDeck(card deck[])
{
	shuffle(deck);

	int cardName = 0;
	int i;

	for (i = 0; i < numDeck; i++)
	{
		deck[i].cardName = i % 52;

		if (deck[i].cardName == AceOfClubs || deck[i].cardName == AceOfSpades || deck[i].cardName == AceOfHearts || deck[i].cardName == AceOfDiamonds)
		{
			deck[i].cardValue = 11;
		}

		else if (deck[i].cardName == KingOfHearts || deck[i].cardName == KingOfDiamonds || deck[i].cardName == KingOfClubs || deck[i].cardName == KingOfSpades ||
			deck[i].cardName == JackOfClubs || deck[i].cardName == JackOfDiamonds || deck[i].cardName == JackOfSpades || deck[i].cardName == JackOfHearts ||
			deck[i].cardName == QueenOfSpades || deck[i].cardName == QueenOfClubs || deck[i].cardName == QueenOfHearts || deck[i].cardName == QueenOfDiamonds)
		{
			deck[i].cardValue = 10;
		}

		else
		{
			deck[i].cardValue = cardName % 9 + 2;
			cardName++;
		}
	}
}

void playRound(int balance, card deck[numDeck]) // ***Add Player from player Module in delcoration***
{
	// ***Call player Module***
	setupDeck(deck);
	shuffle(deck);

	int dealerSum = 0;
	int playerSum = 0;
	int bet = 0;
	int newCard = 0;

	bet = userBet(balance,bet);
	sum(deck, &playerSum, &dealerSum, &newCard);

	if (playerTurn(deck, &playerSum, &newCard))
	{
		if (dealerTurn(deck, &dealerSum, &newCard))
		{

			determineWinner(playerSum, dealerSum, &balance, bet);
		}
		else
		{
			balance += bet;
		}
	}
	else
	{
		balance -= bet;
	}

	// ***Potentially call GUI leaderboard (depending on implementation)
}

int deal(card deck[], int* cardName)
{
	shuffle(deck);
	displayDeck(deck[*cardName]);
	++* cardName;
	return deck[*cardName - 1].cardValue;
}

int playerTurn(card deck[], int* playerSum, int* newCard) // ***Add player from player module in decloration***
{
	int option = 1; // Hardcoded option, 1 = hit, 2 = stand
	do
	{
		// ***Call function to validate input here from Error Checking Module***

		if (option == 1)
		{
			printf("Card:\n");
			shuffle(deck);
			*playerSum += deal(deck, newCard);
			if (*playerSum <= 21)
				printf("\nPlayer has: %d\n", *playerSum);
		}
		else if (option == 2)
		{
			return 1;
		}
	} while (*playerSum <= 21);

	// ***Call file I/O function here to write changes to .txt file***

	return 0;
}

int dealerTurn(card deck[], int* dealerSum, int* newCard)
{
	do
	{
		if (*dealerSum > 16) // Dealer stands
		{
			return 1;
		}

		else
		{
			printf("Card:\n");
			shuffle(deck);
			*dealerSum += deal(deck, newCard);
			printf("\nDealer has: %d\n", *dealerSum);
		}
	} while (*dealerSum <= 21);

	// print "Dealer has busted"

	return 0;
}

void determineWinner(int playerSum, int dealerSum, int* balance, int bet)  // ***Add player from player module in decloration***
{
	if (playerSum == dealerSum)
	{
		// tie
	}
	else if (playerSum > dealerSum)
	{
		// Player wins
		*balance += bet;

		// ***Call file I/O function here to write changes to .txt file***
	}
	else
	{
		// Dealer Wins
		*balance -= bet;

		// ***Call file I/O function here to write changes to .txt file***
	}
}

void sum(card deck[], int* playerSum, int* dealerSum, int* newCard)
{
	int counter;
	//printf("Players hand\n");

	for (counter = 0; counter < 2; counter++)
	{
		*playerSum += deal(deck, newCard);
	}
	//printf("\nSum of Player's Hand %d\n\n", *playerSum);
	//printf("Dealers hand\n");

	for (counter = 0; counter < 2; counter++)
	{
		*dealerSum += deal(deck, newCard);
	}
	//printf("\nSum of Dealer's Hand %d\n\n", *dealerSum);
}

int userBet(int balance, int bet)
{
	do
	{
		if (bet > balance || bet <= 0)
		{
			// Error
		}
	} while (bet > balance || bet <= 0);
	return bet;
}

void displayDeck(card cardName)
{
	switch (cardName.cardName)
	{
	case TwoOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case TwoOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case TwoOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;
	case TwoOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;

	case ThreeOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case ThreeOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case ThreeOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;
	case ThreeOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;

	case FourOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case FourOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case FourOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;
	case FourOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;

	case FiveOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case FiveOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case FiveOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;
	case FiveOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;

	case SixOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case SixOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case SixOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;
	case SixOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;

	case SevenOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case SevenOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case SevenOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;
	case SevenOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;

	case EightOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case EightOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case EightOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;
	case EightOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;

	case NineOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case NineOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case NineOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;
	case NineOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;

	case TenOfHearts:
		printf("%d of Hearts\n", cardName.cardValue);
		break;
	case TenOfDiamonds:
		printf("%d of Diamonds\n", cardName.cardValue);
		break;
	case TenOfSpades:
		printf("%d of Spades\n", cardName.cardValue);
		break;
	case TenOfClubs:
		printf("%d of Clubs\n", cardName.cardValue);
		break;

	case KingOfHearts:
		printf("King of Hearts\n");
		break;
	case KingOfDiamonds:
		printf("King of Diamonds\n");
		break;
	case KingOfClubs:
		printf("King of Clubs\n");
		break;
	case KingOfSpades:
		printf("King of Spades\n");
		break;

	case QueenOfHearts:
		printf("Queen of Hearts\n");
		break;
	case QueenOfDiamonds:
		printf("Queen of Diamonds\n");
		break;
	case QueenOfClubs:
		printf("Queen of Clubs\n");
		break;
	case QueenOfSpades:
		printf("Queen of Spades\n");
		break;

	case JackOfHearts:
		printf("Jack of Hearts\n");
		break;
	case JackOfDiamonds:
		printf("Jack of Diamonds\n");
		break;
	case JackOfClubs:
		printf("Jack of CLubs\n");
		break;
	case JackOfSpades:
		printf("Jack of Spades\n");
		break;

	case AceOfHearts:
		printf("Ace of Hearts\n");
		break;
	case AceOfDiamonds:
		printf("Ace of Hearts\n");
		break;
	case AceOfClubs:
		printf("Ace of Hearts\n");
		break;
	case AceOfSpades:
		printf("Ace of Hearts\n");
		break;
	}
}