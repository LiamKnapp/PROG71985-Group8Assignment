// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "AddAppt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char addappointment(P_CALENDAR date, int maxDays) { // books an appointment		LIAM KNAPP
	int  count, input = 1;
	char appt[MAXSIZE];

	fseek(stdin, 0, SEEK_END);
	printf("\nDays with no appointments are: \n");
	for (count = 0; count < maxDays; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Available") == 0) {
			printf("%d ", date[count].day);
		}
	}
	printf("\n");

	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("\nWhat day would you like to add a appointment to? type 0 to abort: \n");
	} while ((scanf("%d", &input) != 1) || (input < 0) || (input > maxDays));

	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return;
	}

	printf("\nEnter your first appointment: \n"); // gather the appointment info
	scanf("%[^\n]s", appt);
	fseek(stdin, 0, SEEK_END);

	formatWordProperly(appt);

	strcpy(date[input - LINENUM].appointment, &appt); // add appointment
	strcpy(date[input - LINENUM].available, "Unavailable"); // make date tag as Unavailable
	printf("\nbook complete\n");

	return 0;
}