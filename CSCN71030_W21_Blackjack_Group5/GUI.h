#pragma once

#include "TestingModule.h"	//Testing only

#include <stdio.h>
#include <stdlib.h>


void printDisclamer();

pPLAYER PlayerSelectMenu(char*, pPLAYERLIST);

void mainMenu(pPLAYERLIST, pPLAYER);

void displayLearnToPlay();

void displayInstructions();

void optionsMenu(pPlayer);

void printPlayer(pPLayer);

void leaderboard(pPLAYERLIST);

void instructions();

void playGame();

//play game functions will create more fuctions
