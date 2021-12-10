// Group Assignment - Calendar/ appointment manager
// PROG71985 - F21
// Liam Knapp, Andrew Stanley - Group 8 - Dec 2021

#define _CRT_SECURE_NO_WARNINGS

#include "UpdateAppt.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char updateappointment(P_CALENDAR date, int maxDays) {			//LIAM KNAPP
	int count, input = 0;
	char appt[MAXSIZE];

	printf("\nDays with appointments are:\n");
	for (count = 0; count < maxDays; count++) { //  displays all current days that have no appointment
		if (strcmp(date[count].available, "Unavailable") == 0) {
			printf("%d, %s\n", date[count].day, formatWordProperly(date[count].appointment));
		}
	}


	do
	{
		fseek(stdin, 0, SEEK_END);
		printf("\nWhat day would you like to update an appointment for? type 0 to abort: \n");
	} while ((scanf("%d", &input) != 1) || (input < 0) || (input > maxDays));
	fseek(stdin, 0, SEEK_END);

	if (input == ABORT) {// abort if user pressed 0
		fseek(stdin, 0, SEEK_END);
		return 0;
	}
	else if (strcmp(date[input - LINENUM].available, "Available") == 0)		//return if user has selected a day that does not have an appointment already
	{
		printf("\nThat day does not have a current appointment to update.\n");
		return;
	}

	printf("\nPlease enter the new appointment: \n"); // gather the appointment info
	scanf("%[^\n]s", appt);
	fseek(stdin, 0, SEEK_END);

	formatWordProperly(appt);

	strcpy(date[input - LINENUM].appointment, &appt); // update the appointment
	printf("\nAppointment updated\n");

	return 0;
}