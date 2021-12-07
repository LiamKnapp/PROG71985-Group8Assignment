#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

int main(void) {
	char Monthchoice[MAXSIZE], txt[MAXSIZE] = ".txt";

	bool continueprogram = true;// loop for the program
	CALENDAR date[MAXSIZE];
	printf("Welcome to your 2021 appointment manager\n\n");

	do
	{
		printf("What month would you like to to add/look/change information to: \n");
		scanf("%s", Monthchoice); // get the user month choice
		fseek(stdin, 0, SEEK_END);

		strcat(makeWordUppercase(Monthchoice), txt); // add '.txt' to the end of the user monthchoice

		menuFunction(Monthchoice, date);
	} while (Monthchoice != 'EXIT');
}

