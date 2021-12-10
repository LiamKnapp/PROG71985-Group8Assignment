// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void) {		//WORKED TOGETHER
	char Monthchoice[MAXSIZE], txt[MAXSIZE] = ".txt";

	bool continueprogram = true;// loop for the program
	CALENDAR date[MAXSIZE];
	printf("Welcome to your 2021 appointment manager\n\n");

	do
	{
		printf("Please enter the month you would like to to add/look/change information to (Type 'exit' to exit): \n");
		scanf("%s", Monthchoice); // get the user month choice
		fseek(stdin, 0, SEEK_END);

		strcat(formatWordProperly(Monthchoice), txt); // add '.txt' to the end of the user monthchoice

		menuFunction(Monthchoice, date);
	} while (strcmp(Monthchoice, "Exit.txt") != 0);
}

