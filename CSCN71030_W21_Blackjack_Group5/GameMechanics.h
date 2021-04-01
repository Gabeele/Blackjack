// CSCN71030-21W-Sec1-Project II: Team Based Software
//
// Colin Smith
//
// Game Mechanics Module
//
// Game Declorations
#pragma once

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
typedef struct 
{
	cardName cardName;
	int cardValue;

} card;

// Function Declorations
void shuffle(card deck[]);
void setupDeck(card deck[]);
void playRound(int balance, card deck[numDeck]); 
int deal(card deck[], int* cardName);
int playerTurn(card deck[], int* playerSum, int* newCard); 
int dealerTurn(card deck[], int* dealerSum, int* newCard);
void determineWinner(int playerSum, int dealerSum, int* balance, int bet);  
void sum(card deck[], int* playerSum, int* dealerSum, int* newCard);
int userBet(int balance);
void displayDeck(card cardName);

int getInput(); // GUI