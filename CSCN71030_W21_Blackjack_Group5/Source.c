//CSCN71030 - Project II 
//
//Group 5

#include "GUI.h"
//#include "player.h"
//#include "playerNode.h"
//#include "playerList.h"
//#include "dataValidation.h"
//#include "gameMechanics.h"
//#include "fileIO.h"

int main(int argc, char** argv) {

	pPlayerList playerList = initalization();	//Creates, inisitalizes, and reads from the file and returns a playerList

	pPlayer player = selectPlayerMenu(cmdLnPlayer, playerList);	//Selects the player from the list either through the menu or through the command line argument

	while (1) {

		mainMenu(playerList, player);

	}

	//Comment

	return 0;
	}