// CSCN71030 - Project II Group 5
// BlackJack
// 
// Game Mechanics Module - Created by Colin Smith csmith6251@conestogac.on.ca
// The purpose of this module is to provide the fundamental functions required to play a round of BlackJack

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
		deck[i].cardName = i % numDeck;

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

void playRound(int balance, card deck[numDeck]) 
{
	setupDeck(deck);
	shuffle(deck);

	int dealerSum = 0;
	int playerSum = 0;
	int bet = 0;
	int newCard = 0;

	bet = userBet(balance);
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
	printf("End of the Round\n");
}

int deal(card deck[], int* cardName)
{
	shuffle(deck);
	displayDeck(deck[*cardName]);
	++* cardName;
	return deck[*cardName - 1].cardValue;
}

int playerTurn(card deck[], int* playerSum, int* newCard) 
{
	do
	{
		printf("It is the Players Turn\n");
		printf("Chose your move: [1] Hit or [2] Stand\n");

		int option = getInput();

		if (option == 0000)
		{
			printf("The game has ended.");
			return 0;
		}

		if (option == 1)
		{
			printf("Card:\n");
			shuffle(deck);
			*playerSum += deal(deck, newCard);
			if (*playerSum <= 21)
			{
				printf("\nPlayer has: %d\n", *playerSum);
			}
		}
		else if (option == 2)
		{
			return 1;
		}
		//else
		//{
			//errorchecking();
		//}

	} 
	while (*playerSum <= 21);

	printf("\nPlayer has whent bust, Player losees.\n");
	return 0;
}

int dealerTurn(card deck[], int* dealerSum, int* newCard)
{
	printf("It is the Dealer's turn\n");

	do
	{
		if (*dealerSum > 16)
		{
			printf("Dealer stands.\n");
			return 1;
		}

		else
		{
			printf("Card:\n");
			shuffle(deck);
			*dealerSum += deal(deck, newCard);
			printf("\nDealer has: %d\n", *dealerSum);
		}
	} 
	while (*dealerSum <= 21);

	printf("Dealer has whent bust, Player wins.\n");

	return 0;
}

void determineWinner(int playerSum, int dealerSum, int* balance, int bet)  
{
	if (playerSum == dealerSum)
	{
		printf("The round is a tie.\n");
	}
	else if (playerSum > dealerSum)
	{
		printf("Player wins.\n");
		*balance += bet;
	}
	else
	{
		printf("Dealer wins.\n");
		*balance -= bet;
	}
	printf("Balance: %d\n", *balance);
}

void sum(card deck[], int* playerSum, int* dealerSum, int* newCard)
{
	int counter;
	printf("Players hand\n");

	for (counter = 0; counter < 2; counter++)
	{
		*playerSum += deal(deck, newCard);
	}
	printf("\nSum of Player's Hand %d\n\n", *playerSum);
	printf("Dealers hand\n");

	for (counter = 0; counter < 2; counter++)
	{
		*dealerSum += deal(deck, newCard);
	}
	printf("\nSum of Dealer's Hand %d\n\n", *dealerSum);
}

int userBet(int balance)
{
	int bet;
	do
	{
		printf("Balance: %d\n", balance);
		printf("Place your bet\n");

	    bet = getInput();

		if (bet == 0000)
		{
			printf("The game has ended.");
			return 0;
		}
		
		else if (bet > balance || bet <= 0)
		{
			printf("Oops! Plase try again\nHint: Your bet has to be greater than zero, and not more than %d (Your balance)\n", balance);
		}
	} 
	while (bet > balance || bet <= 0);

	return bet;
}

void displayDeck(card cardName)
{
	char suit[4][8] = { "Hearts", "Clubs", "Spades", "Diamonds"};

	switch (cardName.cardName)
	{
	case TwoOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case TwoOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case TwoOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;
	case TwoOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;

	case ThreeOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case ThreeOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case ThreeOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;
	case ThreeOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;

	case FourOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case FourOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case FourOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;
	case FourOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;

	case FiveOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case FiveOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case FiveOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;
	case FiveOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;

	case SixOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case SixOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case SixOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;
	case SixOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;

	case SevenOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case SevenOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case SevenOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;
	case SevenOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;

	case EightOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case EightOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case EightOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;
	case EightOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;

	case NineOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case NineOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case NineOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;
	case NineOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;

	case TenOfHearts:
		printf("%d of %s\n", cardName.cardValue, suit[0]);
		break;
	case TenOfDiamonds:
		printf("%d of %s\n", cardName.cardValue, suit[3]);
		break;
	case TenOfSpades:
		printf("%d of %s\n", cardName.cardValue, suit[2]);
		break;
	case TenOfClubs:
		printf("%d of %s\n", cardName.cardValue, suit[1]);
		break;

	case KingOfHearts:
		printf("King of %s\n", suit[0]);
		break;
	case KingOfDiamonds:
		printf("King of %s\n", suit[3]);
		break;
	case KingOfClubs:
		printf("King of %s\n", suit[1]);
		break;
	case KingOfSpades:
		printf("King of %s\n", suit[2]);
		break;

	case QueenOfHearts:
		printf("Queen of %s\n", suit[0]);
		break;
	case QueenOfDiamonds:
		printf("Queen of %s\n", suit[3]);
		break;
	case QueenOfClubs:
		printf("Queen of %s\n", suit[1]);
		break;
	case QueenOfSpades:
		printf("Queen of %s\n", suit[2]);
		break;

	case JackOfHearts:
		printf("Jack of %s\n", suit[0]);
		break;
	case JackOfDiamonds:
		printf("Jack of %s\n", suit[3]);
		break;
	case JackOfClubs:
		printf("Jack of %s\n", suit[1]);
		break;
	case JackOfSpades:
		printf("Jack of %s\n", suit[2]);
		break;

	case AceOfHearts:
		printf("Ace of %s\n", suit[0]);
		break;
	case AceOfDiamonds:
		printf("Ace of %s\n", suit[3]);
		break;
	case AceOfClubs:
		printf("Ace of %s\n", suit[1]);
		break;
	case AceOfSpades:
		printf("Ace of %s\n", suit[2]);
		break;
	}
}