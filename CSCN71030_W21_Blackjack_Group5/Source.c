// CSCN71030-21W-Sec1-Project II: Team Based Software
//
// Colin Smith
//
// Game Mechanics Module
//
// Sample main()

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GameMechanics.h"

// Main to test game mechanics 

int main(void)
{
	int balance = 10;
	card deck[numDeck];

	playRound(balance, deck);

	return 0;
}