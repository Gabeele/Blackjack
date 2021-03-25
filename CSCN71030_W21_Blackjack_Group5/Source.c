//CSCN71030 - Project II 
//
//Group 5

#define _CRT_SECURE_NO_WARNINGS


#include "GUI.h"

int main() {


	pPLAYER player1 = createPlayer("Gavin");
	pPLAYERNODE node1 = createNode(player1);
	pPLAYERLIST list = createList();



	list->head = node1;

	pPLAYER player = PlayerSelectMenu("", list);
	mainMenu(list, player1);


	return 0;
}


pPLAYER createPlayer(char name[]) {

	pPLAYER player = (pPLAYER)malloc(sizeof(pPLAYER));

	
	strcpy(player->name, name);
	player->balance = 100;

	return player;

}
pPLAYERNODE createNode(pPLAYER player) {

	pPLAYERNODE node = (pPLAYERNODE)malloc(sizeof(pPLAYERNODE));

	node->data = player;

	node->nextNode = NULL;

	return node;


}

pPLAYERLIST createList() {

	pPLAYERLIST list = (pPLAYERLIST)malloc(sizeof(pPLAYERLIST));

	list->head = NULL;

	return list;
}

pPLAYER playerSelectByString(pPLAYERLIST list, char input[]) {

	pPLAYERNODE node;
	node = list->head;

	while (node != NULL) {

		if (strcmp(getName(node->data), input) == 0) {

			return node;
		}
		else {
			node = node->nextNode;
		}

	}

	return NULL;

}

int playerListLength(pPLAYERLIST list) {

	pPLAYERNODE node = list->head;
	int counter = 0;

	while (node != NULL) {

		counter++;

		node = node->nextNode;
	}

	return counter;

}

pPLAYER getPlayerFromList(pPLAYERLIST list, int index) {

	pPLAYERNODE node = list->head;
	int counter = 0;

	while (node != NULL) {

		counter++;

		if (counter == index) {
			return node;
		}

		node = node->nextNode;
	}

	return NULL;

}

int checkInt(int input) {

	return input;
}

int checkAbort(char name[]) {

	return 0;
}

void playRound(pPLAYER player) {

	printf("\n the round is played\n");
}

void changePlayerName(pPLAYER player, char name[]) {

	printf("\nName is changed\n");
}

void deleteProfile(pPLAYER player) {

	printf("\nProfile Deleted\n");
}

void sortList(pPLAYERLIST list) {

	printf("\nList is sorted\n");

}

void resetBalance(pPLAYER player) {

	printf("\nBalance Reset\n");
}

int getBalance(pPLAYER player) {

	return player->balance;
}

char* getName(pPLAYER player) {

	return *player->name;
}
