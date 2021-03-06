// CSCN71030 - Project II Group 5
// BlackJack
// 
// Game Mechanics Module - Created by Colin Smith csmith6251@conestogac.on.ca
// The purpose of this module is to provide the fundamental functions required to play a round of BlackJack

// ******************
// Game Declorations
// ******************

#pragma once

#include "player.h"

//Definitions
#define numDeck 52

// Enum for the value of a card in the Deck
typedef enum
{
	TwoOfHearts, 
	TwoOfDiamonds,
	TwoOfSpades,
	TwoOfClubs,

	ThreeOfHearts, 
	ThreeOfDiamonds,
	ThreeOfSpades,
	ThreeOfClubs,

	FourOfHearts, 
	FourOfDiamonds,
	FourOfSpades,
	FourOfClubs,

	FiveOfHearts, 
	FiveOfDiamonds,
	FiveOfSpades,
	FiveOfClubs,

	SixOfHearts, 
	SixOfDiamonds,
	SixOfSpades,
	SixOfClubs,

	SevenOfHearts, 
	SevenOfDiamonds,
	SevenOfSpades,
	SevenOfClubs,

	EightOfHearts, 
	EightOfDiamonds,
	EightOfSpades,
	EightOfClubs,

	NineOfHearts, 
	NineOfDiamonds,
	NineOfSpades,
	NineOfClubs,

	TenOfHearts, 
	TenOfDiamonds,
	TenOfSpades,
	TenOfClubs,

	KingOfHearts,
	KingOfDiamonds,
	KingOfSpades,
	KingOfClubs,

	QueenOfHearts,
	QueenOfDiamonds,
	QueenOfSpades,
	QueenOfClubs,
	
	JackOfHearts, 
	JackOfDiamonds,
	JackOfSpades,
	JackOfClubs,

	AceOfHearts,
	AceOfDiamonds,
	AceOfSpades,
	AceOfClubs

} cardName;

// Structure for a Card
typedef struct CARD
{
	cardName cardName;
	int cardValue;

} card;

// Function Declorations
void shuffle(card deck[]);
void setupDeck(card deck[]);
void playRound(pPLAYER player, card deck[numDeck]); 
int deal(card deck[], int* cardName);
int playerTurn(card deck[], int* playerSum, int* newCard); 
int dealerTurn(card deck[], int* dealerSum, int* newCard);
void determineWinner(int playerSum, int dealerSum, int* balance, int bet);  
void sum(card deck[], int* playerSum, int* dealerSum, int* newCard);
int userBet(int balance);
void displayDeck(card cardName);

int getInput(); // GUI