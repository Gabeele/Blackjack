#include "Player.h"

void createProfile(pPLAYERLIST playerList)
{
	playerList->head = NULL;
}
void deleteProfile(pPLAYERLIST playerList, pPLAYER profile)
{

}
void alterName(pPLAYER profile, char* newName);
void sortPlayerList(pPLAYERLIST playerList);
void printPlayerList(pPLAYERLIST playerList);
pPLAYER playerSelectByString(char* name);
void addFund(pPLAYER profile, int additionalFund);