#include "extraFunctions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char* formatWordProperly(char word[])
{
	int length;
	length = strlen(word);

	word[0] = toupper(word[0]);
	for (int i = 1; i < length; i++)
		word[i] = tolower(word[i]);

	return word;
}

int setMaxDays(char Monthchoice[])
{
	int maxDays = 0;
	if (strcmp(Monthchoice, "February.txt") == 0)
		maxDays = 28;
	else if ((strcmp(Monthchoice, "April.txt") == 0) || (strcmp(Monthchoice, "June.txt") == 0) || (strcmp(Monthchoice, "Spetember.txt") == 0) || (strcmp(Monthchoice, "November.txt") == 0))
		maxDays = 30;
	else
		maxDays = 31;
	return maxDays;
}
