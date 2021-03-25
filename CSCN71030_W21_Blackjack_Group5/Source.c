//CSCN71030 - Project II 
//
//Group 5

#define _CRT_SECURE_NO_WARNINGS


#include "GUI.h"

int main() {

	pPLAYERLIST list = createList();
	//pPLAYER player1 = addPlayer(list, "Gavin");
	//pPLAYER player2 = addPlayer(list, "Sarah");
	//pPLAYER player3 = addPlayer(list, "Alex");



	pPLAYER player = PlayerSelectMenu("", list);
	mainMenu(list, player);


	return 0;
}

pPLAYER addPlayer(pPLAYERLIST list, char name[]) {

	pPLAYER player = createPlayer(name);

	pPLAYERNODE node = createNode(player);

	pPLAYERNODE nodeTemp = list->head;

	if (list->head == NULL) {
		list->head = node;	
	}
	else {
		while (nodeTemp != NULL) {

			if (nodeTemp->nextNode == NULL) {

				nodeTemp->nextNode = node;
				break;
			}

			nodeTemp = nodeTemp->nextNode;

		}
	}


	return player;

}


pPLAYER createPlayer( char name[]) {

	pPLAYER player = (pPLAYER)malloc(sizeof(pPLAYER));

	strcpy(player->name, name);
	player->balance = DEFAULT_BALANCE;

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

pPLAYER getPlayer(pPLAYERNODE node) {

	return node->data;
}

int checkInt(int input) {

	return 0;
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

	//free(player);

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
