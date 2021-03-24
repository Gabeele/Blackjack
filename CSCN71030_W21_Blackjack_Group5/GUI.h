#pragma once

#include "TestingModule.h"	//Testing only

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 100
#define  LEADERBOARD_COUNT 10

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

void inputCreatePlayer(pPLAYERLIST)

//play game functions will create more fuctions
