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
		printf("Please enter the month you would like to to add/look/change information to (Type 'exit' to exit): \n");
		scanf("%s", Monthchoice); // get the user month choice
		fseek(stdin, 0, SEEK_END);

		strcat(formatWordProperly(Monthchoice), txt); // add '.txt' to the end of the user monthchoice

		menuFunction(Monthchoice, date);
	} while (strcmp(Monthchoice, "Exit.txt") != 0);
}

int setMaxDays(char Monthchoice[])
{
	int maxDays = 0;
	if (strcmp(Monthchoice, "February.txt") == 0)
		maxDays = 28;
	else if ((strcmp(Monthchoice, "April.txt") != 0) || (strcmp(Monthchoice, "June.txt") != 0) || (strcmp(Monthchoice, "Spetember.txt") != 0) || (strcmp(Monthchoice, "November.txt") != 0))
		maxDays = 30;
	else
		maxDays = 31;
	return maxDays;
}

