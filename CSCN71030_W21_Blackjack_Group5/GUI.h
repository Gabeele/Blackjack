#pragma once

#include "TestingModule.h"
#include "inputValidation.h" 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define MAX_NAME_LENGTH 100
#define  LEADERBOARD_COUNT 10
#define MAX_INPUT 10

void printDisclamer();

pPLAYER PlayerSelectMenu(char*, pPLAYERLIST);

void mainMenu(pPLAYERLIST, pPLAYER);

void displayLearnToPlay();

void displayInstructions();

void profileOptions(pPLAYER);

void inputAddFunds(pPLAYER);

void printPlayer(pPLAYER);

void printPlayerList(pPLAYERLIST);

void displayLeaderboard(pPLAYERLIST);

void inputCreatePlayer(pPLAYERLIST);

int getInput();

