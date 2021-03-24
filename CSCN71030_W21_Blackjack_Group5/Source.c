//CSCN71030 - Project II 
//
//Group 5
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int checkInt(char input[]) { //check int from string
	int check = 0;
	int length = strlen(input);
	for (int i = 0; i < length; i++) { //make sure each character is a digit
		if (isdigit(input[i])) {
			check++;
		}
	}
	if (check == length) { //return 0 of it is a valid integer 
		return 0;
	}
	else {
		if (checkAbort(input) == 0) { //return 1 if invalid integer
			return 1;
		}
		else {
			return 2; //return 2 if abort value
		}
	}
}

int checkAbortInt(int input) { //convert int to string to be check if abort value
	char change[10];
	_itoa(input, change, 10);
	return (checkAbort(change));
}

int checkAbort(char input[]) { //check if string is abort value
	if (strcmp(input, "0000") == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

