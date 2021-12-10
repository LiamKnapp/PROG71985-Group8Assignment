// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#include "extraFunctions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char* formatWordProperly(char word[])	//Formats words or sentences into how they will stored in the file and how they will be displayed		ANDREW STANLEY
{
	int length;
	length = strlen(word);

	word[0] = toupper(word[0]);				//Makes first letter capitalized, the rest lowercase
	for (int i = 1; i < length; i++)
		word[i] = tolower(word[i]);			//This makes search function possible with however the user chose to capilize thier words

	return word;
}

int setMaxDays(char Monthchoice[])		//Sets the max days per month according to what month the user entered		ANDREW STANLEY
{
	int maxDays = 0;			
	if (strcmp(Monthchoice, "February.txt") == 0)
		maxDays = 28;
	else if ((strcmp(Monthchoice, "April.txt") == 0) || (strcmp(Monthchoice, "June.txt") == 0) || (strcmp(Monthchoice, "September.txt") == 0) || (strcmp(Monthchoice, "November.txt") == 0))
		maxDays = 30;
	else
		maxDays = 31;
	return maxDays;
}
