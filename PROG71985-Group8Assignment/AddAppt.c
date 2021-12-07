#define _CRT_SECURE_NO_WARNINGS

#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Liam Knapp, Andrew Stanley
//PROG71985
//Group Assignment
//Group 8

char addappointment(P_CALENDAR date) { // books an appointment
	int  count, input = 1;
	char appt[MAXSIZE];

	fseek(stdin, 0, SEEK_END);

	for (count = 0; count < MAXDAYSINMONTH; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Available") == 0) {
			printf("\nDays with no appointments are:\n%d", date[count].day);
		}
	}

	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("\nWhat day would you like to add a appointment to? type 0 to abort: \n");
	} while ((scanf("%d", &input) != 1) || (input < 0) || (input > MAXDAYSINMONTH));

	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return;
	}

	printf("\nEnter your first appointment: \n"); // gather the appointment info
	scanf("%[^\n]s", appt);
	fseek(stdin, 0, SEEK_END);

	makeWordUppercase(appt);

	strcpy(date[input - LINENUM].appointment, &appt); // add appointment
	strcpy(date[input - LINENUM].available, "Unavailable"); // make date tag as Unavailable
	printf("\nbook complete\n");

	return 0;
}

char* makeWordUppercase(char word[])
{
	int length;
	length = strlen(word);

	for (int i = 0; i < length; i++)
		word[i] = toupper(word[i]);

	return word;
}