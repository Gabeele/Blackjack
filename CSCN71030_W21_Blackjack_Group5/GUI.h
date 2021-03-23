#pragma once

#include "TestingModule.h"	//Testing only

#include <stdio.h>
#include <stdlib.h>
#include <dos.h>


void printDisclamer();

pPLAYER PlayerSelectMenu(char*, pPLAYERLIST);

void mainMenu(pPLAYERLIST, pPLAYER);

void displayLearnToPlay();

void displayInstructions();

void inputAddFunds(pPlayer);

void printPlayer(pPLayer);

void leaderboard(pPLAYERLIST);

void displayInstructions();

void playGame();

//play game functions will create more fuctions
