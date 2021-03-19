#pragma once

#include "TestingModule.h"	//Testing only

#include <stdio.h>
#include <stdlib.h>


void printDisclamer();

pPLAYER PlayerSelectMenu(char*, pPLAYERLIST);

void mainMenu(pPLAYERLIST, pPLAYER);

void optionsMenu(pPlayer);

void instructions();

void playGame();

//play game functions will create more fuctions
