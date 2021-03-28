// CSCN71030 - Project II Group 5
// BlackJack
// 
// Game Mechanics Module - Created by Colin Smith csmith6251@conestogac.on.ca
// The purpose of this module is to provide the fundamental functions required to play a round of BlackJack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GameMechanics.h"

// Main to test game mechanics 
int main(void)
{
	int balance = 200000;

	card deck[numDeck];

	playRound(balance, deck);

	return 0;
}

int getInput() 
{
	int option;
	scanf_s("%d", &option);

	return option;
}